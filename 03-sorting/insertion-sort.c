// insertion sort starts comparing not from the 0th element but from the 1st element
// and compares all the elements to the right of it and if found a position then shifts
// all the elements to the right to make room for the correct element ar correct index

#include <stdio.h>

int main() {
    int arr[] = {9,8,7,6,5,4,3,2,1};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i,j,k,temp;

    for (i = 1; i < size; i++) {
        for (j = 0;j < i; j++) {
            // check happens here
            if (arr[j] > arr[i]) {
                temp = arr[j];
                arr[j] = arr[i];

                for (k = i; k > j; k--) {
                    arr[k] = arr[k-1];
                }
                arr[k+1] = temp;
            }
        }
    }
    printf("Sorted array: \n ");
    for (i = 0; i < size; i++) {
        printf("%d\t",arr[i]);
    }
}
