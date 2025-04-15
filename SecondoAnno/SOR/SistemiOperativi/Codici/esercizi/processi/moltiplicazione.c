#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

#define TRUE 1
#define RD_MODE 0
#define WR_MODE 1

int generate(void) {
    int n;
    n = rand() % 101;
    return n;
}

int main(int argc, char *argv[]) {

    srand(time(NULL));

    int first_pipe[2], second_pipe[2];
    pipe(first_pipe);
    pipe(second_pipe);

    int first_pid, second_pid;

    if ((first_pid = fork()) == 0) {

        close(first_pipe[RD_MODE]);
        int n = generate();
        printf("generando %d\n", n);

        write(first_pipe[WR_MODE], &n, sizeof(int));
        exit(0);
    } else {

        close(first_pipe[WR_MODE]);

        waitpid(first_pid, NULL, 0);

        int n;
        read(first_pipe[RD_MODE], &n, sizeof(int));

        int k = rand() % 11;
        int t = n * k;
        printf("moltiplicando %d per %d\n", n, k);

        write(second_pipe[WR_MODE], &t, sizeof(int));

        if ((second_pid = fork()) == 0) {

            close(second_pipe[WR_MODE]);

            int f;
            read(second_pipe[RD_MODE], &f, sizeof(int));
            printf("il numero finale è %d\n", f);

            exit(1);
        }

        waitpid(second_pid, NULL, 0);
    }
    return 0;
}
