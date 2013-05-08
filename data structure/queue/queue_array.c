#include"queue_array.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define TRUE 1
#define FALSE 0

/*
 * 用于存储队列元素的数组和指向队列头和尾的指针
 */
static int array_size = 0;
//static QUEUE_TYPE queue[array_size];
static QUEUE_TYPE *queue;
static size_t head = 0;
static size_t tail = 0;


/*
 * 创建一个队列，参数制定队列可以存储的元素的最大数量。
 * 只适用与动态分配数组的队列
*/
void create_queue( size_t size )
{
    assert( array_size == 0);
    array_size = size; 
    queue = malloc( sizeof(QUEUE_TYPE)*size );
    assert( queue != NULL);
}

/*
 * 销毁一个队列：只适用与链式和动态分配数组的队列
*/
void destroy_queue()
{
    assert( array_size > 0 );
    free(queue);
    array_size = 0;
    queue = NULL;
}

/*
 * insert
*/
void insert(QUEUE_TYPE value)
{
    assert( !is_full() );
    queue[tail] = value;
    tail = (tail + 1)%array_size;
}

/*
 * delete
 */
void delete()
{
    assert( !is_empty() );
    head = (head + 1)%array_size;
}

/*
 * first
 */
QUEUE_TYPE first()
{
    assert( !is_empty() );
    return queue[head];
}

/*
 * 如果队列为空，返回true 否则返回false
 */
int is_empty()
{
    if( head == tail )
        return TRUE;
    return FALSE;
}

/*
 * if_full
 */
int is_full()
{
    if( (tail + 1)%array_size == head )
        return TRUE;
    return FALSE;
}
