#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define NUM_READERS 5
#define NUM_WRITERS 2
pthread_t readers[NUM_READERS];
pthread_t writers[NUM_WRITERS];
int shared_data = 0;
sem_t mutex, write_mutex;
int readers_count = 0;
void *reader(void *arg) {
    int reader_id = *(int *)arg;
    sem_wait(&mutex);
    readers_count++;
    if (readers_count == 1) {
        sem_wait(&write_mutex);
    }
    sem_post(&mutex);
    printf("Reader %d is reading: %d\n", reader_id, shared_data);
    sem_wait(&mutex);
    readers_count--;
    if (readers_count == 0) {
        sem_post(&write_mutex);
    }
    sem_post(&mutex);
    pthread_exit(NULL);
}
void *writer(void *arg) {
    int writer_id = *(int *)arg;
    sem_wait(&write_mutex);
    shared_data++;
    printf("Writer %d is writing: %d\n", writer_id, shared_data);
    sem_post(&write_mutex);
    pthread_exit(NULL);
}
int main() {
    sem_init(&mutex, 0, 1);
    sem_init(&write_mutex, 0, 1);
    int i;
    int reader_ids[NUM_READERS];
    int writer_ids[NUM_WRITERS];
    for (i = 0; i < NUM_READERS; i++) {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader, (void *)&reader_ids[i]);
    }
    for (i = 0; i < NUM_WRITERS; i++) {
        writer_ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer, (void *)&writer_ids[i]);
    }
    for (i = 0; i < NUM_READERS; i++) {
        pthread_join(readers[i], NULL);
    }
    for (i = 0; i < NUM_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }
    sem_destroy(&mutex);
    sem_destroy(&write_mutex);
    return 0;
}

