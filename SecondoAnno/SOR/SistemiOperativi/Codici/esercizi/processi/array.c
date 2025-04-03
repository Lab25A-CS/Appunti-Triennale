#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define MAX 20

#define RD_MODE 0
#define WR_MODE 1

int generate(void) {
    int n = rand() % 101;
    return n;
}

int main(int argc, char *argv[]) {

    int first_pid, second_pid;
    int first_pipe[2], second_pipe[2];
    pipe(first_pipe);
    pipe(second_pipe);

    if ((first_pid = fork()) == 0) {
        srand(getpid());

        close(first_pipe[RD_MODE]);
        int primo_array[MAX];

        for (int i = 0; i < MAX; i++) {
            primo_array[i] = generate();
            printf("-1(%d, %d)\n", i, primo_array[i]);

            if ((i % 2) == 0) {
                write(first_pipe[WR_MODE], &primo_array[i], sizeof(int));
            }
        }

        exit(0);

    } else if ((second_pid = fork()) == 0) {

        srand(getpid());

        close(second_pipe[RD_MODE]);
        int secondo_array[MAX];

        for (int i = 0; i < MAX; i++) {
            secondo_array[i] = generate();
            printf("--2(%d, %d)\n", i, secondo_array[i]);

            if ((i % 2) == 1) {
                write(second_pipe[WR_MODE], &secondo_array[i], sizeof(int));
            }
        }

        exit(1);
    } else {

        close(first_pipe[WR_MODE]);
        close(second_pipe[WR_MODE]);

        int final_array[MAX];

        for (int i = 0; i < MAX; i++) {

            if ((i % 2) == 0) {
                read(first_pipe[RD_MODE], &final_array[i], sizeof(int));
                printf("---3(%d, %d)\n", i, final_array[i]);
            } else {
                read(second_pipe[RD_MODE], &final_array[i], sizeof(int));
                printf("---3(%d, %d)\n", i, final_array[i]);
            }
        }

        int max, min;
        for (int i = 0; i < MAX; i++) {
            if (final_array[i] > max) {
                max = final_array[i];
            } else if (final_array[i] < min) {
                min = final_array[i];
            }
        }

        waitpid(first_pid, NULL, 0);
        waitpid(second_pid, NULL, 0);

        printf("[MAX] -> %d\n[MIN] -> %d\n", max, min);
    }

    return 0;
}
