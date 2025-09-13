#include <stdio.h>

typedef struct {
    int pid, at, bt, ct, tat, wt;
} process;

// Function to sort processes based on arrival time (Stable Sorting)
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
void ganttChart(process p[], int n) {
    printf("\nGantt Chart:\n");

    int time = 0;  // Track current time

    for (int i = 0; i < n; i++) 
    {
        printf("--------");
    }
    
    printf("\n");
    for (int i = 0; i < n; i++) 
    {
        if (time < p[i].at) {  // Print idle state
            printf("| IDLE  ");
        }
        printf("| P%d    ", p[i].pid);
        time = p[i].ct;
        if(i==n-1)
        printf("|");
    }
    printf("\n");
    for (int i = 0; i < n; i++) 
    {
        printf("--------");
    }
    printf("\n");

    // Print timeline
    printf("0");
    time = 0;
    for (int i = 0; i < n; i++) 
    {
        if (i > 0 && p[i].at > p[i - 1].ct) 
            printf("      %d", p[i].at); // Idle time gap
        
        printf("      %d", p[i].ct);
    }
    printf("\n");
}

// Function to implement FCFS scheduling
void fcfs(process p[], int n) {
    sorting(p, n);
    
    int time = 0; // Tracks the current execution time
    for (int i = 0; i < n; i++) 
    {
        if (time < p[i].at) { // If CPU is idle before the process arrives
            time = p[i].at;
        }
        p[i].ct = time + p[i].bt;
        time = p[i].ct; // Update time
    }

    // Calculate Turnaround Time (TAT) and Waiting Time (WT)
    for (int i = 0; i < n; i++) 
    {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    // Print Process Details
    printf("\nThe data is:\n");
    printf("\tProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("\tP%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    ganttChart(p, n);
}

int main() {
    int n, i;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    process p[n];

    // Input Process Details
    printf("\nEnter data:\n");
    for (i = 0; i < n; i++) {
        printf("\nP%d", i + 1);
        p[i].pid = i + 1;
        printf("\nEnter arrival time: ");
        scanf("%d", &p[i].at);
        printf("\nEnter burst time: ");
        scanf("%d", &p[i].bt);
    }

    fcfs(p, n);
    return 0;
}
