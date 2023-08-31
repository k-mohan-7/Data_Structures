#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the linked list
struct Node {
    int data;
    struct Node *next;
};

// Function to create a new node
struct Node *createNode(int data) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
struct Node *insertAtBeginning(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the linked list
struct Node *insertAtEnd(struct Node *head, int data) {
    struct Node *newNode = createNode(data);
    
    if (head == NULL)
        return newNode;
    
    struct Node *current = head;
    while (current->next != NULL)
        current = current->next;
    
    current->next = newNode;
    return head;
}

// Function to delete a node with a specific value from the linked list
struct Node *deleteNode(struct Node *head, int data) {
    if (head == NULL)
        return head;
    
    if (head->data == data) {
        struct Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    struct Node *current = head;
    while (current->next != NULL && current->next->data != data)
        current = current->next;
    
    if (current->next != NULL) {
        struct Node *temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    
    return head;
}

// Function to print the linked list
void printList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Function to free the memory occupied by the linked list
void freeList(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        struct Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL;

    head = insertAtBeginning(head, 3);
    head = insertAtEnd(head, 5);
    head = insertAtBeginning(head, 2);
    head = insertAtEnd(head, 7);

    printf("Linked list after insertion: ");
    printList(head);

    head = deleteNode(head, 5);

    printf("Linked list after deletion: ");
    printList(head);

    freeList(head);

    return 0;
}
