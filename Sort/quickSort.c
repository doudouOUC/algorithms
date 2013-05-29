#include<stdio.h>

int swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int sort[], int p, int r)
{
    int guard = sort[r], i, j;
    i = p - 1;
    for(j = p; j < r; j++)
    {
        if( sort[j] <= guard )
        {
            i = i+1;
            swap( &sort[j], &sort[i]);
        }
    }
    swap(&sort[i+1], &sort[r]);
    return i+1;
}

void quickSort(int sort[], int p, int r)
{
    int q;
    if( p < r )
    {
        q = partition(sort, p, r);
        quickSort(sort, p, q-1);
        quickSort(sort, q+1, r);
    }
}

int main()
{
    int source[50], sum,i;
    while(  scanf("%d", &sum) != -1 )
    {
        for(i = 0; i < sum; i ++)
        {
            scanf("%d", &source[i]);
        }
        quickSort(source, 0, sum-1);
        printf("%d\n", sum);
        for(i = 0; i < sum; i++)
        {
            printf("%d  ", source[i]);
        }
        printf("\n");
    }
}
