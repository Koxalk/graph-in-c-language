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

bool isCyclicUtil(Graph *graph, int vertex, bool visited[], bool *recStack)
{
    visited[vertex] = true;
    recStack[vertex] = true;

    Node *current = graph->adjList[vertex];
    while (current != NULL)
    {
        int adjacentVertex = current->data - 'A';
        if (!visited[adjacentVertex])
        {
            if (isCyclicUtil(graph, adjacentVertex, visited, recStack))
            {
                return true;
            }
        }
        else if (recStack[adjacentVertex])
        {
            return true;
        }
        current = current->next;
    }

    recStack[vertex] = false;
    return false;
}

bool isCyclic(Graph *graph)
{
    int numVertices = graph->numVertices;
    bool visited[MAX_VERTICES];
    bool recStack[MAX_VERTICES];

    for (int i = 0; i < numVertices; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    for (int i = 0; i < numVertices; i++)
    {
        if (!visited[i])
        {
            if (isCyclicUtil(graph, i, visited, recStack))
            {
                return true;
            }
        }
    }

    return false;
}

#endif
