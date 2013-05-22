#include<stdio.h>
#include<stdlib.h>
#include"bellman-ford.h"

int main()
{
    int test;
    ALGraph *graph = malloc(sizeof(ALGraph));
    createALGraph(graph);
//    printGraph(graph);
    
    if(bellman_ford(graph, 1)>0)
    {
       printshortestPath(graph, 1);
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

    return 0;
}
