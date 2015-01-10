#include"traverse.h"
#include<stdio.h>
#include<stdlib.h>

/* 
 * 图的广度遍历所需变量
 */
static int color[MAXVERNUM] = {0}; //都需要
static int d[MAXVERNUM]; //广度遍历表示路径 深度遍历记录时间表示发现时间
static int p[MAXVERNUM]; //pi

/*
 *图的深度遍历所需变量
 */
static int f[MAXVERNUM] = {0}; //深度遍历表示结束时间
static int time = 0; //用来记录时间

static void initTraverse(ALGraph *G)
{
    int i;
    for(i=0; i<= G->n;i++)
    {
        color[i] = WHITE;
    }
}

/* 广度优先遍历 */
void BFS(ALGraph *G, int s)
{
    initTraverse(G);
    int i, j, u;
    EdgeNode *v;
    for( u=0; u < G->n; u++ )
    {
        d[u] = 500;
        p[u] = -1;
    }
    color[s] = GRAY;
    d[s] = 0;
    p[s]= -1;
    insert(s); //enqueue
    while( !is_empty() )
    {
        //dequeue
        u = first();
        delete();
        v = G->adjlist[u].firstedge;
        while( v != NULL)
        {
            if( color[v->adjvex] == WHITE )
            {
                color[v->adjvex] = GRAY;
                d[v->adjvex] = d[u] + 1;
                p[v->adjvex] = u;
                insert(v->adjvex);
            }
            v = v->next;
        }
        color[u] = BLACK;
        printf("%d ", u);
    }
}

/* 深度优先遍历 */
void DFS_Visit(ALGraph *G, int u)
{
    printf("%d %s ",u, G->adjlist[u].vertex);
    color[u] = GRAY; //white vertex u has just been discovered
    time += 1;
    d[u] = time;
    EdgeNode *v;
    v = G->adjlist[u].firstedge;
    while( v != NULL )
    {
        if( color[v->adjvex] == WHITE )
        {
            p[v->adjvex] = u;
            DFS_Visit(G,v->adjvex);
        }
        v = v->next;
    }
    color[u] = BLACK; //Blacken u;it is finished
    //printf("%d ", u);
    time += 1;
    f[u] = time;
}
void DFS(ALGraph *G)
{
    int i;
    time = 0;
    initTraverse(G);
    for(i=1; i<= G->n;i++)
    {
        if(color[i] == WHITE)
            DFS_Visit(G, i);
    }
}

/* 拓扑排序 */
void topological_sort(ALGraph *G)
{
    int i;
    TopNode *head, *newNode, *current, *pre;
    DFS(G);
    head = malloc(sizeof(TopNode));
    head->next = NULL;
    head->d = d[1];
    head->f = f[1];
    head->vertex = G->adjlist[1].vertex;
    current = head;
    printf("\n");
    for( i =1; i<= G->n; i++)
    {
        printf("%d %d %d\n", i, d[i], f[i]);
    }

    for( i=2 ;i<= G->n; i++)
    {
        newNode = malloc(sizeof(TopNode));
        newNode->next = NULL;
        newNode->d = d[i];
        newNode->f = f[i];
        newNode->vertex = G->adjlist[i].vertex;
        current = head;
        pre = current;
        while( (current != NULL) && (current->f > newNode->f) )
        {
           // printf("%d", i);
            pre = current;
            current = current->next;
        }
        if( current == head )
        {
            newNode->next = head;
            //head->next = newNode;
            head = newNode;
            continue;
        }
        pre->next = newNode;
        newNode->next = current;
    }
    
    while( head != NULL )
    {
        //printf("%d ",head->f);
        printf("%d %s ",head->f, head->vertex);
        head = head->next;
    }
    printf("\n");
}

