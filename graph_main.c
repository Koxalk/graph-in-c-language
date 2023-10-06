#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "topological_fun.h"

#include <C:/Program Files/Graphviz/include/graphviz/cgraph.h>

void generateDotFile(Graph *graph, const char *filename);

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
    topologicalSort(graph);

    generateDotFile(graph, "graph.dot");

    system("dot -Tpng -Gdpi=300 -Gsize=5,5 graph.dot -o graph.png");

    return 0;
}

// Function to generate a DOT file from the graph
void generateDotFile(Graph *graph, const char *filename)
{
    FILE *dotFile = fopen(filename, "w");
    if (!dotFile)
    {
        perror("Error opening DOT file");
        return;
    }

    fprintf(dotFile, "digraph G {\n");

    // Write DOT statements to define the graph structure
    for (int i = 0; i < graph->numVertices; i++)
    {
        Node *current = graph->adjList[i];
        while (current != NULL)
        {
            fprintf(dotFile, "  %c -> %c;\n", i + 'A', current->data);
            current = current->next;
        }
    }

    fprintf(dotFile, "}\n");
    fclose(dotFile);
}