/*
Scrivere un programma C che segue le seguenti specifiche.
Il processo eseguito, inizialmente crea un buffer come array di 11 numeri interi, inizializzati a zero. In seguito genera tre thread utilizzando le librerie POSIX secondo le seguenti specifiche:
•  Il primo thread in un ciclo infinito sceglie casualmente una cella del buffer e vi scrive il numero +1, qualsiasi sia il valore presente nella cella.
•  Il secondo thread in un ciclo infinito sceglie casualmente una cella del buffer e vi scrive il numero -1, qualsiasi sia il valore presente nella cella.
•  Il terzo thread in un ciclo infinito controlla se tutte le celle del buffer sono state inizializzate ad un valore diverso da 0. In caso positivo, determina se il numero di celle contenenti un valore pari a +1 è maggiore di quelle con -1 e termina tutti e tre i thread.
•  Mentre un thread ha accesso al buffer, nessun altro thread deve accedervi.
•  Una volta che un thread ha acceduto in lettura o scrittura al buffer, deve attendere un numero di secondi random tra 0 e 3
*/

#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

pthread_mutex_t the_mutex;
pthread_cond_t add_cond, remove_cond, final_cond;
pthread_t adder, remover, final;

int buffer[11] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
int modified = 0;

void print_buffer(int array[]) {
    printf("[");
    for (int i = 0; i < 12; i++) {
        printf("%d, ", buffer[i]);
    }
    printf("]\n");
}

int control(int array[]) {
    int initialize = TRUE;
    for (int i = 0; i <= 11; i++) {
        if (array[i] == 0) {
            initialize = FALSE;
            break;
        }
    }
    return initialize;
}

void *aggiungere(void *ptr) {
    srand(getpid());
    while (TRUE) {
        pthread_mutex_lock(&the_mutex);
        while (modified != 0) {
            pthread_cond_wait(&add_cond, &the_mutex);
        }
        int n = rand() % 12;
        buffer[n] = 1;
        printf("aggiungendo 1 in posizione %d\n", n);
        print_buffer(buffer);
        modified = 1;
        sleep(1);
        pthread_cond_signal(&final_cond);
        pthread_mutex_unlock(&the_mutex);
    }
}

void *togliere(void *ptr) {
    srand(time(NULL));
    while (TRUE) {
        pthread_mutex_lock(&the_mutex);
        while (modified != 0) {
            pthread_cond_wait(&remove_cond, &the_mutex);
        }
        int n = rand() % 12;
        buffer[n] = -1;
        printf("aggiungendo -1 in posizione %d\n", n);
        print_buffer(buffer);
        modified = 1;
        sleep(1);
        pthread_cond_signal(&final_cond);
        pthread_mutex_unlock(&the_mutex);
    }
}

void *finale(void *ptr) {
    while (TRUE) {
        pthread_mutex_lock(&the_mutex);
        while (modified == 0) {
            pthread_cond_wait(&final_cond, &the_mutex);
        }
        if (control(buffer)) {
            printf("il buffer è inizializzato\n");
            int positive;
            int negative;

            for (int i = 0; i <= 11; i++) {
                if (buffer[i] == 1) {
                    positive++;
                } else {
                    negative++;
                }
            }
            printf("%d, %d", positive, negative);
            print_buffer(buffer);
            pthread_kill(adder, SIGINT);
            pthread_kill(remover, SIGINT);
            pthread_mutex_unlock(&the_mutex);
            pthread_exit(0);
        }
        printf("controllando il buffer\n");
        modified = 0;
        pthread_cond_signal(&add_cond);
        pthread_cond_signal(&remove_cond);
        pthread_mutex_unlock(&the_mutex);
    }
}

int main(int argc, char *argv[]) {
    pthread_mutex_init(&the_mutex, NULL);
    pthread_cond_init(&add_cond, NULL);
    pthread_cond_init(&remove_cond, NULL);
    pthread_cond_init(&final_cond, NULL);

    pthread_create(&adder, NULL, aggiungere, NULL);
    pthread_create(&remover, NULL, togliere, NULL);
    pthread_create(&final, NULL, finale, NULL);

    pthread_join(adder, NULL);
    pthread_join(remover, NULL);
    pthread_join(final, NULL);

    pthread_mutex_destroy(&the_mutex);
    pthread_cond_destroy(&add_cond);
    pthread_cond_destroy(&remove_cond);
    pthread_cond_destroy(&final_cond);

    return 0;
}
