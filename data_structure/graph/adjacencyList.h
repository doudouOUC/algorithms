#define MAXVERNUM 100 //最大顶点数

typedef char* VertexType;

/* 边表节点 */
typedef struct node
{
    int adjvex; //邻接点域
    struct node *next; //指向下一个邻接点的指针域
    // 若要表示边上信息，则应增加一个数据域info
} EdgeNode;

/* 顶点表结点 */
typedef struct vnode
{
    VertexType vertex; //顶点域
    EdgeNode *firstedge; // 边表头指针
} VertexNode;

typedef VertexNode AdjList[MAXVERNUM]; /* AdjList 是邻接表类型*/

typedef struct
{
    AdjList adjlist; //邻接表
    int n,e; //顶点数和边数
} ALGraph; // ALGraph 是以邻接表方式存储的图类型

typedef struct topnode
{
    struct topnode *next;
    VertexType vertex;
    int d;//发现时间
    int f;//结束时间
} TopNode;

void createALGraph( ALGraph *G );
void printGraph(ALGraph *G);
