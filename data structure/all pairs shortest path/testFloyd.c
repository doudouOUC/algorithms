#include<stdio.h>
#include"floyd-warshall.h"

int main()
{
    MGraph graph;
    createMGraph(&graph);
    printMGraph(&graph);
    floyd_warshall(&graph);
    return 0;
}
