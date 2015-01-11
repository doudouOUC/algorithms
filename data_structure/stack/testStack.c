#include<stdio.h>

//#include "stack_array.h"
#include "stack_list.h"

int main()
{
    int i;
    create_stack(50);
    for(i = 0; i < 50; i ++)
    {
        push(i);
    }
    while( !is_empty() )
    {
        printf("%3d", top());
        pop();
    }
    printf("\n");
    return 0;
}

