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

//递归输出两点间路径
void printPath(int P[][MAXVERNUM], int i, int j)
{
    if(P[i][j] == -1)
        return;
    printPath(P, i, P[i][j]);
    printf("%d-%d ", P[i][j], j);
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

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printPath(P,i,j);
            printf(" d=%d\n", D[i][j]);
        }
    }
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
            if( i!=j && W[i][j] != INFINITY)
                P[i][j] = i;
            else
                P[i][j] = -1;
                
        }
    }
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                //前趋子图的时候这个地方判断错了，应该是<= 
                /*
                if(D[i][j] <= D[i][k] +D[k][j])
                {
                    D[i][j] = D[i][j];
                   // PTemp[i][j] = P[i][j];
                }
                else
                {
                    D[i][j] = D[i][k]+D[k][j];
                    P[i][j] = P[k][j];
                }
                */
                //改成现在形式更简单
                if(D[i][j] > D[i][k] +D[k][j])
                {
                    D[i][j] = D[i][k]+D[k][j];
                    P[i][j] = P[k][j];
                }

            }
        }
        //memcpy(P,PTemp,sizeof(PTemp));
    }
    printPairsSP(D, P, n);
}
