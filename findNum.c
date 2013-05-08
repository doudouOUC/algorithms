#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int A[], int p, int r)
{
    int x, i, j;
    x = A[r];
    i = p-1;
    for(j = p; j < r; j++)
    {
        if(A[j]< x)
        {
            i +=1;
            swap(&A[j], &A[i]);
        }
    }
    swap(&A[i+1], &A[r]);
    return i+1;
}

int randomized_partition(int A[], int p, int r)
{
    int randNum;
    srand( (unsigned int)time(0) );
    randNum = rand()%r + p;
    swap(&A[randNum], &A[r]);
    return partition(A, p ,r);
}

int randomized_select(int A[], int p, int r, int i)
{
    int q, k;
    if( p == r )
        return A[p];
    q = randomized_partition(A,p,r);
    k = q-p+1;
    if( k == i)
        return A[q];
    if ( i < k )
        return randomized_select(A, p, q-1, i);
    else
        return randomized_select(A, q + 1, r, i-k);
}

int main()
{
    int source[10], num,i;
    for(i=0;i<10;i++)
        scanf("%d", &source[i]);
    printf("the num you want\n");
    scanf("%d", &num);
    printf("%d", randomized_select(source,0, 9, num));
    return 0;
}

