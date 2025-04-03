#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 10

#define TRUE 1
#define THS 5

sem_t semaforo;
sem_t database;

int read_counter = 0;

int buffer[MAX] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

void print_buffer(void) {
    printf("[");
    for (int i = 0; i < MAX; i++) {
        printf("%d, ", buffer[i]);
    }
    printf("]\n");
}

void *lettore(void *ptr) {
    srand(getpid());
    int i = 0;

    while (i < MAX) {

        sem_wait(&semaforo);

        read_counter++;

        if (read_counter == 1) {
            sem_wait(&database);
        }

        sem_post(&semaforo);

        int pos_pari;
        do {
            pos_pari = rand() % 11;
        } while ((pos_pari % 2) != 0);

        int pos_dispari;
        do {
            pos_dispari = rand() % 11;
        } while ((pos_dispari % 2) == 0);

        int paro = buffer[pos_dispari];
        int disparo = buffer[pos_pari];

        sem_wait(&semaforo);

        read_counter--;

        if (read_counter == 0) {
            sem_post(&database);
        }

        sem_post(&semaforo);

        int sum = paro + disparo;

        printf("eseguendo la somma fra %d (in posizione %d) e %d (in posizione %d) = %d\n", paro, pos_dispari, disparo, pos_pari, sum);
        sleep(1);
        i++;
    }
    pthread_exit(0);
}

void *scrittori(void *ptr) {
    srand(time(NULL));
    int i = 0;

    while (i < MAX) {
        int pos_pari, pos_dispari;

        do {
            pos_pari = rand() % 11;
        } while ((pos_pari % 2) != 0);

        do {
            pos_dispari = rand() % 11;
        } while ((pos_dispari % 2) == 0);

        int paro, disparo;
        do {
            paro = rand() % 51;
        } while ((paro % 2) != 0);

        do {
            disparo = (rand() % 51) + 50;
        } while ((disparo % 2) == 0);

        sem_wait(&database);

        buffer[pos_pari] = disparo;
        buffer[pos_dispari] = paro;
        printf("aggiungendo %d (in posizione %d) e %d (in posizione %d)\n", paro, pos_dispari, disparo, pos_pari);
        print_buffer();

        sem_post(&database);
        sleep(1);
        i++;
    }

    pthread_exit(0);
}

int main(int argc, char *argv[]) {
    pthread_t reader[4], writer;

    sem_init(&semaforo, 0, 1);
    sem_init(&database, 0, 1);

    pthread_create(&writer, NULL, scrittori, NULL);
    for (int i = 0; i < 5; i++) {
        pthread_create(&reader[i], NULL, lettore, NULL);
    }

    pthread_join(writer, NULL);
    for (int j = 0; j < 5; j++) {
        pthread_join(reader[j], NULL);
    }

    sem_destroy(&semaforo);
    sem_destroy(&database);

    return 0;
}
