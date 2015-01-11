#include"stack_array.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

/*
 * 用与存储堆栈元素的数组和指向堆栈顶部元素的指针
*/
static STACK_TYPE *stack;
static int stack_size;
static int top_element = -1;


void create_stack(int size)
{
    assert( stack_size == 0);
    stack_size = size;
    stack = malloc(stack_size*sizeof(STACK_TYPE) );
    assert( stack != NULL );
}

void destroy_stack()
{
    assert( stack_size > 0 );
    stack_size = 0;
    free(stack);
    stack = NULL;
}

//push
void push(STACK_TYPE value)
{
    assert( !is_full() );
    stack[++top_element] = value;
}

//pop
void pop()
{
    assert( !is_empty() );
    top_element --;
}

//top
STACK_TYPE top()
{
    return stack[top_element];
}

//is_empty
int is_empty()
{
    return top_element == -1;
}

//if_full
int is_full()
{
    assert(stack_size > 0);
    return top_element == stack_size-1;
}

