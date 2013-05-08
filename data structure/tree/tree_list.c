#include "tree_list.h"
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>

typedef struct TREE_NODE
{
    TREE_TYPE value;
    struct TREE_NODE *left_child;
    struct TREE_NODE *right_child;
}TreeNode;


static TreeNode *tree = NULL;
static int treeSize = 0;

/*
 * 动态分配数组
 */
void createBinaryTree()
{

}

/*
 * 向树添加一个新值，参数是需要被添加的值，它必须原先并不在树中
 */
void insert( TREE_TYPE value)
{
    TreeNode *current = tree;
    TreeNode *parent = tree;

    while(current != NULL)
    {
        parent = current;
        if( value < parent->value )
            current = current->left_child;
        else
            current = current->right_child;
    }
    current = malloc(sizeof(TreeNode));
    current->value = value;
    current->left_child = NULL;
    current->right_child = NULL;
    if( parent == NULL)
        tree = current;    
    else if( value < parent->value )
        parent->left_child = current;
    else
        parent->right_child = current;
}

/*
 * 查找一个特定的值，这个值作为第一个参数传递个函数
 */

TREE_TYPE *find( TREE_TYPE value)
{
    TreeNode *current = tree;
    while( current != NULL && current->value != value )
    {
        if( value < current->value )
            current = current->left_child;
        else 
            current = current->right_child;
    }
    if( current != NULL )
    {
        return &current->value;
    }
    else
        return NULL;
}

/*
 * 执行树的前序遍历，它的参数是一个回调函数指针，他所指向的函数将在树中处理
 * 每个节点被调用，节点的值作为参数传递给这个函数
 */
//void pre_order_traverse( void(*callback)(TREE_TYPE value) );

void do_pre_order_traverse(TreeNode *current)
{
    if( current == NULL)
        return;
    printf("%3d", current->value);
    do_pre_order_traverse(current->left_child);
    do_pre_order_traverse(current->right_child);
}

void pre_order_traverse()
{
    do_pre_order_traverse(tree);
}


