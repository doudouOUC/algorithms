#include "MST.h"
#include<stdlib.h>

void sortEdges(Edge *edges)
{
    
}

/* Kruskal 最小生成树算法*/
void kruskalMST(MGraph *G)
{
    int i, j;
    //定义边数组
    Edge *edges = malloc( sizeof(Edge)*G->numEdges );
    int *parent = malloc( sizeof(int)*G->numVertexes );
    //初始化边数组
    for( i=0; i<G->numVertexes;)

    //边权排序
}

/* Prime 最小生成树算法*/
void primeMST(MGraph *G)
{

}
