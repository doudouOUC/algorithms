#include"stack.h"
#include<assert.h>

#define STACK_SIZE 100 //堆栈中数量最大的限制

/*
所有不属于外部接口的内容都被声明为static，
这可以防止用户使用预定义借口之外的任何方式访问堆栈中的值 
*/
static STACK_TYPE stack[STACK_SIZE];
static int top_element = -1;

void push(STACK_TYPE value)
{
    assert( !is_full() );
    top_element += 1;
    stack[top_element] = value;
}

STACK_TYPE pop()
{
    assert( !is_empty() );
    STACK_TYPE temp = stack[top_element];
    top_element -= 1;
    return temp;
}

int is_full()
{
    return top_element == STACK_SIZE -1;
}

int is_empty()
{
    return top_element == -1;
}
