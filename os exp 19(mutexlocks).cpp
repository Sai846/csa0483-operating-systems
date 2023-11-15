#include <stdio.h>
#include <pthread.h>
#define NUM_THREADS 2
#define NUM_INCREMENTS 10000
int sharedVariable = 0;
pthread_mutex_t mutex;
void *incrementFunction(void *threadID) {
    int tid = *((int *)threadID);
    for (int i = 0; i < NUM_INCREMENTS; ++i) {
        pthread_mutex_lock(&mutex); 
        sharedVariable++;
        pthread_mutex_unlock(&mutex); 
    }
    printf("Thread %d finished.\n", tid);
    pthread_exit(NULL);
}
int main() {
    pthread_t threads[NUM_THREADS];
    int threadIDs[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < NUM_THREADS; ++i) {
        threadIDs[i] = i;
        pthread_create(&threads[i], NULL, incrementFunction, (void *)&threadIDs[i]);
    }
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }
    printf("Final value of the shared variable: %d\n", sharedVariable);
    pthread_mutex_destroy(&mutex);
    return 0;
}

