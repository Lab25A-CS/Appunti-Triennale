/*Si scriva un programma con tre thread che risolvono il seguente problema: Un buffer di n elementi inizializzato con a -1 viene riempito nel seguente modo:

    Il primo thread aggiunge nelle posizioni pari del buffer un numero casuale da 0 a 100.
    Il secondo thread aggiunge nelle posizioni dispari del buffer un casuale da 100 a 200.
    Il terzo thread somma gli elementi e modifica il buffer nel seguente modo:
    buff[0] = buff[0]; buff[1] = buff[1] + buff[0]; buff[2] = buff[1] + buff[2]. Si proponga una soluzione di mutua esclusione.
*/

#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX 10

pthread_mutex_t the_mutex;
pthread_cond_t cond_par, cond_disp, cond_sum;

int buffer[MAX] = {-1};
int par_call = 0;
int disp_call = 1;
int sum_call = 0;

void *pari(void *ptr) {
    srand(time(NULL));

    for (int i = 0; i < MAX; i += 2) {
        pthread_mutex_lock(&the_mutex);
        while (par_call != 0) {
            pthread_cond_wait(&cond_par, &the_mutex);
        }
        buffer[i] = rand() % 101;
        printf("ponendo il valore %d in posizione pari %d\n", buffer[i], i);
        par_call = 1;
        disp_call = 0;
        sum_call += 1;
        sleep(rand() % 2);
        pthread_cond_signal(&cond_disp);
        pthread_mutex_unlock(&the_mutex);
    }
    pthread_exit(0);
}

void *dispari(void *ptr) {
    srand(time(NULL));

    for (int i = 1; i < MAX; i += 2) {
        pthread_mutex_lock(&the_mutex);
        while (disp_call != 0) {
            pthread_cond_wait(&cond_disp, &the_mutex);
        }
        buffer[i] = (rand() % 101) + 100;
        printf("ponendo il valore %d in posizione dispari %d\n", buffer[i], i);
        sum_call += 1;
        disp_call = 1;
        sleep(rand() % 2);
        pthread_cond_signal(&cond_sum);
        pthread_mutex_unlock(&the_mutex);
    }
    pthread_exit(0);
}

void *somma(void *ptr) {
    for (int i = 0; i < MAX; i++) {
        pthread_mutex_lock(&the_mutex);
        while (sum_call < 1) {
            pthread_cond_wait(&cond_sum, &the_mutex);
        }
        if (i != 0) {
            int n = buffer[i];
            buffer[i] = buffer[i] + buffer[i - 1];
            printf("eseguendo la somma fra %d e %d che viene posta in posizione %d\n", buffer[i - 1], n, i);
        }
        sum_call -= 1;
        par_call = 0;
        sleep(rand() % 2);
        pthread_cond_signal(&cond_par);
        pthread_mutex_unlock(&the_mutex);
    }
    pthread_exit(0);
}

int main(int argc, char *argv[]) {

    pthread_t even, odd, sum;

    pthread_mutex_init(&the_mutex, NULL);
    pthread_cond_init(&cond_par, NULL);
    pthread_cond_init(&cond_disp, NULL);
    pthread_cond_init(&cond_sum, NULL);

    pthread_create(&even, NULL, pari, NULL);
    pthread_create(&odd, NULL, dispari, NULL);
    pthread_create(&sum, NULL, somma, NULL);

    pthread_join(even, NULL);
    pthread_join(odd, NULL);
    pthread_join(sum, NULL);

    pthread_mutex_destroy(&the_mutex);
    pthread_cond_destroy(&cond_par);
    pthread_cond_destroy(&cond_disp);
    pthread_cond_destroy(&cond_sum);

    printf("[");
    for (int i = 0; i < MAX; i++) {
        printf("%d, ", buffer[i]);
    }
    printf("]\n");

    return 0;
}
