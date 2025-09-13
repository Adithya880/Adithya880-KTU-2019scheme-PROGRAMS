#include<stdio.h>
#include<stdlib.h>

typedef struct Queue {
    int data;
    struct Queue* next;
} queue;

queue* getnode(int data) {
    queue* new = (queue*)malloc(sizeof(queue));
    if (new == NULL) {
        printf("\nMemory allocation failed");
        return NULL;
    } else {
        new->data = data;
        new->next = NULL;
        return new;
    }
}

// Function to enqueue (insert at the rear)
queue* enqueue(queue* rear, int data) {
    queue* new = getnode(data);
    if (rear == NULL) {
        // If the queue is empty, the new node is both the front and rear
        return new;
    } else {
        rear->next = new;
        return new;  // New rear
    }
}

// Function to dequeue (remove from the front)
int dequeue(queue** front) {
    if (*front == NULL) {
        printf("\nQueue empty");
        return -1;
    }
    queue* temp = *front;
    int data = temp->data;
    *front = temp->next;
    free(temp);
    return data;
}

// Function to display the queue
void display(queue* front) {
    if (front == NULL) {
        printf("\nQueue empty");
        return;
    }
    queue* temp = front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main() {
    int c, data;
    queue* front = NULL;
    queue* rear = NULL;

    do {
        printf("\nEnter choice:\n");
        printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &c);

        switch(c) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                if (front == NULL) {
                    // If the queue is empty, both front and rear will point to the new node
                    front = rear = enqueue(rear, data);
                } else {
                    // Otherwise, just enqueue at the rear
                    rear = enqueue(rear, data);
                }
                break;

            case 2:
                data = dequeue(&front);
                if (data != -1) {
                    printf("\nDequeued element: %d", data);
                }
                break;

            case 3:
                display(front);
                break;

            case 4:
                printf("Exiting..");
                exit(0);

            default:
                printf("Wrong choice!\n");
        }
    } while (c != 4);
}
