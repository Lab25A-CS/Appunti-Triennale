#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define STDIN 0
#define STDOUT 1
#define PIPE_RD 0
#define PIPE_WR 1

int generate() {
    return rand() % 101; // il % serve per selezionare il modulo -> ergo prende
                         // solo i numeri da 1 a 100
}

int main() {

    srand(time(NULL));
    pid_t disp_pid, par_pid;

    int fdisp[2], fpar[2]; //  per creare le pipe bisogna creare un array di int
                           //  con due elementi
    int d = 0, p = 0;
    ssize_t buffer; // usato per leggere dalle pipe !! usare ssize_t altrimenti
                    // la read restituisce soolo byte

    pipe(fdisp); // trasformo gli array in pipe
    pipe(fpar);

    if ((disp_pid = fork()) ==
        0) {                   // creo il processo figlio e lo faccio entrare in questo if mantre
                               // il padre salta all'else
        close(fdisp[PIPE_RD]); // chiudo la pipe in lettura perché il figlio
                               // scrive e basta
        close(STDOUT);         // chiudo lo STDOUT perché il figlio scrive direttamente
                               // sulla pipe
        dup(fdisp[PIPE_WR]);   // faccio in modo che lo scriva qui
        while (1) {
            int n = generate();

            if (n % 2 != 0) {
                write(fdisp[PIPE_WR], &n,
                      sizeof(int)); // scrivo sulla pipe il valore salvato in n
            }
        }
    }

    else if ((par_pid = fork()) ==
             0) {             // creo il processo figlio e lo faccio entrare in questo if
                              // mantre il padre salta all'else
        close(fpar[PIPE_RD]); // chiudo la pipe in lettura perché il figlio
                              // scrive e basta
        close(STDOUT);        // chiudo lo STDOUT perché il figlio scrive direttamente
                              // sulla pipe
        dup(fpar[PIPE_WR]);   // faccio in modo che lo scriva qui
        while (1) {
            int f = generate();

            if (f % 2 == 0) {
                write(fpar[PIPE_WR], &f,
                      sizeof(int)); // scrivo sulla pipe il valore salvato in f
            }
        }
    }

    else {
        while (1) {
            dup(fpar[PIPE_RD]); // seleziono la pipe da leggere
            buffer = read(fpar[PIPE_RD], &d,
                          sizeof(p)); // salvo in d il valore letto !! usando il
                                      // buffer salva il valore e non i byte!!

            dup(fdisp[PIPE_RD]);
            buffer = read(fpar[PIPE_RD], &p, sizeof(p));

            int somma = p + d;
            printf("%d + %d = %d\n", p, d, somma);
            if (somma > 190) {
                kill(par_pid, SIGTERM); // avendo finito tutto il padre uccide i
                                        // figli in un ciclo infinito
                kill(disp_pid, SIGTERM);
                break;
            }
        }
        waitpid(par_pid, NULL,
                0); // per sicurezza il padre aspetta che i figli finiscano
        waitpid(disp_pid, NULL, 0);
        return 0;
    }
}
