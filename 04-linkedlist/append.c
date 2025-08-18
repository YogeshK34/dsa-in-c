#include <stdio.h>
#include <stdlib.h>

// struct containing the data & link
struct node {
    int data;
    struct node *link;
};

// function to append a new node at the end
void append(struct node **q, int num) {
    struct node *temp, *r;

    // if list is empty
    if (*q == NULL) {
        temp = malloc(sizeof(struct node)); // allocate memory
        temp->data = num;
        temp->link = NULL;
        *q = temp;  // head points to the new node
    }
    else {
        temp = *q; // start from head

        // traverse to the last node
        while (temp->link != NULL) {
            temp = temp->link;
        }

        // create a new node
        r = malloc(sizeof(struct node));
        r->data = num;
        r->link = NULL;
        temp->link = r;  // link last node to new node
    }
}

// function to print the list
void printList(struct node *q) {
    if (q == NULL) {
        printf("List is empty\n");
        return;
    }
    while (q != NULL) {
        printf("%d -> ", q->data);
        q = q->link;
    }
    printf("NULL\n");
}

int main() {
    struct node *p = NULL; // head pointer

    printf("Initial list:\n");
    printList(p);

    printf("\nAppending 10...\n");
    append(&p, 10);
    printList(p);

    printf("\nAppending 20...\n");
    append(&p, 20);
    printList(p);

    printf("\nAppending 30...\n");
    append(&p, 30);
    printList(p);

    return 0;
}
