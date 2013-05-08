#include<stdio.h>

#define ARRAYSIZE 50

void findMaxMin(int A[], int n)
{
    int min, max,i;
    if( A[0] > A[1] )
    {
        max = A[0];
        min = A[1];
    }else{
        max = A[1];
        min = A[0];
    }
    i = 2;
    while( (i+1) < n )
    {
        if( A[i] < A[i+1])
        {
            if( A[i] < min)
                min = A[i];
            if( A[i+1] > max )
                max = A[i+1];
        }else
        {
            if( A[i] > max )
                max = A[i+1];
            if( A[i+1] < min )
                min = A[i+1];
        }
        i +=2;
    }
    printf("last i is %d\n", i);
    if( i < n)
    {
        if( A[i] < min )
            min = A[i];
        if( A[i] > max )
            max = A[i];
    }
    printf("%d\n%d\n", min, max);
}

int main()
{
    int source[ARRAYSIZE], count, i;
    while( scanf("%d", &count) != -1)
    {
        for(i = 0; i < count; i++)
        {
            scanf("%d", &source[i]);
        }
        findMaxMin(source, count);
    }
    return 0;
}

