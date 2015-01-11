#include"bellman-ford.h"
#include<stdio.h>

static int d[MAXVERNUM];
static int p[MAXVERNUM];

void initialize_single_source(ALGraph *G, int s)
{
    int i;
    for(i=0;i<G->n;i++)
    {
        d[i] = INFINITY;
        p[i] = -1;
    }
    p[s] = s;
    d[s] = 0;
}

void relax(int u, int v, int w)
{
    if(d[v]>d[u]+w)
    {
        d[v] = d[u]+w;
        p[v] = u;
    }
}

int bellman_ford(ALGraph *G, int s)
{
    int j,i;
    EdgeNode *edge;
    initialize_single_source(G, s);
    for( j =0 ;j<G->n-1;j++)
    {
        for(i=0;i<G->n;i++)
        {
            edge = G->adjlist[i].firstedge;
            while(edge != NULL)
            {
                relax(i,edge->adjvex,edge->w);
                edge = edge->next;
            }
        }
    }

    for(i=0;i<G->n;i++)
    {
        edge = G->adjlist[i].firstedge;
        while(edge != NULL)
        {
            if(d[i]>d[edge->adjvex]+ edge->w)
            {
                return -1;
            }
            edge = edge->next;
        }
    }
    return 1;
}

void printshortestPath(ALGraph *G, int s)
{
    int i, j;
    for(i=0;i<G->n;i++)
    {
        printf("%d to %d = %d\n", s, i, d[i]);
        j=i;
        while(p[j]!=s)
        {
            printf("%d-%d ",j, p[j]);
            j = p[j];
        }
        printf("%d-%d ", j, p[j]);
        putchar('\n');
    }
}
