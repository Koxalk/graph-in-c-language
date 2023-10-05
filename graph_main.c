#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack_function.h"

void dfs(Graph *graph);

int main(int argc, char const *argv[])
{
    int numVertices = 6; // Change this to the desired number of vertices
    Graph *graph = createGraph(numVertices);

    // Example: Adding edges
    addEdge(graph, 'A', 'B');
    addEdge(graph, 'A', 'C');

    addEdge(graph, 'B', 'D');
    addEdge(graph, 'C', 'D');

    addEdge(graph, 'D', 'E');
    addEdge(graph, 'F', 'E');
    

    // Print the graph
    printGraph(graph);

    printf("<======================> \n");
    printf("Topological Sort\n");
    dfs(graph);

    return 0;
}

void dfsUtil(Graph *graph, int vertex, bool *visited, St *stack)
{
    visited[vertex] = true;

    Node *current = graph->adjList[vertex];
    
    while (current != NULL)
    {
        int adjacentVertex = current->data - 'A';
        if (!visited[adjacentVertex])
        {
            dfsUtil(graph, adjacentVertex, visited, stack);
        }
        current = current->next;
    }

    push(stack, createNode(vertex + 'A'));
}

void dfs(Graph *graph)
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
            dfsUtil(graph, i, visited, stack);
    }

    while (!isEmpty(stack))
    {
        Node *temp = peek(stack);

        printf("%c\n", temp->data);

        pop(stack);
    }
}
