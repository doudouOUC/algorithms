#include<stdio.h>
#include<stdlib.h>
//#include"bellman-ford.h"
#include"dijkstra.h"

int main()
{
    MGraph *graph = malloc(sizeof(MGraph));
    createMGraph(graph);
    printMGraph(graph);
    //dijkstra(graph, 0);
    dijkstra_normal(graph,0);
    printShortestPath(graph,0);

    /*
    int test;
    ALGraph *graph = malloc(sizeof(ALGraph));
    createALGraph(graph);
    printGraph(graph);

    if(bellman_ford(graph, 0)>0)
    {
       printshortestPath(graph, 0);
    }
    else
    {
        printf("there is a negative circle\n");
    }
    
    test = -1;
    if(test)
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    */
    return 0;
}
