#include <stdio.h>

void optimal(int f, int rs[], int r) {
    int fr[f], i, j, k, pos, farthest;
    int faults = 0, hits = 0;

    // Initialize frames to -1 (empty)
    for (i = 0; i < f; i++) 
        fr[i] = -1;

    for (i = 0; i < r; i++) {
        printf("\n%d :", rs[i]);
        int found = 0;

        // Check if page already exists (Page Hit)
        for (j = 0; j < f; j++) {
            if (fr[j] == rs[i]) {
                found = 1;
                hits++;
                break;
            }
        }

        if (!found) { // Page Fault Occurs
            // Find empty frame (if available)
            int empty = -1;
            for (j = 0; j < f; j++) {
                if (fr[j] == -1) {
                    empty = j;
                    break;
                }
            }

            if (empty != -1) {
                // Fill empty frame
                fr[empty] = rs[i];
            } else {
                // **Find page to replace using OPTIMAL strategy**
                farthest = -1;
                pos = -1;
                
                for (j = 0; j < f; j++) {
                    int next_use = 1000;  // Large number (Infinity)

                    // Find when fr[j] appears again in the future
                    for (k = i + 1; k < r; k++) {
                        if (fr[j] == rs[k]) {
                            next_use = k;
                            break;
                        }
                    }

                    // If a page is **never used again**, replace it immediately
                    if (next_use == 1000) {
                        pos = j;
                        break;
                    }

                    // Otherwise, choose the page that is used farthest in the future
                    if (next_use > farthest) {
                        farthest = next_use;
                        pos = j;
                    }
                }

                // Replace the victim page
                fr[pos] = rs[i];
            }

            faults++;
        }

        // Print current frame status
        for (j = 0; j < f; j++) {
            if (fr[j] != -1)
                printf("%d ", fr[j]);
            else
                printf("- ");
        }
        printf(found ? " H" : " F");
    }

    printf("\n\nTotal Page Faults: %d\n", faults);
    printf("Total Page Hits: %d\n", hits);
}

int main() {
    int f, r, i;

    printf("\nEnter number of frames: ");
    scanf("%d", &f);
    printf("\nEnter number of references: ");
    scanf("%d", &r);

    int rs[r];
    printf("\nEnter reference string:\n");
    for (i = 0; i < r; i++) {
        scanf("%d", &rs[i]);
    }

    optimal(f, rs, r);
    return 0;
}
