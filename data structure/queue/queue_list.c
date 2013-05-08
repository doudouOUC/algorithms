#include "queue_list.h"
#include<stdio.h>
#include<assert.h>


#define FALSE 0
/*
 * 定义一个结构以存储堆栈元素，其中next字段指向堆栈的下一个元素
 */
typedef struct QUEUE_NODE
{
    QUEUE_TYPE value;
    struct QUEUE_NODE *next;
   // struct QUEUE_NODE *pre;
} QueueNode;

/*
 * 用于存储队列元素的数组和指向队列头和尾的指针
 */
static QueueNode *head = NULL;
static QueueNode *tail = NULL;


/*
 * 创建一个队列，参数制定队列可以存储的元素的最大数量。
 * 只适用与动态分配数组的队列
*/
void create_queue( int size )
{
    
}

/*
 * 销毁一个队列：只适用与链式和动态分配数组的队列
*/
void destroy_queue()
{
    while( !is_empty() )
    {
        delete();
    }
}

/*
 * insert
*/
void insert(QUEUE_TYPE value)
{
    QueueNode *newNode = malloc(sizeof(QueueNode));
    newNode->value = value;
    newNode->next = NULL;
    if( is_empty() )
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

/*
 * delete
 */
void delete()
{
    assert( !is_empty() );
    QueueNode *delNode = head;
    head = head->next;
    free(delNode);
}

/*
 * first
 */
QUEUE_TYPE first()
{
    assert( !is_empty() );
    return head->value;
}

/*
 * 如果队列为空，返回true 否则返回false
 */
int is_empty()
{
    return (head == NULL);
}

/*
 * if_full
 */
int is_full()
{
    return FALSE;
}
