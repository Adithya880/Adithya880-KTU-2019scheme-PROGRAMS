#include <stdio.h>
#include <stdbool.h>

int p, r;

// Function to calculate available resources
void findAvailable(int all[][r], int inst[], int av[]) {
    int i, j, sum[r];
    for (i = 0; i < r; i++) {
        sum[i] = 0;
    }

    for (i = 0; i < r; i++) {
        for (j = 0; j < p; j++) {
            sum[i] += all[j][i];
        }
    }

    for (i = 0; i < r; i++) {
        av[i] = inst[i] - sum[i];
    }
}

// Function to print the table at each step
void printTable(int all[][r], int max[][r], int need[][r], int av[][r]) {
  
    printf("Process\tAllocation\t\tMax\t\t\tNeed\t\t\tAvailable\n");
    printf("\t");
    for (int i = 0; i < r; i++) printf("R%d ", i + 1);
    printf("\t\t");
    for (int i = 0; i < r; i++) printf("R%d ", i + 1);
    printf("\t\t");
    for (int i = 0; i < r; i++) printf("R%d ", i + 1);
    printf("\t\t");
    for (int i = 0; i < r; i++) printf("R%d ", i + 1);
    printf("\n");

    for (int i = 0; i < p; i++) {
        printf("P%d\t", i + 1);
        for (int j = 0; j < r; j++) printf("%d  ", all[i][j]); // Allocation
        printf("\t\t");
        for (int j = 0; j < r; j++) printf("%d  ", max[i][j]); // Max
        printf("\t\t");
        for (int j = 0; j < r; j++) printf("%d  ", need[i][j]); // Need
        printf("\t\t");
        for (int j = 0; j < r; j++) printf("%d  ", av[i][j]); // Available for each process
        printf("\n");
    }
}

// Function to check if the system is in a safe state
void isSafe(int all[][r], int max[][r], int inst[]) {
    int need[p][r], work[r], avail[p][r];
    bool finish[p]; // To track finished processes
    int i, j;
    
    // Initialize available resources
    findAvailable(all, inst, avail[0]);
    
    // Calculate Need Matrix
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            need[i][j] = max[i][j] - all[i][j];
        }
    }

    // Initialize Work = Available
    for (i = 0; i < r; i++) {
        work[i] = avail[0][i];
    }

    // Mark all processes as unfinished
    for (i = 0; i < p; i++) {
        finish[i] = false;
    }

    int count = 0, safeSeq[p];

    while (count < p) {
        bool found = false;

        for (i = 0; i < p; i++) {
            if (!finish[i]) {
                bool canExecute = true;

                for (j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) {
                        canExecute = false;
                        break;
                    }
                }

                if (canExecute) {
                    for (j = 0; j < r; j++) {
                        work[j] += all[i][j]; // Release resources
                    }

                    safeSeq[count++] = i; // Add to safe sequence
                    finish[i] = true;
                    found = true;

                    // Update Available matrix
                    for (j = 0; j < r; j++) {
                        avail[count][j] = work[j];
                    }

                    
                    
                }
            }
        }

        if (!found) {
            printf("\nSystem is in an unsafe state! Deadlock detected.\n");
            return;
        }
    }
    printTable(all, max, need, avail);
    // Print safe sequence
    printf("\nSystem is in a safe state.\nSafe Sequence: ");
    for (i = 0; i < p; i++) {
        printf("P%d ", safeSeq[i] + 1);
    }
    printf("\n");
}

int main() {
    int i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &p);
    printf("Enter the number of resources: ");
    scanf("%d", &r);

    int inst[r], all[p][r], max[p][r];

    printf("Enter the available resources:\n");
    for (i = 0; i < r; i++) {
        scanf("%d", &inst[i]);
    }

    printf("Enter the allocation of resources:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &all[i][j]);
        }
    }

    printf("Enter the maximum demand of resources:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    isSafe(all, max, inst);

    return 0;
}
