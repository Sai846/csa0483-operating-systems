#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_PHILOSOPHERS 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2
pthread_mutex_t mutex;
pthread_cond_t condition[NUM_PHILOSOPHERS];
int state[NUM_PHILOSOPHERS];
void test(int phil_id) {
    if (state[phil_id] == HUNGRY &&
        state[(phil_id + 1) % NUM_PHILOSOPHERS] != EATING &&
        state[(phil_id + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS] != EATING) {
        state[phil_id] = EATING;
        printf("Philosopher %d is eating.\n", phil_id);
        pthread_cond_signal(&condition[phil_id]);
    }
}
void grab_forks(int phil_id) {
    pthread_mutex_lock(&mutex);
    state[phil_id] = HUNGRY;
    printf("Philosopher %d is hungry.\n", phil_id);
    test(phil_id);
    pthread_mutex_unlock(&mutex);
    pthread_cond_wait(&condition[phil_id], &mutex);
}
void put_forks(int phil_id) {
    pthread_mutex_lock(&mutex);
    state[phil_id] = THINKING;
    printf("Philosopher %d is thinking.\n", phil_id);
    test((phil_id + 1) % NUM_PHILOSOPHERS);
    test((phil_id + NUM_PHILOSOPHERS - 1) % NUM_PHILOSOPHERS);
    pthread_mutex_unlock(&mutex);
}
void *philosopher(void *arg) {
    int phil_id = *((int *)arg);
    while (1) {
        sleep(rand() % 3 + 1);
        grab_forks(phil_id);
        sleep(rand() % 3 + 1);
        put_forks(phil_id);
    }
}
int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_ids[NUM_PHILOSOPHERS];
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_cond_init(&condition[i], NULL);
    }
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, (void *)&philosopher_ids[i]);
    }
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_join(philosophers[i], NULL);
    }
    pthread_mutex_destroy(&mutex);
    for (int i = 0; i < NUM_PHILOSOPHERS; ++i) {
        pthread_cond_destroy(&condition[i]);
    }
    return 0;
}
