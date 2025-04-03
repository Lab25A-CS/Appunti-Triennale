#include <pthread.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 10
#define THR 3

#define FALSE 0
#define TRUE 1

pthread_mutex_t A_mutex;
pthread_mutex_t B_mutex;

pthread_cond_t C_cond;

int primo_array[MAX];
int secondo_array[MAX];

int initialize(int array[]) {

    int full = TRUE;

    for (int i = 0; i < MAX; i++) {
        if (array[i] == 0) {
            full = FALSE;
        }
    }

    if (full == TRUE) {
        return 1;
    } else {
        return 0;
    }
}

void print_array(int array[]) {
    printf("[");
    for (int i = 0; i < MAX; i++) {
        printf("%d, ", array[i]);
    }
    printf("]\n");
}

void *first(void *ptr) {
    srand(time(NULL));

    int i;

    while (TRUE) {
        pthread_mutex_lock(&A_mutex);
        if (initialize(primo_array) == TRUE) {
            printf("[FIRST] -> ha terminato il compito\n");
            pthread_exit(0);
        }

        i = rand() % (MAX + 1);
        primo_array[i] = rand() % 151;
        printf("[FIRST] -> posizionando il valore %d in posizione %d\n", primo_array[i], i);
        print_array(primo_array);
        sleep(rand() % 2);

        pthread_cond_signal(&C_cond);
        pthread_mutex_unlock(&A_mutex);
    }
}

void *second(void *ptr) {
    printf("thread_init\n");
    srand(getpid());

    int i;

    while (TRUE) {
        pthread_mutex_lock(&B_mutex);
        printf("il second ha il mutex\n");
        if (initialize(secondo_array) == TRUE) {
            printf("[SECOND] -> ha terminato il compito\n");
            pthread_exit(0);
        }

        i = rand() % (MAX + 1);
        secondo_array[i] = (rand() % 151) + 150;
        printf("[SECOND] -> posizionando il valore %d in posizione %d\n", secondo_array[i], i);
        print_array(secondo_array);
        sleep(rand() % 2);

        pthread_cond_signal(&C_cond);
        pthread_mutex_unlock(&B_mutex);
    }
}

void * final(void *ptr) {

    int first_complete = FALSE;
    int second_complete = FALSE;
    int first_max;
    int first_min;
    int second_max;
    int second_min;

    pthread_mutex_lock(&A_mutex);
    pthread_mutex_lock(&B_mutex);

    if (first_complete == FALSE) {
        while ((initialize(primo_array) == FALSE)) {
            pthread_cond_wait(&C_cond, &A_mutex);
        }

        int first_max;
        int first_min;
        for (int i = 0; i < MAX; i++) {
            if (primo_array[i] > first_max) {
                first_max = primo_array[i];
            }
            if (primo_array[i] < first_min) {
                first_min = primo_array[i];
            }
        }

        first_complete = TRUE;
    }

    if (second_complete == FALSE) {

        while (initialize(secondo_array) == FALSE) {
            pthread_cond_wait(&C_cond, &B_mutex);
        }

        for (int j = 0; j < MAX; j++) {
            if (secondo_array[j] > second_max) {
                second_max = secondo_array[j];
            }
            if (secondo_array[j] < second_min) {
                second_min = secondo_array[j];
            }
        }

        second_complete = TRUE;
    }

    if (first_complete && second_complete) {
        print_array(primo_array);
        printf("[FINAL] -> first_max: %d, first_min %d\n", first_max, first_min);

        print_array(secondo_array);
        printf("[FINAL] -> second_max: %d, second_min %d\n", second_max, second_min);

        pthread_exit(0);
    }

    pthread_mutex_unlock(&A_mutex);
    pthread_mutex_unlock(&B_mutex);
}

int main(int argc, char *argv[]) {
    for (int i = 0; i < MAX; i++) {
        primo_array[i] = 0;
        secondo_array[i] = 0;
    }

    pthread_t primo, secondo, finale;

    pthread_mutex_init(&A_mutex, NULL);
    pthread_mutex_init(&B_mutex, NULL);
    pthread_cond_init(&C_cond, NULL);

    pthread_create(&primo, NULL, &first, NULL);
    pthread_create(&secondo, NULL, &second, NULL);
    pthread_create(&finale, NULL, &final, NULL);

    pthread_join(primo, NULL);
    pthread_join(secondo, NULL);
    pthread_join(finale, NULL);

    pthread_mutex_destroy(&A_mutex);
    pthread_mutex_destroy(&B_mutex);
    pthread_cond_destroy(&C_cond);

    return 0;
}
