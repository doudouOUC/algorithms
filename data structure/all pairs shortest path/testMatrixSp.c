#include<stdio.h>
#include"matrixSP.h"

int main()
{
    MGraph graph;
    createMGraph(&graph);
    printMGraph(&graph);
    faster_all_pairs_shortest_paths(&graph);
    return 0;
}
