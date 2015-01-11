#include "MST.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#define PARENT(i) (i/2)
#define LEFT(i) (2*i)
#define RIGHT(i) (2*i+1)

void swapEdge(Edge *a, Edge *b)
{
    Edge *temp = malloc( sizeof(Edge) );
    memcpy(temp, a, sizeof(Edge));
    memcpy(a, b, sizeof(Edge));
    memcpy(b, temp, sizeof(Edge));
    free(temp);
}

int partition(Edge *edges, int p, int r)
{
    int i, j;
    i = p -1;
    for( j=p; j<r; j++)
    {
        if( edges[j].weight <= edges[r].weight )
        {
            i += 1;
            swapEdge(&edges[i], &edges[j]);
        }
    }
    swapEdge(&edges[i+1], &edges[r]);
    return i+1;
}

void quickSortEdges(Edge *edges, int p, int r)
{
    int q;
    if( p < r )
    {
        q = partition(edges, p, r);
        quickSortEdges(edges, p, q-1);
        quickSortEdges(edges, q+1, r);
    }
}

/* 查找连线顶点的尾部下标 */
int find(int *parent, int f)
{
    while(parent[f] > -1)
        f = parent[f];
    return f;
}

/* Kruskal 最小生成树算法*/
void kruskalMST(MGraph *G)
{
    int i, j, k;
    int bV, eV; //begin, end
    //无向图
    G->numEdges *= 2;
    //定义边数组
    Edge *edges = malloc( sizeof(Edge)*G->numEdges );
    int *parent = malloc( sizeof(int)*G->numVertexes );
    
    //初始化联通量
    for(i=0; i< G->numVertexes;i++)
    {
        parent[i] = -1;
    }
    //初始化边数组
    k = 0; 
    for( i=0; i<G->numVertexes;i++)
    {
        for( j=0; j<G->numVertexes; j++ )
        {
            if( G->edges[i][j] != INFINITY)
            {
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = G->edges[i][j];
                k++;
            }
        }
    }
    putchar('\n');
    //边权排序
    /*
    for(i=0;i<G->numEdges;i++)
    {
        printf(" %d %d %d ", edges[i].begin, edges[i].end, edges[i].weight );
    }
    */     
    quickSortEdges(edges, 0, G->numEdges-1);

    for(i =0; i <G->numEdges; i++)
    {
        bV = find(parent, edges[i].begin);
        eV = find(parent, edges[i].end);
        //最小权边
        if( bV!= eV)
        {
            printf("%d-%d weight %d added\n", edges[i].begin, edges[i].end, edges[i].weight);
            //将此边的结尾点加入到下标尾起点的parent中，表示此节点已经加入到生成树中
            //跟先后循序无关，跟初始化parent数组有关。
            parent[eV] = bV;
        }
    }
    free(edges);
    free(parent);
}

/* Prime 最小生成树算法*/
//O(n2)
void primNormal(MGraph *G)
{
    int i, j, k, min;
    int *lowcost = malloc(sizeof(int)*G->numVertexes); //保存相关顶点间编剧权值
    int *adjvex = malloc(sizeof(int)*G->numVertexes);//保存相关顶点下标
    /*lowcast 值为0，表示该下标顶点已经加入生成树*/
    lowcost[0] = 0; 
    adjvex[0] = 0; 
    for(i=1;i<G->numVertexes;i++)
    {
        lowcost[i] = G->edges[0][i];
        adjvex[i] = 0;
    }

    for(i=1;i<G->numVertexes;i++)
    {
        j = 0;
        min = INFINITY;
        while( j<G->numVertexes )
        {
            if(lowcost[j]&&lowcost[j]<min)
            {
                min = lowcost[j];
                k = j;
            }
            j++;
        }
        printf("(%d,%d)",adjvex[k], k);
        lowcost[k] = 0;
        for(j=1; j<G->numVertexes;j++)
        {
            if( (lowcost[j]!=0) &&(lowcost[j] >G->edges[k][j]))
            {
                lowcost[j] = G->edges[k][j];
                adjvex[j] = k;
            }
        }
    }
    free(lowcost);
    free(adjvex);
}


void build_min_heap(int heap[], int key[])
{

}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void min_heapify(MinHeap *heap)
{
    int l, r, minimum;
    l = LEFT(i);
    r = right(i);
    if( l<size && key[heap(l)] <key[heap(i)])
        minimum = l;
    else
        minimum = i;
    if( r<size &&key[heap(r)] <key[heap(i)])
        minimum = r;
    if(minimum !=i)
    {
        swap(&heap[i], &heap[minimum]);
        min_heapify(heap, key, minimum, size);
    }
}

void heap_decrease_num(int heap[], int i, int key[], int num)
{
}


void primHeap(MGraph *G)
{
    
}


void primMST(MGraph *G)
{
    primNormal(G);
}

