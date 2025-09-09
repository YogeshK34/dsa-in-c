#include <stdio.h>
#include <stdlib.h>
#define SIZE 5  // maximum queue size

struct Queue {
    int items[SIZE];
    int front, rear;
};

// Initialize queue
void initQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

// Check if queue is full
int isFull(struct Queue *q) {
    return (q->rear + 1) % SIZE == q->front;
}

// Check if queue is empty
int isEmpty(struct Queue *q) {
    return q->front == -1;
}

// Enqueue (insert element)
void enqueue(struct Queue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % SIZE;
    q->items[q->rear] = value;
    printf("%d enqueued\n", value);
}

// Dequeue (remove element)
int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->items[q->front];
    if (q->front == q->rear) { // only one element
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % SIZE;
    }
    return value;
}

// Peek (front element)
int peek(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->items[q->front];
}

// Display queue
void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->items[i]);
        if (i == q->rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

// Main function
int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    printf("Dequeued: %d\n", dequeue(&q));
    display(&q);

    printf("Front element: %d\n", peek(&q));

    return 0;
}
