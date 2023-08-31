#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
struct QueueNode {
    int data;
    struct QueueNode *next;
};

// Structure for the queue
struct Queue {
    struct QueueNode *front, *rear;
};

// Function to create a new queue node
struct QueueNode *createNode(int data) {
    struct QueueNode *newNode = (struct QueueNode *)malloc(sizeof(struct QueueNode));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize a new queue
struct Queue *initializeQueue() {
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    queue->front = queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue) {
    return queue->front == NULL;
}

// Function to enqueue a new element into the queue
void enqueue(struct Queue *queue, int data) {
    struct QueueNode *newNode = createNode(data);
    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to dequeue an element from the queue
int dequeue(struct Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        exit(1);
    }
    struct QueueNode *temp = queue->front;
    int data = temp->data;
    queue->front = temp->next;
    free(temp);
    return data;
}

// Function to display the elements of the queue
void displayQueue(struct Queue *queue) {
    struct QueueNode *current = queue->front;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Queue *queue = initializeQueue();

    enqueue(queue, 3);
    enqueue(queue, 5);
    enqueue(queue, 7);

    printf("Queue elements: ");
    displayQueue(queue);

    printf("Dequeued element: %d\n", dequeue(queue));

    printf("Queue elements after dequeue: ");
    displayQueue(queue);

    free(queue);

    return 0;
}
