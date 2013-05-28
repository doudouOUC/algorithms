#include"floyd-warshall.h"
#include<string.h>
#include<stdio.h>

int min(int a, int b)
{
    if( a<b )
        return a;
    else
        return b;
}

void printPairsSP(int D[][MAXVERNUM], int P[][MAXVERNUM], int n)
{
    int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" %4d", D[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" %4d", P[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

void printP(int P[][MAXVERNUM], int n)
{
    int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf(" %4d", P[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}

void floyd_warshall(MGraph *G)
{
    int n, i, j, k;
    int W[MAXVERNUM][MAXVERNUM];
    int D[MAXVERNUM][MAXVERNUM];
    int P[MAXVERNUM][MAXVERNUM];
    int PTemp[MAXVERNUM][MAXVERNUM];
    n = G->numVertexes;
    memcpy(W,G->edges,sizeof(W));
    //initial W i =j Wij = 0
    for(i=0;i<n;i++)
        W[i][i] = 0;
    memcpy(D,W,sizeof(D));
    //initial P
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            
            if(W[i][j] == INFINITY || i==j)
                P[i][j] = -1;
            else
                P[i][j] = i;
                
        }
    }
    printP(P,n);
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(D[i][j] < D[i][k] +D[k][j])
                {
                    D[i][j] = D[i][j];
                   // PTemp[i][j] = P[i][j];
                }
                else
                {
                    D[i][j] = D[i][k]+D[k][j];
                    P[i][k] = i;
                    P[i][j] = k;
                }

            }
        }
        printP(P,n );
        //memcpy(P,PTemp,sizeof(PTemp));
    }
    printPairsSP(D, P, n);
}
