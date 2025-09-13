#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5  // Size of the shared buffer
int p,c;
int buffer[BUFFER_SIZE];  // Shared buffer
int in = 0, out = 0;  // Indexes for producer and consumer

sem_t empty;  // Number of empty slots
sem_t full;   // Number of filled slots
pthread_mutex_t mutex;  // Mutex for critical section

void* producer(void* arg) {
    int item;
    for (int i = 0; i < p; i++) {  // Producing 10 items
        item = i + 1;  // Item to be produced

        sem_wait(&empty);  // Wait if buffer is full
        pthread_mutex_lock(&mutex);  // Lock critical section

        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;  // Move index circularly

        pthread_mutex_unlock(&mutex);  // Unlock critical section
        sem_post(&full);  // Signal that an item is available

        sleep(1);  // Simulate time delay
    }
    return NULL;
}

void* consumer(void* arg) {
    int item;
    for (int i = 0; i < c; i++) {  // Consuming 10 items
        sem_wait(&full);  // Wait if buffer is empty
        pthread_mutex_lock(&mutex);  // Lock critical section

        item = buffer[out];
        printf("\tConsumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;  // Move index circularly

        pthread_mutex_unlock(&mutex);  // Unlock critical section
        sem_post(&empty);  // Signal that an empty slot is available

        sleep(2);  // Simulate time delay
    }
    return NULL;
}

int main() {
    printf("\nEnter no: of producers:");
    scanf("%d",&p);
    printf("\nEnter no: of consumers:");
    scanf("%d",&c);
    pthread_t prod, cons;

    sem_init(&empty, 0, BUFFER_SIZE);  // Initialize empty slots
    sem_init(&full, 0, 0);  // Initially, buffer is empty
    pthread_mutex_init(&mutex, NULL);  // Initialize mutex

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
