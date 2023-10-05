#ifndef FUN_IMPL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

// Define a structure for the graph
typedef struct Graph {
    int numVertices;
    Node** adjList;
} Graph;

Node* createNode(char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int numVertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = numVertices;
    graph->adjList = (Node**)malloc(numVertices * sizeof(Node*));

    for (int i = 0; i < numVertices; i++) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge between two vertices
void addEdge(Graph* graph, char src, char dest) {
    int srcIndex = src - 'A';
    int destIndex = dest - 'A';

    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[srcIndex];
    graph->adjList[srcIndex] = newNode;
}

// Function to print the graph
void printGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* current = graph->adjList[i];
        printf("Vertex %c: ", i + 'A');
        while (current != NULL) {
            printf("%c -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}


#endif