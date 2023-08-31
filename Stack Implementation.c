#include <stdio.h>
#include <stdlib.h>

// Structure for a stack node
struct StackNode {
    int data;
    struct StackNode *next;
};

// Structure for the stack
struct Stack {
    struct StackNode *top;
};

// Function to create a new stack node
struct StackNode *createNode(int data) {
    struct StackNode *newNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a new stack
struct Stack *initializeStack() {
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return stack->top == NULL;
}

// Function to push a new element onto the stack
void push(struct Stack *stack, int data) {
    struct StackNode *newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(1);
    }
    struct StackNode *temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to peek at the top element of the stack
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        exit(1);
    }
    return stack->top->data;
}

int main() {
    struct Stack *stack = initializeStack();

    push(stack, 3);
    push(stack, 5);
    push(stack, 7);

    printf("Top element: %d\n", peek(stack));

    printf("Popped element: %d\n", pop(stack));

    printf("Top element after pop: %d\n", peek(stack));

    free(stack);

    return 0;
}
