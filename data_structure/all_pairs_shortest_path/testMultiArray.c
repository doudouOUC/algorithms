#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    int a[10][10];
    int **b;
    int i, j;
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            a[i][j] = 1;
        }
    }
    b = (int ** )malloc(10*sizeof(int *));
    //printf("sizeof(a) = %ld\n", sizeof(a));
    //printf("sizeof(b) = %ld\n", sizeof(b));
    /*
    for(i=0;i<10;i++)
    {
        b[i] = (int *)malloc(sizeof(int)*10);
    }
    for(i=0;i<10;i++)
    {
        memcpy(b[i], a[i], sizeof(int)*10);
    }
    */
    b[0] = (int *)malloc(10*10*sizeof(iny));
    memcpy(b[0][0],a[0][0],sizeof(a));
    for(i=0;i<10;i++)
    {
        for(j=0;j<10;j++)
        {
            printf("%4d",b[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
