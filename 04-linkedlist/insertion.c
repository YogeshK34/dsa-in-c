#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

// adds a node to the linkedlist assuming the list is empty
void addNode(struct node **s, int item) {
    *s = malloc(sizeof(struct node));
    if (*s == NULL) {
        printf("Memory allocation failed!");
    }
    (*s)->data = item;
    (*s)->link = NULL;
}

void addAtBeginning(struct node **s, int item) {
    // create a pointer of type struct node
    struct node *temp;

    // add a new node
    temp = malloc(sizeof(struct node));
    temp->data = item;
    temp->link = *s;
    *s = temp;
}

int main() {
    struct node *head = NULL;

    addNode(&head,100);
    addAtBeginning(&head,200);

    printf("Node created:\n");
    printf("Data: %d, Link: %d", head->data, head->link);
}