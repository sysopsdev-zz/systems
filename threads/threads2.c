#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_safe(void *args);

int main() {
    int i, j; 
    int NUM_THREADS = 10;

    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];

    printf("Before in thread\n");

    for(i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i; 
        pthread_create(&threads[i], NULL, thread_safe, (void *) &thread_args[i]);
    }

    for(j = 0; j < NUM_THREADS; j++) {
        pthread_join(threads[j], NULL);
    }

    printf("After thread.\n");
    pthread_exit(NULL);

    return 0;
}

void *thread_safe(void *args) {
    int *thread_id = (int *) args;
    printf("Hello from thread: %d\n", *thread_id);
}
