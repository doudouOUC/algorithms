#include<stdio.h>

#define SIZE 50

void printArray(int a[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
// a[p - q] a[q+1 r]
void merge(int sort[], int p, int q, int s)
{
    int n1, n2, i, j, k, l[20],r[20];
    n1 = q - p + 1;
    n2 = s - q;
    for( i = 0; i < n1;i++)
    {
        l[i] = sort[p+i];
    }
    for( j = 0; j < n2 ; j++)
        r[j] = sort[q+1+j];
    i = j = 0;
    k = p;
    while( i < n1 && j < n2)
    {
        if( l[i] < r[j])
        {
            sort[k++] = l[i++];
        }
        else
        {
            sort[k++] = r[j++];
        }
    }
    if( i == n1 )
    {
        for(; j < n2; j++)
            sort[k++] = r[j];
    }
    else if ( j == n2 )
    {
        for(;i<n1;i++)
            sort[k++] = l[i];
    }
}

void mergeSort(int sort[], int start, int end)
{
    if( start < end )
    {
        int mid = (start + end)/2;
        mergeSort(sort, start, mid);
        mergeSort(sort, mid+1, end);
        merge(sort, start, mid, end);
    }
}

int main()
{
   int i, sum, source[SIZE];
   while( scanf("%d", &sum) != -1)
   {
        for( i = 0; i < sum ; i++ )
        {
            scanf("%d", &source[i]);
        }
        mergeSort(source, 0, sum -1);
        for(i = 0; i < sum; i++)
        {
            printf("%d  ", source[i]);
        }
        printf("\n");
   }
}
