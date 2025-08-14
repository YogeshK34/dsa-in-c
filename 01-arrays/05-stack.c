// stack implementation in Array

#include <stdio.h>

// pre-define the array size
#define MAX_SIZE 10

// define the structure of the stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// initialize an empty stack
void stack_init(struct Stack *s) {
    s->top = -1;
    // -1 indicates an empty stack
}

// fn to check if stack is full
int isFull(struct Stack *s) { return s->top == MAX_SIZE - 1; }
int isEmpty(struct Stack *s) { return s->top == -1; }

// fn to push an element to the stack
void push(struct Stack *s, int item) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
    } else {
        s->top++;
        s->items[s->top] = item;
    }
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return -1; // Or handle error appropriately
    } else {
        int poppedItem = s->items[s->top];
        s->top--;
        return poppedItem;
    }
}

// main fn
int main() {
    struct Stack s;
    stack_init(&s);
    push(&s, 10);
    push(&s, 20);
    // push(&s, 30);
    // push(&s, 40);
    // push(&s, 50);
    // push(&s, 60);
    // push(&s, 70);
    // push(&s, 80);
    // push(&s, 90);
    // push(&s, 100);
    // push(&s, 110);
    pop(&s);
    printf("Popped item: %d\n", pop(&s));
}
