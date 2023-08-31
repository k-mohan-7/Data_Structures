#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Maximum number of vertices in the graph
#define MAX_VERTICES 100

// Structure to represent a graph
struct Graph {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};

// Function to initialize the graph
void initGraph(struct Graph *graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge to the graph
void addEdge(struct Graph *graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1; // For undirected graph
}

// Breadth First Search traversal function
void BFS(struct Graph *graph, int startVertex) {
    bool visited[MAX_VERTICES] = { false };
    int queue[MAX_VERTICES]; // Queue to store vertices for BFS traversal
    int front = 0, rear = 0; // Front and rear pointers for the queue

    printf("Breadth First Traversal starting from vertex %d: ", startVertex);
    visited[startVertex] = true;
    queue[rear++] = startVertex;

    while (front < rear) {
        int vertex = queue[front++];
        printf("%d ", vertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjacencyMatrix[vertex][i] && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }

    printf("\n");
}

int main() {
    struct Graph graph;
    int vertices = 7; // Number of vertices in the graph

    initGraph(&graph, vertices);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 5);
    addEdge(&graph, 2, 6);

    int startVertex = 0; // Starting vertex for BFS traversal

    BFS(&graph, startVertex);

    return 0;
}
