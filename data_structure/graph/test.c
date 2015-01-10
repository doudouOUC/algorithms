#include<stdio.h>

int main()
{
    int i;
    char test[20];
    for(i=0; i<20;i++)
    {
        scanf("\n%c", &test[i]);
    }

    for(i = 0; i< 20;i++)
        printf("%c ", test[i]);
    return 0;
}
