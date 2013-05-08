
#include "adjacencyList.h"
#include"queue_list.h"

//存放颜色 0:白色 1：灰色 2：黑色
#define WHITE 0
#define GRAY 1
#define BLACK 2
void BFS(ALGraph *G, int s);
void DFS(ALGraph *G);
void topological_sort(ALGraph *G);
