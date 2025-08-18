// I'll write the implementation of selection sort
// in selection sort the 0th element is compared with all all other elements
// and if any element is found smaller than 0th elements are replaced

#include <stdio.h>

int main() {
    int arr[] = {25,17,31,13,2};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before Sort:\n");
    for (int i = 0; i < size ; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("After Sort:\n");
    for (int i = 0; i <= 4; i++) {
        printf("%d ", arr[i]);
    }
}