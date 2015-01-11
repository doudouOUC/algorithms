#include "adjacencyMatrix.h"

/*Kruskal 最小生成树需要边结构*/
typedef struct
{
    int begin;
    int end;
    int weight;
} Edge;

typedef struct
{
    int ver;
    int key;
} Vertex;

/* Prime 最小生成树堆结构 */
typedef struct
{
    int size;
    Vertex *vertexes;
} MinHeap;

void kruskalMST(MGraph *G);
void primMST(MGraph *G);

