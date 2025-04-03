#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define RD_MODE 0
#define WR_MODE 1

#define TRUE 1
#define FALSE 0;

int generate_1(void) {
    int n = rand() % 51;
    return n;
}

int generate_2(void) {
    int n = rand() % 51;
    return n + 50;
}

int main(int argc, char *argv[]) {

    srand(time(NULL));

    int first_pid, second_pid;
    int first_pipe[2], second_pipe[2];
    pipe(first_pipe);
    pipe(second_pipe);

    if ((first_pid = fork()) == 0) {

        close(first_pipe[RD_MODE]);

        while (TRUE) {
            int n = generate_1();

            if ((n % 3) == 0) {
                printf("[FIRST_PID] -> %d\n", n);
                write(first_pipe[WR_MODE], &n, sizeof(int));
            }
        }
    } else if ((second_pid = fork()) == 0) {

        close(second_pipe[RD_MODE]);

        while (TRUE) {
            int n = generate_2();

            if ((n % 2) == 0) {
                printf("[SECOND_PID] -> %d\n", n);
                write(second_pipe[WR_MODE], &n, sizeof(int));
            }
        }
    } else {

        int first_number, second_number;
        close(first_pipe[WR_MODE]);
        close(second_pipe[WR_MODE]);

        while (TRUE) {
            read(first_pipe[RD_MODE], &first_number, sizeof(int));
            read(second_pipe[RD_MODE], &second_number, sizeof(int));

            int final_number = first_number + second_number;
            printf("eseguendo la somma fra %d e %d -> %d\n", first_number, second_number, final_number);

            if (final_number >= 130) {
                kill(first_pid, SIGTERM);
                kill(second_pid, SIGTERM);
                break;
            }
        }

        close(first_pipe[RD_MODE]);
        close(second_pipe[RD_MODE]);
    }

    return 0;
}
