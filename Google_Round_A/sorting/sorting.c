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

void sorting(int books[], int sum)
{
	int source[1000];
	int odd[1000];
	int even[1000];
	int i;
	int odd_num=0, even_num=0;
	int p=0, q=0;
	for(i=0;i<sum;i++)
	{
		source[i] = books[i];
	}
	
	for(i=0;i<sum;i++)
	{
		if( books[i]%2 ==0 )
			even[even_num++] = books[i];
		else
			odd[odd_num++] = books[i];
	}
	quickSort(even, 0, even_num-1);
	quickSort(odd, 0, odd_num-1);
	q = even_num-1;
	for(i=0;i<sum;i++)
	{
		if(source[i]%2!=0)
			books[i] = odd[p++];
		else 
			books[i] = even[q--];
	}
}

int main()
{
	int sum;
	int num = 1;
	int books[1000];
	int book_sum;
	int i;
	scanf("%d", &sum);
	while(sum)
	{
		scanf("%d", &book_sum);
		for(i=0;i<book_sum;i++)
		{
			scanf("%d", &books[i]);
		}
		sorting(books, book_sum);
		printf("Case #%d:", num);
		for(i=0;i<book_sum;i++)
		{
			printf(" %d", books[i]);
		}
		printf("\n");
		num++;
		sum--;
	}
	return 0;
}