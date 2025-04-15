#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dir.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

#define RD_MODE 0
#define WR_MODE 1

#define TRUE 1
#define FALSE 0

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "input error\n");
        exit(5);
    }

    DIR *dirp;
    struct dirent *dirent;

    dirp = opendir(argv[1]);
    int presente = FALSE;
    while ((dirent = readdir(dirp)) != NULL) {
        if (strcmp(argv[2], dirent->d_name) == 0) {
            presente = TRUE;
            break;
        }
    }

    if (presente == TRUE) {
        printf("il file %s è presente all'interno della cartella %s\n", argv[2], argv[2]);
    } else {
        fprintf(stderr, "il file %s non è presente all'interno della cartella %s\n", argv[2], argv[2]);
        exit(1);
    }

    int len_dir = strlen(argv[1]);
    int len_file = strlen(argv[2]);
    char file_input[len_dir + len_file - 1];
    strcpy(file_input, argv[1]);
    file_input[len_dir] = '/';
    strcat(file_input, argv[2]);

    struct stat file_info;
    stat(file_input, &file_info);

    int half_size = file_info.st_size / 2;

    if (file_info.st_mode & S_IRUSR) {
        printf("il file %s può essere letto\n", file_input);
    } else {
        fprintf(stderr, "il file %s non può essere letto\n", file_input);
        exit(2);
    }

    int first_pid, second_pid;
    int first_fd, second_fd;
    int first_pipe[2], second_pipe[2];
    pipe(first_pipe);
    pipe(second_pipe);

    if ((first_pid = fork()) == 0) {
        close(first_pipe[RD_MODE]);
        first_fd = open(file_input, O_RDONLY);

        char first_buffer[half_size];

        if (read(first_fd, &first_buffer, sizeof(char) * half_size) == 0) {
            fprintf(stderr, "la prima lettura non é andata a buon fine\n");
            exit(3);
        } else {
            printf("la prima lettura è andata bene\n");
        }

        if (write(first_pipe[WR_MODE], &first_buffer, sizeof(char) * half_size) == 0) {
            fprintf(stderr, "la prima scrittura è andata male\n");
            exit(4);
        } else {
            printf("la prima scrittura è andata a buon fine\n");
        }

        close(first_fd);
        exit(0);

    } else if ((second_pid = fork()) == 0) {
        close(second_pipe[RD_MODE]);
        second_fd = open(file_input, O_RDONLY);

        char second_buffer[half_size];

        lseek(second_fd, half_size, SEEK_SET);

        if (read(second_fd, &second_buffer, sizeof(char) * half_size) == 0) {
            fprintf(stderr, "la seconda lettura non è andata a buon fine\n");
            exit(3);
        } else {
            printf("la seconda lettura è andata a buon fine\n");
        }

        if (write(second_pipe[WR_MODE], &second_buffer, sizeof(char) * half_size) == 0) {
            fprintf(stderr, "la seconda scrittura non è andata a buon fine\n");
            exit(4);
        } else {
            printf("la seconda scrittura è andata a buon fine\n");
        }

        close(second_fd);
        exit(0);

    } else {

        waitpid(first_pid, NULL, 0);
        waitpid(second_pid, NULL, 0);

        close(first_pipe[WR_MODE]);
        close(second_pipe[WR_MODE]);

        char first_buffer[half_size];

        if (read(first_pipe[RD_MODE], &first_buffer, sizeof(char) * half_size) == 0) {
            fprintf(stderr, "la prima lettura finale non è andata a buon fine\n");
            exit(5);
        } else {
            printf("la prima lettura finale è andata a buon fine\n");
        }

        first_buffer[half_size] = '\0';

        printf("[FIRST_PID] -> %s\n", first_buffer);

        printf("---------------------------\n");

        char second_buffer[half_size];

        if (read(second_pipe[RD_MODE], &second_buffer, sizeof(char) * half_size) == 0) {
            fprintf(stderr, "la seconda lettura finale non è andata a buon fine\n");
            exit(5);
        } else {
            printf("la seconda lettura finale è andata a buon fine\n");
        }

        second_buffer[half_size] = '\0';

        printf("[SECOND_PID] -> %s\n", second_buffer);

        close(first_pipe[RD_MODE]);
        close(second_pipe[WR_MODE]);
    }

    return 0;
}
