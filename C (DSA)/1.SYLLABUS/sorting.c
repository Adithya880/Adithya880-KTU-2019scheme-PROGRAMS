#include <stdio.h>
#include <stdlib.h>  // For rand() and srand()
#include <time.h>    // For clock() and measuring time

void insertion_sort(int a[], int n) {
    for (int i = 0; i <= n; i++) {
        int key = a[i];
        int j = i - 1;

        // Move elements that are greater than key to one position ahead
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}


void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {  // Outer loop: 0 to (n-2)
        for (int j = 0; j < n - i - 1; j++) {  // Inner loop: 0 to (n-i-2)
            if (a[j] > a[j + 1]) {
                // Swap adjacent elements if they are in the wrong order
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}




void selection_sort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int small = i;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] < a[small])
                small = j;
        }
        int temp = a[i];
        a[i] = a[small];
        a[small] = temp;
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && a[left] > a[largest])
        largest = left;

    if (right <= n && a[right] > a[largest])
        largest = right;

    if (largest != i) {
        swap(&a[i], &a[largest]);
        maxHeapify(a, n, largest);
    }
}

void buildMaxHeap(int a[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        maxHeapify(a, n, i);
    }
}

void heapSort(int a[], int n) {
    buildMaxHeap(a, n);
    for (int i = n; i > 1; i--) {
        swap(&a[1], &a[i]);
        maxHeapify(a, i - 1, 1);
    }
}

int partition(int a[], int lb, int ub) {
    int pivot = a[lb];
    int down = lb + 1;
    int up = ub;

    while (down <= up) {
        while (down <= up && a[down] <= pivot) {
            down++;
        }
        while (down <= up && a[up] > pivot) {
            up--;
        }
        if (down < up) {
            swap(&a[down], &a[up]);
        }
    }
    swap(&a[lb], &a[up]);
    return up;
}

void quicksort(int a[], int lb, int ub) {
    if (lb < ub) {
        int pi = partition(a, lb, ub);
        quicksort(a, lb, pi - 1);
        quicksort(a, pi + 1, ub);
    }
}

void merge(int a[], int start, int mid, int end) {
    int i = start, j = mid + 1, k = start;
    int temp[100];

    while (i <= mid && j <= end) {
        if (a[i] <= a[j]) {
            temp[k++] = a[i++];
        } else {
            temp[k++] = a[j++];
        }
    }

    while (i <= mid) temp[k++] = a[i++];
    while (j <= end) temp[k++] = a[j++];

    for (i = start; i <= end; i++) {
        a[i] = temp[i];
    }
}

void mergeSort(int a[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(a, start, mid);
        mergeSort(a, mid + 1, end);
        merge(a, start, mid, end);
    }
}

void display(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}

void generate_random_array(int a[], int n) {
    srand(time(0));  // Seed for random number generation
    for (int i = 1; i <= n; i++) {
        a[i] = rand() % 1000;  // Generate random numbers between 0 and 999
    }
}

int main() {
    int c, n;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int a[n + 1];  // 1-based index array

    generate_random_array(a, n);

    do {
        printf("\nEnter choice:\n");
        printf("1. Insertion sort\n2. Selection sort\n3. Bubble sort\n4. Quick sort\n5. Merge sort\n6. Heap sort\n7. Exit\n");
        scanf("%d", &c);

        // Create a copy of the array for each sorting algorithm
        int copy[n + 1];
        for (int i = 1; i <= n; i++) {
            copy[i] = a[i];
        }

        switch (c) {
            case 1:
                start = clock();
                insertion_sort(copy, n);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Time taken for Insertion Sort: %f seconds\n", cpu_time_used);
                display(copy, n);
                break;

            case 2:
                start = clock();
                selection_sort(copy, n);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Time taken for Selection Sort: %f seconds\n", cpu_time_used);
                display(copy, n);
                break;

            case 3:
                start = clock();
                bubble_sort(copy, n);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Time taken for Bubble Sort: %f seconds\n", cpu_time_used);
                display(copy, n);
                break;

            case 4:
                start = clock();
                quicksort(copy, 1, n);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Time taken for Quick Sort: %f seconds\n", cpu_time_used);
                display(copy, n);
                break;

            case 5:
                start = clock();
                mergeSort(copy, 1, n);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Time taken for Merge Sort: %f seconds\n", cpu_time_used);
                display(copy, n);
                break;

            case 6:
                start = clock();
                heapSort(copy, n);
                end = clock();
                cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                printf("Time taken for Heap Sort: %f seconds\n", cpu_time_used);
                display(copy, n);
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Wrong choice!\n");
        }
    } while (c != 7);

    return 0;
}
