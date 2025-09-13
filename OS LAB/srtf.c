#include <stdio.h>
#include <limits.h>

typedef struct {
    int pid, at, bt, rt, ct, tat, wt, start;
} Process;

void sortByArrival(Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

void printGanttChart(int timeline[], int count, int tt[]) {
    printf("\nGantt Chart:\n");
    printf("|");

    for (int i = 0; i < count; i++) {
        if (i == 0 || timeline[i] != timeline[i - 1]) {
            printf(" P%d |", timeline[i]);
        }
    }
    printf("\n");

    printf("%d    ", tt[0]);
    for (int i = 1; i <= count; i++) {  // FIX: Now printing up to count
        if (i == count || timeline[i] != timeline[i - 1]) {
            printf("%d    ", tt[i]);
        }
    }
    printf("\n");
}

void srtf(Process p[], int n) {
    int time = 0, completed = 0, min_rt, min_index;
    int timeline[100], t_count = 0, tt[100];

    while (completed < n) {
        min_rt = INT_MAX;
        min_index = -1;

        for (int i = 0; i < n; i++) {
            if (p[i].at <= time && p[i].rt > 0 && p[i].rt < min_rt) {
                min_rt = p[i].rt;
                min_index = i;
            }
        }

        if (min_index == -1) {
            time++;
            continue;
        }

        if (p[min_index].start == -1) p[min_index].start = time;

        timeline[t_count] = p[min_index].pid;
        tt[t_count] = time;  // Store the correct time when the process starts execution
        t_count++;

        p[min_index].rt--;
        time++;

        if (p[min_index].rt == 0) {
            completed++;
            p[min_index].ct = time;
            p[min_index].tat = p[min_index].ct - p[min_index].at;
            p[min_index].wt = p[min_index].tat - p[min_index].bt;
        }
    }

    tt[t_count] = time;  // FIX: Store final completion time

    printGanttChart(timeline, t_count, tt);

    printf("\nPID  AT  BT  CT  TAT  WT\n");
    for (int i = 0; i < n; i++) {
        printf("%d    %d   %d   %d   %d    %d\n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    Process p[n];
    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("P%d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].start = -1;
    }

    sortByArrival(p, n);
    srtf(p, n);

    return 0;
}
