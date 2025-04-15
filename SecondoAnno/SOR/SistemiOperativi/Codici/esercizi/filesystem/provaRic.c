#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define TRUE 1

int main(int agrc, char *argv[]) {
    int in_fd;
    int rd_count;
    int n = strlen(argv[2]);
    char buffer[n];

    struct stat file_info;
    stat(argv[1], &file_info);
    int file_size = file_info.st_size;

    in_fd = open(argv[1], O_RDONLY);
    if (in_fd < 0) {
        exit(1);
    }
    int i = file_size;
    while (i > n) {
        if (lseek(in_fd, i, SEEK_END) < 0)
            exit(2);

        rd_count = read(in_fd, &buffer, n);

        if (strcmp(buffer, argv[2])) {
            close(in_fd);
            printf("hai trovato la parola %s nel file %s, in posizione %d", argv[2], argv[1], i);
            exit(0);
        }
        if (rd_count <= 0)
            break;
        i--;
    }

    printf("la parola che hai cercato non si trova nel file");
    close(in_fd);
    exit(1);
}
