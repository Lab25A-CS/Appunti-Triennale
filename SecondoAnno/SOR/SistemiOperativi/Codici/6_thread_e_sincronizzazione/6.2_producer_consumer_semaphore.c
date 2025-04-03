/*

Esempio dello schema Produttore Consumatore in C usando POSIX

Autore. Danilo Croce

NOTA: per essere eseguito in ambiente LINUX usare gcc -pthread source_file.c -o
binary_output

WARNING: sembra non funzionare su MAC OS X

*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 10 /* numero di posti nel buffer */
#define TRUE 1

/* Dichiarazione dei semafori */
sem_t mutex; // Semaforo per l'accesso esclusivo alla regione critica
sem_t empty; // Semaforo per contare i posti vuoti nel buffer
sem_t full;  // Semaforo per contare i posti pieni nel buffer

int buffer[N]; // Buffer condiviso tra produttore e consumatore
int in = 0;    // Indice dove inserire il prossimo elemento nel buffer

/* Funzioni helper per utilizzare i semafori */
void down(sem_t *sem) { sem_wait(sem); }

void up(sem_t *sem) { sem_post(sem); }

/* Funzione per inserire un elemento nel buffer */
void insert_item() {
    int item = rand() % 100; // Genera un elemento casuale
    printf("\nInserisco %d in posizione %d\n", item, (in + 1));
    buffer[in] = item; // Inserisce l'elemento nel buffer
    in++;              // Incrementa l'indice
}

/* Funzione per rimuovere un elemento dal buffer */
void remove_item() {
    int item = buffer[in - 1];
    printf("\nPrelevo %d da posizione %d\n", item, in);
    in--; // Decrementa l'indice
}

/* Funzione per stampare il contenuto del buffer */
void print_buffer() {
    for (int i = 0; i < in; i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");
}

/* Funzione eseguita dal thread del produttore */
void *producer(void *arg) {
    while (TRUE) {
        down(&empty); // Attende finché ci sono posti vuoti nel buffer
        down(&mutex); // Entra nella regione critica

        insert_item();  // Inserisce un elemento nel buffer
        print_buffer(); // Stampa il contenuto del buffer

        up(&mutex); // Esce dalla regione critica
        up(&full);  // Segnala che c'è un posto pieno in più nel buffer
    }
}

/* Funzione eseguita dal thread del consumatore */
void *consumer(void *arg) {
    while (TRUE) {
        down(&full);  // Attende finché ci sono posti pieni nel buffer
        down(&mutex); // Entra nella regione critica

        remove_item();  // Rimuove un elemento dal buffer
        print_buffer(); // Stampa il contenuto del buffer

        up(&mutex); // Esce dalla regione critica
        up(&empty); // Segnala che c'è un posto vuoto in più nel buffer
        // MAI mettere qualcosa dopo l'uscita da una zona critica perché può
        // venire modificato il tutto
    }
}

int main() {
    pthread_t prod, cons; // Dichiarazione dei thread

    // Inizializzazione dei semafori
    sem_init(&mutex, 0, 1); // se il semaforo è zero allora
    sem_init(&empty, 0, N); // non è condiviso fra i processi
    sem_init(&full, 0, 0);

    // Creazione dei thread
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // Attesa della terminazione dei thread
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Distruzione dei semafori
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
