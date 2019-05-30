#include <pthread.h>
#include <stdio.h>

void *thread_safe(void *argp);

int main() {
    
    pthread_t id;
    printf("Before in thread.\n");
    pthread_create(&id, NULL, thread_safe, NULL);
    pthread_join(id, NULL);
    printf("After thread.\n");

    return 0;
}

void *thread_safe(void *argp) {
    printf("Hello from the thread!\n");
}
