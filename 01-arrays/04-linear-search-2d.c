// find a element in a 2d array
#include <stdio.h>
int main() {

    int arr[2][3] = {
    {1,2,6},
    {4,5,6}
    };
    int rows = 2;
    int cols = 3;
    int key = 6;
    // int found = 0;
    int count = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == key) {
                // printf("Element %d found at %d row and %d column", key, i,j);
                // found = 1;
                count++;
            }
        }
    }

    if (count == 0) {
        printf("Key not found\n");
    }else {
        printf("Element %d was found %d time(s):\n",key, count);
    }
}
