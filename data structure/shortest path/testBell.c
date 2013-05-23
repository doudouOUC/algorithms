#include<stdio.h>
#include<stdlib.h>
#include"bellman-ford.h"

int main()
{
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
    /* 
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
