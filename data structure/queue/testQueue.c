#include<stdio.h>
//#include "queue_array.h"
#include"queue_list.h"

int main()
{
    int i;
    create_queue(20);
    for(i = 0; i < 19; i++)
    {
        insert(i);
    }
     
    while( !is_empty() )
    {
        printf("%3d", first());
        delete();
    }
    printf("\n");
    //destroy_queue();
    
    return 0;
}
