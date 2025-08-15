// here we'll write the code for bubble sort
#include <stdio.h>

int main() {
    // define the array, i,j & temp variable
    int arr[] = {4,5,3,7,2,1,9,8,6}; // You can now add/remove elements freely
    int i,j,temp;

    // Calculate array size dynamically
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array before sorting is:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // we'll have to write down 2 loops
    // the i th loop is for the no of iterations / passes
    // while the j loop actually makes the checks and swaps the elements
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            // here the actual check will happen
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Array after sorting is:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
