#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 6;
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > key) { // strictly greater
            printf("First element greater than %d is %d at index %d\n", key, arr[i], i);
            found = 1;
            break; // stop after first match
        }
    }

    if (!found) {
        printf("No element greater than %d found\n", key);
    }

    return 0;
}
