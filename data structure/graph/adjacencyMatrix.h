
#define MAXVERNUM 100 //最大顶点数100
#define INFINITY 200
typedef char VertexType; //顶点类型设为字符型
typedef int EdgeType; //边的权值设为整型

/* Mgragh 是以邻接矩阵存储的图类型 */
typedef struct
{
    VertexType vexs[MAXVERNUM]; //顶点表
    EdgeType edges[MAXVERNUM][MAXVERNUM]; //邻接矩阵，即边表
    int numVertexes, numEdges; //顶点数和边数
}MGraph;


/*建立有向图G的邻接矩阵存储*/
void createMGraph(MGraph *G);
void printMGraph(MGraph *G);
