#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 190
#define TRUE 1
#define FALSE 0

#define RD_MODE 0
#define WR_MODE 1

int generate(void) {
    int n = rand() % 101;
    return n;
}

int main(int argc, char *argv[]) {

    int first_pid, first_pipe[2];
    int second_pid, second_pipe[2];

    pipe(first_pipe);
    pipe(second_pipe);

    if ((first_pid = fork()) == 0) {

        close(first_pipe[RD_MODE]);

        while (TRUE) {
            int buffer;
            buffer = generate();
            if ((buffer % 2) == 0) {
                write(first_pipe[WR_MODE], &buffer, sizeof(int));
                printf("[FIRST] -> generando %d\n", buffer);
                sleep(1);
            }
        }
    } else if ((second_pid = fork()) == 0) {

        close(second_pipe[RD_MODE]);

        while (TRUE) {
            int buffer;
            buffer = generate();
            if ((buffer % 2) != 0) {
                write(second_pipe[WR_MODE], &buffer, sizeof(int));
                printf("[SECOND] -> generando %d\n", buffer);
                sleep(1);
            }
        }
    } else {
        close(first_pipe[WR_MODE]);
        close(second_pipe[WR_MODE]);

        int first_number, second_number, final_number;

        while (TRUE) {
            read(first_pipe[RD_MODE], &first_number, sizeof(int));
            read(second_pipe[RD_MODE], &second_number, sizeof(int));

            final_number = first_number + second_number;
            printf("[FINAL] -> eseguendo la somma fra %d e %d, uguale a %d\n", first_number, second_number, final_number);
            sleep(1);

            if (final_number >= MAX) {
                break;
            }
        }

        kill(first_pid, SIGINT);
        kill(second_pid, SIGINT);
        return 0;
    }
}
