#include <stdio.h>
#define MAX_SIZE 5 // Fixed size for the static queue

int circular_queue[MAX_SIZE];
int front = -1;
int rear = -1;

// Function to check if the queue is full
int isFull() {
    if ((rear + 1) % MAX_SIZE == front) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty() {
    if (front == -1) {
        return 1;
    }
    return 0;
}

// Function to add an element to the circular queue
void enqueue(int element) {
    if (isFull()) {
        printf("\nQueue is full! Cannot enqueue %d.\n", element);
    } else {
        if (front == -1) {
            front = 0; // Initialize front for the first element
        }
        rear = (rear + 1) % MAX_SIZE;
        circular_queue[rear] = element;
        printf("\nEnqueued: %d\n", element);
    }
}

// Function to remove an element from the circular queue
int dequeue() {
    int element;
    if (isEmpty()) {
        printf("\nQueue is empty! Cannot dequeue.\n");
        return -1; // Return a sentinel value
    } else {
        element = circular_queue[front];
        if (front == rear) {
            front = -1;
            rear = -1; // Reset queue if it becomes empty
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("\nDequeued: %d\n", element);
        return element;
    }
}

// Function to display the elements in the circular queue
void display() {
    int i;
    if (isEmpty()) {
        printf("\nQueue is empty!\n");
    } else {
        printf("\nCircular Queue: ");
        for (i = front; i != rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", circular_queue[i]);
        }
        printf("%d\n", circular_queue[i]); // Print the last element
    }
}

// Main function to demonstrate the circular queue
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();

    dequeue();
    display();

    enqueue(4);
    enqueue(5);
    enqueue(6); // This will cause a queue full message
    display();

    dequeue();
    dequeue();
    dequeue();
    display(); // Should show the last remaining element

    dequeue(); // Queue is now empty
    display();

    return 0;
}
