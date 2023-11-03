#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
void *printHello(void *arg) {
    printf("Hello from Thread 1!\n");
    pthread_exit(NULL); 
}
void *printWorld(void *arg) {
    printf("World from Thread 2!\n");
    pthread_exit(NULL); 
}
int main() {
    pthread_t thread1, thread2; 
    if (pthread_create(&thread1, NULL, printHello, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }
    if (pthread_create(&thread2, NULL, printWorld, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Both threads have completed their tasks.\n");
    return 0;
}
