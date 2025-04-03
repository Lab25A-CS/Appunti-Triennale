#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define TRUE 1
#define RD_MODE 0
#define WR_MODE 1

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("input error\n");
        exit(0);
    }

    int len = strlen(argv[1]);
    char word_to_find[len];
    strcpy(word_to_find, argv[1]);
    // printf("%s\n", word_to_find);

    char *file_input = argv[2];
    struct stat file_info;
    stat(file_input, &file_info);
    int file_size = file_info.st_size;
    int half_size = file_size / 2;
    // printf("%d", file_size);

    int first_fd, first_pid;
    int second_fd, second_pid;
    int first_pipe[2], second_pipe[2];
    pipe(first_pipe);
    pipe(second_pipe);

    if ((first_pid = fork()) == 0) {
        first_fd = open(file_input, O_RDONLY);
        int n = 0;
        int t = 0;
        char buffer[len];
        close(first_pipe[RD_MODE]);

        while ((n + len) <= half_size) {
            lseek(first_fd, n, SEEK_SET);
            read(first_fd, &buffer, sizeof(char) * len);
            buffer[len] = '\0';
            if (strcmp(word_to_find, buffer) == 0) {
                t++;
            }
            n++;
        }

        write(first_pipe[WR_MODE], &t, sizeof(int));
        close(first_fd);
        exit(1);

    } else if ((second_pid = fork()) == 0) {
        second_fd = open(file_input, O_RDONLY);
        int n = half_size;
        int t = 0;
        char buffer[len];
        close(second_pipe[RD_MODE]);

        while ((n + len) <= file_size) {
            lseek(second_fd, n, SEEK_SET);
            read(second_fd, &buffer, sizeof(char) * len);
            buffer[len] = '\0';
            if (strcmp(buffer, word_to_find) == 0) {
                t++;
            }
            n++;
        }

        write(second_pipe[WR_MODE], &t, sizeof(int));
        close(second_fd);
        exit(2);

    } else {

        waitpid(first_pid, NULL, 0);
        waitpid(second_pid, NULL, 0);

        close(first_pipe[WR_MODE]);
        close(second_pipe[WR_MODE]);
        int first_number, second_number;

        read(first_pipe[RD_MODE], &first_number, sizeof(int));
        read(second_pipe[RD_MODE], &second_number, sizeof(int));

        int final_numebr = first_number + second_number;
        printf("ci sono %d ricorrenze della parola %s all'interno del file %s\n", final_numebr, word_to_find, file_input);
    }
    return 0;
}
