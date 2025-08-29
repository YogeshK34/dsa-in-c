#include <stdio.h>
#include <stdlib.h>

// Define structure for node
struct Node {
    int data;
    struct Node* next;
};

// Function to delete node at given position
void deleteAtPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    // If head needs to be removed
    if (position == 1) {
        *head = temp->next;
        free(temp); // Free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->next;
    }

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of range.\n");
        return;
    }

    // Node temp->next is the node to delete
    struct Node* next = temp->next->next;

    free(temp->next);  // Free memory

    temp->next = next; // Unlink the deleted node
}

// Utility function to print list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Utility function to create new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

int main() {
    // Creating a linked list with 4 nodes
    struct Node* head = newNode(90);
    head->next = newNode(10);
    head->next->next = newNode(20);
    head->next->next->next = newNode(30);

    printf("Original list:\n");
    printList(head);

    int pos = 3;
    printf("Deleting node at position %d\n", pos);
    deleteAtPosition(&head, pos);

    printf("Updated list:\n");
    printList(head);

    return 0;
}
