#include<stdio.h>
#include<stdlib.h>
#include "adjacencyList.h"

/* 建立有向图的邻接表存储 */
void createALGraph( ALGraph *G )
{
    int i, j, k, w;
    EdgeNode *s, *d;
    //printf("Please input your vertices and edges,eg(v,e)\n");
    scanf("%d,%d", &(G->n), &(G->e)); /* 读入顶点数和边数 */
    //printf("Please input vertex info \n");
    for(i=1;i <= G->n; i++)
    {
        //G->adjlist[i].vertex = malloc(sizeof(char)*20);
        scanf("%d", &(G->adjlist[i].vertex));
        G->adjlist[i].firstedge = NULL; /* 顶点的边表头指针设为空 */
    }
    //printf("Please input edge info eg:(i,j)\n");
    /* 建立边表 */
    for( k = 0; k < G->e; k++)
    {
        /* 读入边<Vi,Vj>的顶点对应序号 */
        scanf("%d,%d,%d", &i, &j, &w);
        s = malloc(sizeof(EdgeNode)); //生成新边表结点s
        s->adjvex = j; /* 邻接点序号为 j*/
        s->next = G->adjlist[i].firstedge; //将新边表节点插入到顶点Vi的边表头部分
        s->w = w;
        G->adjlist[i].firstedge = s;
        //无向图 两条边
        d = malloc(sizeof(EdgeNode)); //生成新边表结点s
        d->adjvex = i; /* 邻接点序号为 j*/
        d->next = G->adjlist[j].firstedge; //将新边表节点插入到顶点Vi的边表头部分
        d->w = w;
        G->adjlist[j].firstedge = d;
    }
}

void printGraph(ALGraph *G)
{
    int i;
    EdgeNode *s;
    for(i=0; i < G->n; i++)
    {
        s = G->adjlist[i].firstedge;
        while( s != NULL)
        {
            printf("%d,%d,%d\n", i, s->adjvex, s->w);
            s = s->next;
        }
    }
}
