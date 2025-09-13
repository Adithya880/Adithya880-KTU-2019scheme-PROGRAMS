#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Req {
    int id;
    int urgency; // 0 for regular, 1 for urgent
} Req;

typedef struct Queue {
    Req data[MAX_SIZE];
    int front, rear;
} Queue;

typedef struct PriorityQueue {
    Req data[MAX_SIZE];
    int front, rear;
} PriorityQueue;

void createQueue(Queue* q) {
    q->front = q->rear = -1;
}

void createPriorityQueue(PriorityQueue* pq) {
    pq->front = pq->rear = -1;
}

int isEmpty(Queue* q) {
    return q->front == -1 && q->rear == -1;
}

int isEmptyPQ(PriorityQueue* pq) {
    return pq->front == -1 && pq->rear == -1;
}

int isFull(Queue* q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

int isFullPQ(PriorityQueue* pq) {
    return (pq->rear + 1) % MAX_SIZE == pq->front;
}

void enqueue(Queue* q, Req newReq) {
    if (isFull(q)) {
        printf("Queue overflow\n");
        return;
    }

    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }

    q->data[q->rear] = newReq;
}

void enqueuePQ(PriorityQueue* pq, Req newReq) {
    if (isFullPQ(pq)) {
        printf("Priority queue overflow\n");
        return;
    }

    if (isEmptyPQ(pq)) {
        pq->front = pq->rear = 0;
    } else {
        // Find the insertion position based on urgency
        int i = pq->rear;
        while (i != pq->front - 1 && pq->data[i % MAX_SIZE].urgency && newReq.urgency == 0) {
            i = (i - 1 + MAX_SIZE) % MAX_SIZE;
        }

        // Shift elements to make space for new urgent request
        if (i != pq->rear) {
            int j = (pq->rear + 1) % MAX_SIZE;
            while (j != i) {
                pq->data[j] = pq->data[(j - 1 + MAX_SIZE) % MAX_SIZE];
                j = (j + 1) % MAX_SIZE;
            }
        }

        pq->rear = (pq->rear + 1) % MAX_SIZE;
    }

    pq->data[pq->rear] = newReq;
}

Req dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        Req dummy;
        dummy.id = -1;
        dummy.urgency = -1;
        return dummy;
    }

    Req temp = q->data[q->front];

    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }

    return temp;
}

Req dequeuePQ(PriorityQueue* pq) {
    if (isEmptyPQ(pq)) {
        printf("Priority queue underflow\n");
        Req dummy;
        dummy.id = -1;
        dummy.urgency = -1;
        return dummy;
    }

    Req temp = pq->data[pq->front];

    if (pq->front == pq->rear) {
        pq->front = pq->rear = -1;
    } else {
        pq->front = (pq->front + 1) % MAX_SIZE;
    }

    return temp;
}

int main() {
    Queue regularQueue;
    PriorityQueue urgentQueue;

    createQueue(&regularQueue);
    createPriorityQueue(&urgentQueue);

    int choice, id, urgency;

    while (1) {
        printf("\n1. Add regular request\n2. Add urgent request\n3. Process next request\n4. Switch urgent to regular\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter request ID: ");
                scanf("%d", &id);
                Req regularReq = {id, 0};
                enqueue(&regularQueue, regularReq);
                break;
            case 2:
                printf("Enter request ID and urgency (1 for urgent, 0 for regular): ");
                scanf("%d %d", &id, &urgency);
                Req urgentReq = {id, urgency};
                enqueuePQ(&urgentQueue, urgentReq);
                break;
            case 3:
                if (!isEmptyPQ(&urgentQueue)) {
                    Req urgentReq = dequeuePQ(&urgentQueue);
                    printf("Processing urgent request: ID %d\n", urgentReq.id);
                } else if (!isEmpty(&regularQueue)) {
                    Req regularReq = dequeue(&regularQueue);
                    printf("Processing regular request: ID %d\n", regularReq.id);
                } else {
                    printf("No more requests to process.\n");
                }
                break;
            case 4:
                if (!isEmptyPQ(&urgentQueue)) {
                    Req urgentReq = dequeuePQ(&urgentQueue);
                    urgentReq.urgency = 0;
                    enqueue(&regularQueue, urgentReq);
                    printf("Switched urgent request to regular: ID %d\n", urgentReq.id);
                } else {
                    printf("No urgent requests to switch.\n");
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}