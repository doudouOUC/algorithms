#include"dijkstra.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define PARENT(i) (i/2)
#define LEFT(i) (2*i)
#define RIGHT(i) (2*i+1)

static int d[MAXVERNUM];
static int p[MAXVERNUM];

void initialize_single_source(MGraph *G, int s)
{
    int i;
    for(i=0;i<G->numVertexes;i++)
    {
        d[i] = INFINITY;
        p[i] = -1;
    }
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

void exchange(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(MinQueue *q, int i)
{
    int l, r, smallest;
    l = LEFT(i);
    r = RIGHT(i);
    if( l <= q->size && (d[q->heap[l]] < d[q->heap[i]]))
        smallest = l;
    else
        smallest = i;
    if( r <= q->size && (d[q->heap[r]] < d[q->heap[smallest]]))
        smallest = r;
    if(smallest != i)
    {
        exchange(&(q->heap[i]), &(q->heap[smallest]));
        min_heapify(q, smallest);
    }
}

void build_min_heap(MinQueue *q)
{
    int i;
    for(i=q->size/2;i>0;i--)
    {
        min_heapify(q,i);
    }
}

int extract_min(MinQueue *q)
{
    int min;
    assert(q->size > 0);
    min = q->heap[1];
    q->heap[1] = q->heap[q->size];
    q->size -= 1;
    min_heapify(q,1);
    return min;
}

void decrease_key(MinQueue *q, int i, int key)
{
    q->heap[i] = key;
    while( i > 1 && d[q->heap[PARENT(i)]] < d[q->heap[i]])
    {
        exchange(&(q->heap[i]), &(q->heap[PARENT(i)]));
        i = PARENT(i);
    }
}

void dijkstra(MGraph *G, int s)
{
    int i, *set, u, v;
    MinQueue queue;
    initialize_single_source(G, s);
    set = malloc(sizeof(int)*G->numVertexes);
    queue.size = G->numVertexes;
    queue.heap = malloc(sizeof(int)*(G->numVertexes+1));
    //初始化集合S为空
    for(i=0;i<G->numVertexes;i++)
    {
        set[i] = 0;
    }
    set[s] = 1;
    //初始化队列为空
    for(i=0;i<G->numVertexes;i++)
    {
        queue.heap[i+1] = i;
    }
    
    //逐步添加最小权值边
    while(queue.size>0)
    {
        build_min_heap(&queue);
        u = extract_min(&queue);
        set[u] = 1;
        for(i=0;i<G->numVertexes;i++)
        {
            if(G->edges[u][i] != INFINITY)
            {
                relax(u,i, G->edges[u][i]);
            }
        }
    }
}

void dijkstra_normal(MGraph *G, int s)
{ 
    int i ,j, *set;
    int minDis,minNode;
    initialize_single_source(G, s);
    set = malloc(sizeof(int)*G->numVertexes);
}

void printShortestPath(MGraph *G, int s)
{
    int i, j;
    for(i=0;i<G->numVertexes;i++)
    {
        printf("%d - %d = %d\n", s, i, d[i]);
    }
}
