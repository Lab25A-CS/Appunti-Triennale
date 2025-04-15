#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STDIN 0
#define STDOUT 1
#define PIPE_RD 0
#define PIPE_WR 1

int main() {

    int pid, child_status;
    pid = fork();

    if (pid == 0) { // se fork è 0 allpra è il figlio
        printf("I am the child and I see the PID %d\n", pid);
    } else {
        wait(&child_status); // viene eseguito dopo l'if, in attesa del figlio
        printf(
            "I am the parent, I see the child's PID (%d) and the status (%d)\n",
            pid, child_status);
    }
}
