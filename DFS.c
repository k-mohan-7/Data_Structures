#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_VERTICES 100

struct Graph {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
};


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

// Depth First Search traversal recursive function
void dfsTraversal(struct Graph *graph, int vertex, bool visited[]) {
    printf("%d ", vertex);
    visited[vertex] = true;

    for (int i = 0; i < graph->vertices; i++) {
        if (graph->adjacencyMatrix[vertex][i] && !visited[i]) {
            dfsTraversal(graph, i, visited);
        }
    }
}

// Depth First Search traversal function
void DFS(struct Graph *graph, int startVertex) {
    bool visited[MAX_VERTICES] = { false };

    printf("Depth First Traversal starting from vertex %d: ", startVertex);
    dfsTraversal(graph, startVertex, visited);
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

    int startVertex = 0; // Starting vertex for DFS traversal

    DFS(&graph, startVertex);

    return 0;
}
