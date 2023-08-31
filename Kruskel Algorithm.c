#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a subset for union-find
struct Subset {
    int parent, rank;
};

// Comparison function for sorting edges based on weight
int compareEdges(const void *a, const void *b) {
    return ((struct Edge *)a)->weight - ((struct Edge *)b)->weight;
}

// Function to find the parent of a subset (with path compression)
int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Function to perform union of two subsets (with union by rank)
void unionSets(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

// Function to find the Minimum Spanning Tree using Kruskal's algorithm
void kruskalMST(struct Edge edges[], int V, int E) {
    struct Subset *subsets = (struct Subset *)malloc(V * sizeof(struct Subset));
    struct Edge *result = (struct Edge *)malloc((V - 1) * sizeof(struct Edge));

    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    qsort(edges, E, sizeof(struct Edge), compareEdges);

    int e = 0; // Index variable for result[]
    int i = 0; // Index variable for sorted edges[]
    while (e < V - 1) {
        struct Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        if (x != y) {
            result[e++] = next_edge;
            unionSets(subsets, x, y);
        }
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < V - 1; i++)
        printf("%d - %d (%d)\n", result[i].src, result[i].dest, result[i].weight);

    free(subsets);
    free(result);
}

// Driver program
int main() {
    int V = 4; // Number of vertices in the graph
    int E = 5; // Number of edges in the graph

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges, V, E);

    return 0;
}
