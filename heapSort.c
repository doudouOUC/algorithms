#include<stdio.h>

#define LEFT(i)  (2*i)
#define RIGHT(i) (2*i+1)

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify(int heap[], int i, int heapSize)
{
    int l, r, largest;
    l = LEFT(i);
    r = RIGHT(i);
    if( l <= heapSize && heap[l] > heap[i] )
        largest = l;
    else
        largest = i;
    if ( r <= heapSize && heap[r] > heap[largest])
        largest = r;
    if( largest != i )
    {
        swap(&heap[i], &heap[largest]);
        maxHeapify(heap, largest, heapSize);
    }
}

void buildMaxHeap(int heap[], int length)
{
    int i, heapSize = length;
    for(i = length/2 ; i >0 ; i--)
    {
        maxHeapify(heap, i, heapSize);
    }
}

void heapSort(int heap[], int length)
{
    int i, heapSize = length;
    buildMaxHeap(heap, length);
    for(i = length; i > 1; i--)
    {
        swap( &heap[1], &heap[i]);
        heapSize = heapSize - 1;
        maxHeapify(heap, 1, heapSize);
    }
}


int main()
{
    int source[100];
    int i, sum;
    while(  scanf("%d", &sum) != -1 )
    {
        // from 1 to n
        for(i = 1; i < sum+1; i ++)
        {
            scanf("%d", &source[i]);
        }
        heapSort(source, sum);
        printf("%d\n", sum);
        for(i = 1; i < sum+1; i++)
        {
            printf("%d  ", source[i]);
        }
        printf("\n");
    }
    return 0;
}
