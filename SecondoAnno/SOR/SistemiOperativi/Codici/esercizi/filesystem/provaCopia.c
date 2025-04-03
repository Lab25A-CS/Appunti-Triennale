#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define OUTPUT_MODE 0700
#define BUF_SIZE 4096

#define TRUE 1

int main(int argc, char *argv[]) {
    int in_fd, out_fd;
    int rd_count, wt_count;
    char buffer[BUF_SIZE];

    if (argc != 3) {
        fprintf(stderr, "hai sbagliato i parametri coglione\n");
        exit(1);
    }

    in_fd = open(argv[1], O_RDONLY);
    if (in_fd < 0) {
        exit(2);
    }

    out_fd = creat(argv[2], OUTPUT_MODE);
    if (out_fd < 0) {
        exit(3);
    }

    while (TRUE) {
        rd_count = read(in_fd, buffer, BUF_SIZE);
        if (rd_count <= 0) {
            break;
        }

        wt_count = write(out_fd, buffer, rd_count);
        if (wt_count < 0) {
            exit(4);
        }
    }

    close(in_fd);
    close(out_fd);
}
