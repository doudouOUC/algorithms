#include<stdio.h>
#include<stdlib.h>
//#include"adjacencyList.h"
//#include"traverse.h"
#include"adjacencyMatrix.h"

int main()
{
    /*
    ALGraph *graph = malloc(sizeof(ALGraph));
    createALGraph(graph);
    printGraph(graph);
    //BFS(graph,1);
//    DFS(graph);
//    topological_sort(graph);
    */
    MGraph *graph = malloc( sizeof(MGraph) );
    createMGraph(graph);
    printMGraph(graph);
    return 0;
}
