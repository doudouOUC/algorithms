#include"matrixSP.h"

void extend_shortest_paths(int **L, int **L, int n)
{
    int LTemp
}

void faster_all_pairs_shortest_paths(MGraph *G)
{
    int n, m;
    n = G->numVertexes;
    int W[MAXVERNUM][MAXVERNUM];
    //initial W
    //
    int L[MAXVERNUM][MAXVERNUM];
    m = 1;
    while(m < n-1)
    {
        extend_shortest_paths(L, L, n);
        m *= 2;
    }
}

