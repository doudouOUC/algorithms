#include<stdio.h>
//#include"tree_array.h"
#include "tree_list.h"
#include<assert.h>

int main()
{
    int i;
    createBinaryTree();
    for( i = 1; i < 20; i++)
    {
        insert(i);
    }
    pre_order_traverse();
    printf("\n");
    printf("find 1 in %d\n", *find(1));
    assert( find(2) != NULL);
    printf("find 11 in %d\n", *find(11));
    return 0;
}
