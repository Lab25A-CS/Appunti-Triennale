#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <wait.h>

#define RD_PIPE 0
#define WR_PIPE 1

#define TRUE 1

#define OUTPUT_MODE 0700
#define BUFFER_SIZE 4096

int getFileSize(const char *);

int main(int argc, char *argv[]) {

    pid_t firstHalf_pid, secondHalf_pid;
    int first_pipe[2], second_pipe[2];
    pipe(first_pipe);
    pipe(second_pipe);

    int fd_in, fd_out;
    int rdCounter_first, wrCounter_first;
    int rdCounter_second, wrCounter_second;
    char first_buffer[BUFFER_SIZE];
    char second_buffer[BUFFER_SIZE];

    fd_in = open(argv[1], O_RDONLY);
    fd_out = creat(argv[2], OUTPUT_MODE);
    if (fd_in < 0 || fd_out < 0) {
        fprintf(stderr, "c'è stato un errore in apertura o chiusura del file");
        exit(-1);
    }

    const int halfSize = getFileSize(argv[1]) / 2;

    int i = 0;

    if ((firstHalf_pid = fork()) == 0) {
        close(first_pipe[RD_PIPE]);

        while (i < halfSize) {
            if ((rdCounter_first = read(fd_in, &first_buffer, BUFFER_SIZE) < 0))
                exit(1);

            if ((wrCounter_first = write(first_pipe[WR_PIPE], &first_buffer, sizeof(first_buffer))) < 0) {
                fprintf(stderr, "c'è stato un errore di scrittura");
                exit(2);
            }
            i += sizeof(first_buffer);
        }
    } else if ((secondHalf_pid = fork()) == 0) {
        close(second_pipe[RD_PIPE]);
        if ((lseek(fd_in, halfSize, SEEK_SET)) == 0) {
            fprintf(stderr, "è andata male la seek");
            exit(3);
        }
        while (TRUE) {
            if ((rdCounter_second = read(fd_in, &second_buffer, BUFFER_SIZE)) <= 0) {
                exit(1);
            }
            if ((wrCounter_second = write(second_pipe[WR_PIPE], &second_buffer, sizeof(second_buffer))) < 0) {
                exit(2);
            }
        }
    } else {
        close(first_pipe[WR_PIPE]);
        close(second_pipe[WR_PIPE]);

        waitpid(firstHalf_pid, NULL, 0);
        waitpid(secondHalf_pid, NULL, 0);

        write(fd_out, first_pipe[RD_PIPE], sizeof(first_pipe[RD_PIPE]));
        write(fd_out, first_pipe[RD_PIPE], sizeof(first_pipe[RD_PIPE]));
    }
}

int getFileSize(const char *fileName) {
    struct stat fileInfo;
    if (stat(fileName, &fileInfo) < 0) {
        fprintf(
            stderr,
            "ci sono problemi con il file");
        exit(0);
    }
    return fileInfo.st_size;
}
