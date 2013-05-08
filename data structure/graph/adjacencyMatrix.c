#include"adjacencyMatrix.h"
#include<stdio.h>
#include<stdlib.h>

void createMGraph(MGraph *G)
{
    int i, j, k, w;
    char ch;
    /*读入顶点数和边数*/
    scanf("%d,%d", &(G->numVertexes), &G->numEdges);
    /* 读入顶点信息 */
    for( i=0; i < G->numVertexes; i++)
    {
        scanf("\n%c", &G->vexs[i]);
    }
    /*邻接矩阵初始化*/
    for( i=0; i< G->numVertexes; i++)
    {
        for( j=0; j < G->numVertexes; j++)
        {
           G->edges[i][j] = INFINITY;
        }
    }
    /*读入numEdges条边，建立邻接矩阵*/
    for( k =0; k < G->numEdges; k++)
    {
        //输入边(vi,vj)上的权
        scanf("%d,%d,%d", &i, &j, &w);
        G->edges[i][j] = w;
        /* 此处假设是无向图 */
       // G->edges[j][i] = w;
    }
}

void printMGraph(MGraph *G)
{
    int i, j;
    for( i =0; i< G->numVertexes; i++)
    {
        for( j=0; j<G->numVertexes;j++)
            printf("%5d ", G->edges[i][j]);
        printf("\n");
    }
}
