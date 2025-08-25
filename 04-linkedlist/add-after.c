#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void addAfter(struct node *p, int loc, int item) {
    struct node *temp, *r;

    temp = p;
    for (int i = 1; i < loc; i++) {
        temp = temp->link;

        if (temp == NULL) {
            printf("End of the list, %d location is not found\n", loc);
            return;
        }
    }
    r = malloc(sizeof(struct node));
    r->data = item;
    r->link = temp->link;
    temp->link = r;
}

void addNode(struct node **s, int item) {
    struct node *newNode = malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = item;
    newNode->link = NULL;
    
    // If list is empty, make new node the head
    if (*s == NULL) {
        *s = newNode;
        return;
    }
    
    // Otherwise, find the last node and link the new node
    struct node *temp = *s;
    while (temp->link != NULL) {
        temp = temp->link;
    }
    temp->link = newNode;
}

void displayList(struct node *p) {
    if (p == NULL) {
        printf("List is empty\n");
        return;
    }
    
    printf("Linked List: ");
    while (p != NULL) {
        printf("%d", p->data);
        if (p->link != NULL) {
            printf(" -> ");
        }
        p = p->link;
    }
    printf(" -> NULL\n");
}

int main() {
    struct node *p = NULL;

    addNode(&p, 10);
    addNode(&p, 20);

    printf("After adding 10 and 20:\n");
    displayList(p);

    addAfter(p, 1, 30);

    printf("After adding 30 at position 1:\n");
    displayList(p);

    return 0;
}
