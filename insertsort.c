#include<stdio.h>

#define SIZE 50

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void insertSort(int sort[], int n)
{
    int i, j, key;
    for( i = 1; i < n; i++ )
    {
        j = i - 1;
        key = sort[i];
        while( j >= 0 && sort[j] > key )
        {
            swap(&sort[j], &sort[j+1]);
            j--;
        }
        sort[j+1] = key;
    }
}

int main()
{
    int source[50];
    int i, sum;
    while(  scanf("%d", &sum) != -1 )
    {
        for(i = 0; i < sum; i ++)
        {
            scanf("%d", &source[i]);
        }
        insertSort(source, sum);
        printf("%d\n", sum);
        for(i = 0; i < sum; i++)
        {
            printf("%d  ", source[i]);
        }
        printf("\n");
    }
    return 0;
}

