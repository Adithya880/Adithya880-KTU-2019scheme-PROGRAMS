#include <stdio.h>
#include <stdlib.h>

#define max 6

typedef struct element {
    int value;
    int priority;
} element;

typedef struct queue {
    element elements[max];
    int front, rear;
} queue;

void createQueue(queue* q) {
    q->front = -1;
    q->rear = -1;
}

int ISempty(queue* q) {
    return (q->front == -1);
}

int ISfull(queue* q) {
    return (q->rear == max - 1);
}

void enqueue(queue* q, int value, int priority) {
    if (ISfull(q)) {
        printf("\nQueue is full.\n");
        return;
    }

    element new_element;
    new_element.value = value;
    new_element.priority = priority;

    // If the queue is empty, add the new element at the front
    if (ISempty(q)) {
        q->front = q->rear = 0;
        q->elements[q->rear] = new_element;
    } else {
        // Find the correct position for the new element
        int i = q->rear;
        while (i >= q->front && q->elements[i].priority < new_element.priority) {
            q->elements[i + 1] = q->elements[i]; // Shift elements to the right
            i--;
        }

        // Insert the new element at the correct position
        q->elements[i + 1] = new_element;
        q->rear++; // Increment rear to reflect the new element
    }
}

int dequeue(queue* q) {
    if (ISempty(q)) {
        printf("\nQueue is empty.\n");
        return -1;
    }

    int value = q->elements[q->front].value;

    // If there's only one element in the queue, reset it to empty
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++; // Move front pointer forward
    }

    return value;
}

void display(queue* q) {
    if (ISempty(q)) {
        printf("\nQueue is empty.\n");
        return;
    }

    printf("Queue elements (Value, Priority):\n");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d (Priority %d)\t", q->elements[i].value, q->elements[i].priority);
    }
    printf("\n");
}

int main() {
    queue q;
    createQueue(&q);

    int choice, value, priority;

    do {
        printf("\nEnter choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter value: ");
                scanf("%d", &value);
                printf("\nEnter priority: ");
                scanf("%d", &priority);
                enqueue(&q, value, priority);
                break;

            case 2:
                value = dequeue(&q);
                if (value != -1) {
                    printf("\nDequeued element: %d\n", value);
                }
                break;

            case 3:
                display(&q);
                break;

            case 4:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Wrong choice!\n");
        }
    } while (choice != 4);

    return 0;
}
