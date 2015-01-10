#include"stack_list.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


typedef struct STACK_NODE
{
    STACK_TYPE value;
    struct STACK_NODE *next;
} StackNode;

/*
 * 指向堆栈中第一个节点的指针
*/

static StackNode *stack;

void create_stack(int size)
{

}


void destroy_stack()
{
    while( !is_empty() )
    {
        pop();
    }
}

//push
void push(STACK_TYPE value)
{
    StackNode *new_node;
    new_node = malloc( sizeof(StackNode) );
    //分配成功与否
    assert( new_node != NULL );
    new_node->value = value;
    new_node->next = stack;
    stack = new_node;
}

//pop
void pop()
{
    assert( !is_empty() );
    StackNode *first_node;
    first_node = stack;
    stack = stack->next;
    free(first_node);
}

//top
STACK_TYPE top()
{
    assert( !is_empty() );
    return stack->value;
}

//is_empty
int is_empty()
{
    return stack == NULL;
}

//if_full
int is_full()
{

}
