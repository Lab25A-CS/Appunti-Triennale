#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 10

pthread_mutex_t the_mutex;
pthread_cond_t condc, condp;

int buffer = 0;

void *producer(void *ptr) {
    int i;

    for (i = 1; i <= MAX; i++) {
        pthread_mutex_lock(&the_mutex);
        while (buffer != 0) {
            pthread_cond_wait(&condp, &the_mutex);
        }
        buffer = i;
        printf("producing %d\n", i);
        sleep(rand() % 2);
        pthread_cond_signal(&condc);
        pthread_mutex_unlock(&the_mutex);
    }
    pthread_exit(0);
}

void *consumer(void *ptr) {
    int i;
    for (i = 1; i <= MAX; i++) {
        pthread_mutex_lock(&the_mutex);

        while (buffer == 0) {
            pthread_cond_wait(&condc, &the_mutex);
        }

        printf("consumando %d\n", i);
        buffer = 0;
        sleep(rand() % 2);
        pthread_cond_signal(&condp);
        pthread_mutex_unlock(&the_mutex);
    }
    pthread_exit(0);
}

int main(int arcg, char *argv[]) {
    pthread_t con, pro;

    pthread_mutex_init(&the_mutex, NULL);
    pthread_cond_init(&condc, NULL);
    pthread_cond_init(&condp, NULL);

    pthread_create(&pro, NULL, producer, NULL);
    pthread_create(&con, NULL, consumer, NULL);

    pthread_join(pro, NULL);
    pthread_join(con, NULL);

    pthread_mutex_destroy(&the_mutex);
    pthread_cond_destroy(&condp);
    pthread_cond_destroy(&condc);

    return 0;
}
