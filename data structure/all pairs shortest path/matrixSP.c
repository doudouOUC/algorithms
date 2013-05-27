#include"matrixSP.h"
#include<string.h>
#include<stdio.h>

int min(int a, int b)
{
    if( a>b )
        return b;
    else
        return a;
}

void printPairsSP(int L[][MAXVERNUM], int n)
{
    int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            //printf("%i-%d = %d", i, j, L[i][j]);
                printf("%4d", L[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void extend_shortest_paths(int L[][MAXVERNUM], int W[][MAXVERNUM], int n)
{
    int LTemp[MAXVERNUM][MAXVERNUM];
    int i, j, k;
    int temp;
    for(i=0;i< n;i++)
    {
        for(j=0;j<n;j++)
        {
            LTemp[i][j] = INFINITY;
            for(k=0;k<n;k++)
            {
                if(L[i][k] == INFINITY || W[k][j] == INFINITY)
                    temp = INFINITY;
                else
                    temp = L[i][k] + W[k][j];
                LTemp[i][j] = min(LTemp[i][j], temp);
            }
        }
    }
    memcpy(L, LTemp, sizeof(LTemp));
//    printPairsSP(L, n);
}

void faster_all_pairs_shortest_paths(MGraph *G)
{
    int i, j;
    int n, m;
    n = G->numVertexes;
    int W[MAXVERNUM][MAXVERNUM];
    //initial W
    memcpy(W,G->edges,sizeof(W));
    //第一次做的时候这个地方做错了，因为i==j的情况下lij = 0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            if(i == j)
                W[i][j] = 0;
    }

    int L[MAXVERNUM][MAXVERNUM];
    //initial L1 = W
    memcpy(L, W, sizeof(L));
    
    m = 1;
    while(m < n)
    {
        extend_shortest_paths(L, W, n);
        m *= 2;
    }

    printPairsSP( L, n);
}

