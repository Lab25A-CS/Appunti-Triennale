#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Per strsignal()
#include <unistd.h>

void alarm_handler(int signal) {
    printf("In signal handler: caught signal %d which is %s!\n", signal,
           strsignal(signal));
    exit(0); // il parametro serve per cambiare il codice con cui esce
}

int main(int argc, char **argv) {
    signal(SIGALRM, alarm_handler); // la funzione signal intercetta il segnale
                                    // e lo interpreta come vuole
    alarm(1);                       // manda semplicemente un segnale

    while (1) {
        printf("I am running!\n");
    }

    return 0;
}
