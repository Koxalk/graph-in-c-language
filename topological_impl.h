#ifndef TOPOLOGICAL_IMPL

#include "stack_function.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void topologicalSortUtil(Graph *graph, int vertex, bool *visited, St *stack)
{
    visited[vertex] = true;

    Node *current = graph->adjList[vertex];

    while (current != NULL)
    {
        int adjacentVertex = current->data - 'A';
        if (!visited[adjacentVertex])
        {
            topologicalSortUtil(graph, adjacentVertex, visited, stack);
        }
        current = current->next;
    }

    push(stack, createNode(vertex + 'A'));
}

void topologicalSort(Graph *graph)
{
    int i;
    int n = graph->numVertices;

    St *stack = create_stack(n);

    bool *visited = (bool *)malloc(n * sizeof(bool));

    for (i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    for (i = 0; i < n; i++)
    {
        if (visited[i] == false)
            topologicalSortUtil(graph, i, visited, stack);
    }

    while (!isEmpty(stack))
    {
        Node *temp = peek(stack);

        printf("%c\n", temp->data);

        pop(stack);
    }
}

#endif

