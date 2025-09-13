#include<stdio.h>
#include<stdlib.h>

void fifo(int f, int rs[], int r) {
    int fr[f];
    int i, j, found;
    int k = 0, faults = 0, hits = 0;

    // Initialize frames
    for (i = 0; i < f; i++) {
        fr[i] = -1;
    }

    for (i = 0; i < r; i++) {
        printf("\n%d :", i + 1);
        found = 0;

        // Check for page hit
        for (j = 0; j < f; j++) {
            if (rs[i] == fr[j]) {
                found = 1;
                hits++;
                break;
            }
        }

        // Page fault - replace using FIFO
        if (!found) {
            fr[k] = rs[i];
            k = (k + 1) % f;
            faults++;
        }

        // Print frame status
        for (j = 0; j < f; j++) {
            if (fr[j] != -1)
                printf("%d ", fr[j]);
            else
                printf("- ");
        }
        printf(found ? " H" : " F");
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);
    printf("Total Page Hits: %d\n", hits);
}

void lru(int f, int rs[], int r) {
    int fr[f], count[f];
    int i, j, found;
    int time = 0, faults = 0, hits = 0;

    // Initialize frames and count
    for (i = 0; i < f; i++) {
        fr[i] = -1;
        count[i] = -1;  // Mark as never used
    }

    for (i = 0; i < r; i++) {
        printf("\n%d :", i + 1);
        found = 0;

        // Check for page hit
        for (j = 0; j < f; j++) {
            if (rs[i] == fr[j]) {
                found = 1;
                hits++;
                count[j] = time++;  // Update usage time
                break;
            }
        }

        // Page fault - replace using LRU
        if (!found) {
            int pos = 0;
            for (j = 0; j < f; j++) {
                if (count[j] < count[pos])
                    pos = j;
            }
            fr[pos] = rs[i];
            count[pos] = time++;  // Set the current time
            faults++;
        }

        // Print frame status
        for (j = 0; j < f; j++) {
            if (fr[j] != -1)
                printf("%d ", fr[j]);
            else
                printf("- ");
        }
        printf(found ? " H" : " F");
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);
    printf("Total Page Hits: %d\n", hits);
}

typedef struct fr {
    int value;
    int freq;
} frames;

void lfu(int f, int rs[], int r) {
    frames fr[f];
    int faults = 0, hits = 0;
    
    // Initialize frames
    for (int i = 0; i < f; i++) {
        fr[i].value = -1;
        fr[i].freq = 0;
    }

    printf("\nLFU Page Replacement:\n");
    for (int i = 0; i < r; i++) {
        int found = 0;
        printf("\n%d :", i + 1);

        // Check for page hit
        for (int j = 0; j < f; j++) {
            if (fr[j].value == rs[i]) {
                fr[j].freq++;  // Increase frequency on hit
                hits++;
                found = 1;
                break;
            }
        }

        // If page fault
        if (!found) {
            faults++;
            int replaceIndex = -1;
            int minFreq = 1e9;

            // First, check for an empty slot
            for (int j = 0; j < f; j++) {
                if (fr[j].value == -1) {
                    replaceIndex = j;
                    break;
                }
            }

            // If no empty slot, find LFU page to replace
            if (replaceIndex == -1) {
                for (int j = 0; j < f; j++) {
                    if (fr[j].freq < minFreq) {
                        minFreq = fr[j].freq;
                        replaceIndex = j;
                    }
                }
            }

            // Replace the page and reset frequency
            fr[replaceIndex].value = rs[i];
            fr[replaceIndex].freq=1;
        }

        // Print frame status
        for (int j = 0; j < f; j++) {
            if (fr[j].value != -1)
                printf("%d ", fr[j].value);
            else
                printf("- ");
        }
        printf(found ? " H" : " F");
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);
    printf("Total Page Hits: %d\n", hits);
}


void copy(int rs[], int r, int crs[]) {
    for (int i = 0; i < r; i++)
        crs[i] = rs[i];
}

int main() {
    int f, r, i, c;
    printf("\nEnter no: of frames: ");
    scanf("%d", &f);
    printf("\nEnter no: of references: ");
    scanf("%d", &r);
    int rs[r];
    
    printf("\nEnter reference strings:\n");
    for (i = 0; i < r; i++) {
        printf("%d: ", i + 1);
        scanf("%d", &rs[i]);
    }

    int crs[r];

    do {
        printf("\nEnter your choice:");
        printf("\n1. FIFO\n2. LRU\n3. LFU\n4. Exit\n");
        scanf("%d", &c);

        switch (c) {
            case 1:
                copy(rs, r, crs);
                printf("\nFIFO\n");
                fifo(f, crs, r);
                break;

            case 2:
                copy(rs, r, crs);
                printf("\nLRU\n");
                lru(f, crs, r);
                break;
                
            case 3:
                copy(rs, r, crs);
                printf("\nLFU\n");
                lfu(f, crs, r);
                break;

            case 4:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while (c != 4);

    return 0;
}
