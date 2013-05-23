#include"adjacencyMatrix.h"

typedef struct 
{
    int size;
    int *heap;
} MinQueue;

void dijkstra(MGraph *G, int s);
void dijkstra_normal(MGraph *G, int s);
void printShortestPath(MGraph *G, int s);
