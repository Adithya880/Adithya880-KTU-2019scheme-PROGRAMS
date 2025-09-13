#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int pid,pr, at, bt, ct, tat, wt;
    bool completed;
} process;

// Function to sort processes based on arrival time
void sortByArrival(process p[], int n) {
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
void ganttChart(int execution[], int executionTime[], int total,process p[],int n) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < total; i++) printf("--------");
    printf("\n|");
    if(p[0].at!=0)
    printf("IDLE  |");
    for (int i = 0; i < total; i++) {
        printf(" P%d   |", execution[i]);
    }
    printf("\n");

    for (int i = 0; i < total; i++) printf("--------");
    printf("\n");

    printf("0");
    if(p[0].at!=0)
    printf("     1");
    for (int i = 0; i < total; i++) {
        printf("      %d", executionTime[i]);
    }
    printf("\n");
}

// Function to implement SJF (Non-Preemptive) scheduling
void pr(process p[], int n) {
    sortByArrival(p, n);

    int execution[n], executionTime[n], total = 0;
    int completed = 0, time = 0;

    while (completed < n) {
        int shortest = -1;
        int min_pr = __INT_MAX__;

        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].at <= time && p[i].pr < min_pr) {
                shortest = i;
                min_pr = p[i].pr;
            }
        }

        if (shortest == -1) { 
            time = p[completed].at; // Jump to the next process arrival
            continue;
        }

        p[shortest].ct = time + p[shortest].bt;
        time = p[shortest].ct;
        p[shortest].tat = p[shortest].ct - p[shortest].at;
        p[shortest].wt = p[shortest].tat - p[shortest].bt;
        p[shortest].completed = true;

        execution[total] = p[shortest].pid;
        executionTime[total] = p[shortest].ct;
        total++;
        completed++;
    }
    
    // Print Process Details
    printf("\nProcess Details:\n");
    printf("\tPID\tPriority AT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("\tP%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid,p[i].pr, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    ganttChart(execution, executionTime, total,p,n);
}

int main() {
    int n;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);
    process p[n];

    // Input Process Details
    printf("\nEnter data:\n");
    for (int i = 0; i < n; i++) {
        printf("\nP%d", i + 1);
        p[i].pid = i + 1;
        p[i].completed = false;
        printf("\nEnter priority");
        scanf("%d",&p[i].pr);
        printf("\nEnter arrival time: ");
        scanf("%d", &p[i].at);
        printf("\nEnter burst time: ");
        scanf("%d", &p[i].bt);
        
    }

    pr(p, n);
    return 0;
}
