#include"tree_array.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>


//#define TREE_SIZE 100  //定义二叉树大小
//#define ARRAY_SIZE (TREE_SIZE + 1) //定义存储二叉树数组大小，因为省去0，所以要+1

static TREE_TYPE *tree;
static int array_size;

static int left_child(int current)
{
    return current*2;
}

static int right_child(int current)
{
    return current*2+1;
}

/*
 * 动态分配数组
 */
void createBinaryTree()
{
    tree = malloc(101*sizeof(TREE_TYPE));
    array_size = 100;
    tree[0] = 0;
    assert( tree != NULL);
}

void reallocTree(int current)
{
    TREE_TYPE *old = tree;
    int i, total = 0;
    for(i = 0; total < current;i++)
    {
        total = pow(2, i);
    }
    tree = malloc( (total+1)*sizeof(TREE_TYPE) );
    assert(old != NULL);
    for(i = 0; i < array_size;i++)
    {
        tree[i] = old[i];
    }
    array_size = total;
    free(old);
}

/*
 * 向树添加一个新值，参数是需要被添加的值，它必须原先并不在树中
 */
void insert( TREE_TYPE value)
{
    assert( value != 0);
    int current = 1;
    while( tree[current] != 0 )
    {
       if( value < tree[current] )
       {
           current = left_child(current);
       }else
       {
           current = right_child(current);
       }
       if( current > array_size )
       {
           reallocTree(current);
       }
    }
    assert( current < array_size );
    tree[current] = value;
}

/*
 * 查找一个特定的值，这个值作为第一个参数传递个函数
 */

TREE_TYPE *find( TREE_TYPE value)
{
    int current = 1;
    while( tree[current] != value )
    {
        if( value < tree[current] )
            current = left_child(current);
        else
            current = right_child(current);
        //assert( current < array_size );
        if( current > array_size )
            break;
    }
    if( current < array_size)
    {
        //printf("current is %d", current);
        //printf("find is %d", *(tree+current));
        return tree+current;
    }
    else
        return tree;
}

/*
 * 执行树的前序遍历，它的参数是一个回调函数指针，他所指向的函数将在树中处理
 * 每个节点被调用，节点的值作为参数传递给这个函数
 */
//void pre_order_traverse( void(*callback)(TREE_TYPE value) );

void pre_order_traverse(int root)
{
    if(root > array_size || tree[root] == 0)
        return;
    printf("%3d", tree[root]);
    pre_order_traverse(left_child(root));
    pre_order_traverse(right_child(root));
}

int treeSize()
{
    return array_size;
}
