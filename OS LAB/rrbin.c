#include <stdio.h>
#define MAX 100

// Queue Structure
typedef struct Queue {
    int a[MAX];
    int front, rear;
} queue;

// Queue Operations
void createQueue(queue* q) {
    q->front = -1;
    q->rear = -1;
}

int ISempty(queue* q) {
    return (q->front == -1);
}

int ISfull(queue* q) {
    return (q->rear == MAX - 1);
}

void enqueue(queue* q, int item) {
    if (ISfull(q)) return;
    
    if (ISempty(q)) 
        q->front = q->rear = 0;
    else 
        q->rear++;
    
    q->a[q->rear] = item;
}

int dequeue(queue* q) {
    if (ISempty(q)) return -1;
    
    int item = q->a[q->front];
    if (q->front == q->rear) 
        q->front = q->rear = -1;
    else 
        q->front++;
    
    return item;
}

// Process Structure
typedef struct {
    int pid, at, bt, ct, tat, wt, remaining_bt;
} process;

// Function to sort processes based on arrival time
void sorting(process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

// Function to print Gantt Chart
void ganttChart(int order[], int ordert[], int count) {
    printf("\nGantt Chart:\n");
    
    for (int i = 0; i < count; i++) 
        printf("--------");
    printf("\n");

    for (int i = 0; i < count; i++) 
        printf("| P%d    ", order[i]);
    printf("|\n");

    for (int i = 0; i < count; i++) 
        printf("--------");
    printf("\n");

    printf("0");
    for (int i = 0; i < count; i++) 
        printf("       %d", ordert[i]);
    printf("\n");
}

// Round Robin Scheduling Function
void roundRobinScheduling(process p[], int n, int ts) {
    sorting(p, n); // Sort by arrival time
    
    queue q;
    createQueue(&q);
    
    int completed = 0, time = 0, i;
    int order[MAX], ordert[MAX], count = 0;
    
    // Copy burst times to remaining burst times
    for (i = 0; i < n; i++) 
        p[i].remaining_bt = p[i].bt;

    enqueue(&q, 0); // Enqueue first process

    while (completed < n) {
        if (ISempty(&q)) {
            // Find the next process to enqueue
            int next_process = -1;
            for (i = 0; i < n; i++) {
                if (p[i].at > time && p[i].remaining_bt > 0) {
                    next_process = i;
                    break;
                }
            }
            if (next_process == -1) break; // No more processes to execute
            time = p[next_process].at;
            enqueue(&q, next_process);
            continue;
        }
        
        int k = dequeue(&q); // Get process from queue
        if (p[k].remaining_bt > ts) {
            time += ts;
            p[k].remaining_bt -= ts;
        } else {
            time += p[k].remaining_bt;
            p[k].remaining_bt = 0;
            p[k].ct = time;
            completed++;
        }
        
        order[count] = p[k].pid; // Store process ID
        ordert[count] = time;       // Store completion time
        count++;
        
        // Enqueue arriving processes
        for (i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].remaining_bt > 0 && i != k) {
                int already_enqueued = 0;
                for (int j = q.front; j <= q.rear; j++) {
                    if (q.a[j] == i) {
                        already_enqueued = 1;
                        break;
                    }
                }
                if (!already_enqueued) 
                    enqueue(&q, i);
            }
        }

        if (p[k].remaining_bt > 0)
            enqueue(&q, k);
    }

    // Calculate TAT and WT
    for (i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    // Print Process Details
    printf("\nProcess Details:\n");
    printf("---------------------------------------------------\n");
    printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
    printf("---------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    printf("---------------------------------------------------\n");

    ganttChart(order, ordert, count);
}

// Main Function
int main() {
    int n, i, ts;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    process p[n];

    // Input Process Details
    printf("\nEnter time slice: ");
    scanf("%d", &ts);
    
    for (i = 0; i < n; i++) {
        printf("\nP%d", i + 1);
        p[i].pid = i + 1;
        printf("\nEnter arrival time: ");
        scanf("%d", &p[i].at);
        printf("\nEnter burst time: ");
        scanf("%d", &p[i].bt);
    }

    roundRobinScheduling(p, n, ts);
    return 0;
}