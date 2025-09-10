#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Define the queue structure
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Initialize the queue
void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

// Check if the queue is empty
int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

// Enqueue operation (add to rear)
void enqueue(struct Queue* q, int data) {
    struct Node* newNode = createNode(data);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Dequeue operation (remove from front)
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }
    struct Node* temp = q->front;
    int data = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return data;
}

// Peek at the front element without removing
int peek(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

// Print queue elements
void printQueue(struct Queue* q) {
    struct Node* temp = q->front;
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Example usage
int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printQueue(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    printQueue(&q);

    printf("Front element: %d\n", peek(&q));

    return 0;
}
