#include "adjacencyMatrix.h"

/*Kruskal 最小生成树需要边结构*/
typedef struct
{
    int begin;
    int end;
    int weight;
}Edge;
void kruskalMST(MGraph *G);
void primeMST(MGraph *G);

