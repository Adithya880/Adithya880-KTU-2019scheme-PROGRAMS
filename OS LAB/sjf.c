#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int pid, at, bt, ct, tat, wt;
    bool completed;
} process;

// Function to sort processes based on arrival time
void sortByArrival(process p[], int n) 
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (p[j].at > p[j + 1].at) 
            {
                process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

// Function to print Gantt Chart
void ganttChart(int execution[], int executionTime[], int completed,process p[],int n) {
    printf("\nGantt Chart:\n");
    for (int i = 0; i < completed; i++) printf("--------");
    printf("\n|");
    if(p[0].at!=0)
    printf("IDLE  |");
    for (int i = 0; i < completed; i++) {
        printf(" P%d   |", execution[i]);
    }
    printf("\n");

    for (int i = 0; i < completed; i++) printf("--------");
    printf("\n");

    printf("0");
    if(p[0].at!=0)
    printf("     1");
    for (int i = 0; i < completed; i++) {
        printf("      %d", executionTime[i]);
    }
    printf("\n");
}

// Function to implement SJF (Non-Preemptive) scheduling
void sjf(process p[], int n) {
    sortByArrival(p, n);

    int execution[n], executionTime[n];
    int completed = 0, time = 0;

    while (completed < n) {
        int shortest = -1;
        int min_bt = __INT_MAX__;

        for (int i = 0; i < n; i++) {
            if (!p[i].completed && p[i].at <= time && p[i].bt < min_bt) {
                shortest = i;
                min_bt = p[i].bt;
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

        execution[completed] = p[shortest].pid;
        executionTime[completed] = p[shortest].ct;
        completed++;

}
    // Print Process Details
    printf("\nProcess Details:\n");
    printf("\tPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("\tP%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }

    ganttChart(execution, executionTime, completed,p,n);
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
        printf("\nEnter arrival time: ");
        scanf("%d", &p[i].at);
        printf("\nEnter burst time: ");
        scanf("%d", &p[i].bt);
    }

    sjf(p, n);
    return 0;
}

/*
#include<stdio.h>
#include<stdbool.h>
typedef struct process{
    int pid,at,bt,ct,wt,tat;
    bool completed;
}process;

void sorting(process p[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(p[j].at>p[j+1].at)
            {
                process c=p[j];
                p[j]=p[j+1];
                p[j+1]=c;
            }
        }
    }
}

void ganttChart(process p[],int n)
{
    int i,time=0;
    for( i=0;i<n;i++) printf("------");
    printf("\n");
    for(i=0;i<n;i++)
    {
        if(time<p[i].at)
        printf("|IDLE ");
        printf("|P%d  ",p[i].pid);
        time=p[i].ct;
    }
    printf("\n");
    for( i=0;i<n;i++) printf("------");
    printf("\n");
    printf("0");
    for( i=0;i<n;i++) {
        
        if (i > 0 && p[i].at > p[i - 1].ct) 
            printf("      %d", p[i].at);
        printf("    %d",p[i].ct);
    }
    
}

void sjf(process p[],int n){
    sorting(p,n);
    int i,time=0,execution[n],executiont[n],total=0,completed=0;
    
    while(completed<n)
    {
        int s=-1;
        int mbt=99999;
        
        for(i=0;i<n;i++)
        {
            if(!p[i].completed && p[i].at <= )
        }
    }
    
    printf("\nP   AT    BT    CT    TAT    WT\n");
    for(i=0;i<n;i++)
    printf("P%d    %d    %d    %d    %d    %d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    ganttChart(p,n);
}

void main()
{
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
        p[i].completed=false;
    }

    sjf(p, n);
    
}
    */