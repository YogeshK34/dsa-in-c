// implementation of binary search

// so binary search works by dividing the sorted array and then checks the element with the mid-element
#include <stdio.h>

int main() {
    // sorted array
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Enter a array to search: ");
    scanf("%d", &arr[i]);
    // define the mid, lower,upper,element_to_search
    int size = sizeof(arr) / sizeof(arr[0]);
    int mid, lower = 0, upper = size - 1, element_to_search; // fixed upper bound to size-1
    
    printf("Enter element to search: ");
    scanf("%d", &element_to_search);
    
    int found = 0;

    // start the for loop
    for (mid = (lower + upper) / 2; lower <= upper; mid = (lower + upper) / 2) {
        // check if the first mid is the key
        if (arr[mid] == element_to_search) {
            printf("Element %d found at index %d\n", element_to_search, mid);
            found = 1; // mark as found
            break;  // no need to search rest of the array
        }

        // check if number is smaller than mid
        if (arr[mid] > element_to_search) {
            upper = mid - 1;
        }
        else {
            lower = mid + 1;
        }
    }
    
    if (!found) {
        printf("Element %d not found in the array\n", element_to_search);
    }
    
    return 0;
}
