#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert at specific position
// position starts from 1 (head = position 1)
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);

    // Insert at beginning
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    // Traverse to the node before the given position
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is invalid (greater than list length+1)
    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    // Insert the new node
    newNode->next = temp->next;
    temp->next = newNode;
}

int main() {
    // Example: Create a linked list with 4 nodes
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    printf("Original list:\n");
    printList(head);

    // Insert node with value 25 at position 3
    insertAtPosition(&head, 25, 3);

    printf("After inserting 25 at position 3:\n");
    printList(head);

    // Insert node with value 5 at position 1 (beginning)
    insertAtPosition(&head, 5, 1);

    printf("After inserting 5 at position 1:\n");
    printList(head);

    // Insert node with value 50 at position 6 (end of list)
    insertAtPosition(&head, 50, 6);

    printf("After inserting 50 at position 6:\n");
    printList(head);

    return 0;
}
