// this program will count all occurences of the element to be searched

#include <stdio.h>
int linearSearch(int arr[], int n, int key) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            count++;
    }
    printf("Element %d was found %d time(s)\n",key, count);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 5, 9, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    linearSearch(arr, n, key);
}