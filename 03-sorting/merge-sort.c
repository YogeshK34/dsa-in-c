#include <stdio.h>

int main() {
    // Pre-sorted arrays from your textbook example
    int a[] = {11, 2, 9, 13, 57};  // First array (already sorted: 2, 9, 11, 13, 57)
    int b[] = {25, 17, 1, 90, 3};  // Second array (already sorted: 1, 3, 17, 25, 90)

    // Let's use the actual sorted versions for demonstration
    int sorted_a[] = {2, 9, 11, 13, 57};
    int sorted_b[] = {1, 3, 17, 25, 90};

    int c[10];  // Merged array
    int i = 0, j = 0, k = 0;  // Index variables

    printf("Merge sort implementation from textbook:\n\n");

    printf("First sorted array: ");
    for(int x = 0; x < 5; x++) {
        printf("%d ", sorted_a[x]);
    }
    printf("\n");

    printf("Second sorted array: ");
    for(int x = 0; x < 5; x++) {
        printf("%d ", sorted_b[x]);
    }
    printf("\n\n");

    // Main merging loop - compares elements from both arrays
    printf("Merging process:\n");
    while(i < 5 && j < 5) {
        if(sorted_a[i] <= sorted_b[j]) {
            printf("a[%d]=%d <= b[%d]=%d, so c[%d] = %d\n", i, sorted_a[i], j, sorted_b[j], k, sorted_a[i]);
            c[k] = sorted_a[i];
            i++;  // Move to next element in array a
        } else {
            printf("a[%d]=%d > b[%d]=%d, so c[%d] = %d\n", i, sorted_a[i], j, sorted_b[j], k, sorted_b[j]);
            c[k] = sorted_b[j];
            j++;  // Move to next element in array b
        }
        k++;  // Move to next position in merged array
    }

    // Copy remaining elements from array a (if any)
    printf("\nCopying remaining elements from array a:\n");
    while(i < 5) {
        printf("c[%d] = a[%d] = %d\n", k, i, sorted_a[i]);
        c[k] = sorted_a[i];
        i++;
        k++;
    }

    // Copy remaining elements from array b (if any)
    printf("\nCopying remaining elements from array b:\n");
    while(j < 5) {
        printf("c[%d] = b[%d] = %d\n", k, j, sorted_b[j]);
        c[k] = sorted_b[j];
        j++;
        k++;
    }

    // Display final merged array
    printf("\nArray after merging:\n");
    for(i = 0; i < 10; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}
