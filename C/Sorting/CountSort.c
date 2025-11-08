#include<stdio.h>
#include<stdlib.h>

int findMax(int A[], int n) {
    int max = -1;
    if (n <= 0) return -1;

    max = A[0];
    for (int i = 1; i < n; i++) {
        if (A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

void countSort(int A[], int n) {
    int max, i, j;
    if (n <= 0) return;
    max = findMax(A, n);
    int* c = (int *)malloc((max + 1) * sizeof(int));
    if (c == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    for (i = 0; i <= max; i++) {
        c[i] = 0;
    }
    for (i = 0; i < n; i++) {
        c[A[i]]++;
    }
    i = 0;
    j = 0;
    while (i < max + 1) {
        if (c[i] > 0) {
            A[j++] = i;
            c[i]--;
        } else {
            i++;
        }
    }

    free(c);
}

void printArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {4, 2, 2, 8, 3, 3, 1, 7, 0, 5};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Original array: \n");
    printArray(A, n);

    countSort(A, n);

    printf("Sorted array: \n");
    printArray(A, n);

    return 0;
}