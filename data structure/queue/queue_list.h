#include<stdlib.h>
#define QUEUE_TYPE int /* 队列元素的类型 */

/*
 * 创建一个队列，参数制定队列可以存储的元素的最大数量。
 * 只适用与动态分配数组的队列
*/
void create_queue( int size );

/*
 * 销毁一个队列：只适用与链式和动态分配数组的队列
*/
void destroy_queue();

/*
 * insert
*/
void insert(QUEUE_TYPE value);

/*
 * delete
 */
void delete();

/*
 * first
 */
QUEUE_TYPE first();

/*
 * 如果队列为空，返回true 否则返回false
 */
int is_empty();

/*
 * if_full
 */
int is_full();
