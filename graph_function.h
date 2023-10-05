#ifndef FUN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "graph_functions_impl.h"

Node* createNode(char data);
Graph* createGraph(int numVertices);
void addEdge(Graph* graph, char src, char dest);
void printGraph(Graph* graph);

#endif