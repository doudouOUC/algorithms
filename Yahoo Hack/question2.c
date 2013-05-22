#include <stdio.h>
#include<math.h>

static int cycle[5000] = {0};

int isCycle(int count)
{
    int i, mid;
    mid = (count+1)/2;
	for(i=0;i< mid;i++)
    {
    	if(cycle[i] != cycle[mid+i])
            return i;
    }
    return 0;
}

int isHasDigit(int d, int n_cycle)
{
	int i;
    for(i=0;i<n_cycle;i++)
    {
    	if(cycle[i]==d)
            return 1;
    }
    return 0;
}

int findtheNum(int a, int b, int m, int d)
{
	int n_cycle = 0, digitNum = 0;
    int is_zhengchu = 0;
    while(1)
    {
        if( a<b )
        {
        	a = a*10;
        }
        cycle[n_cycle] = a/b;
        a = a%b;
        if(a==0)
        {
        	//zhengchu
            is_zhengchu = 1;
            break;
        }
        if( (n_cycle+1)%2 == 0)
        {
        	if(isCycle(n_cycle))
            {
                //find cycle
            	break;
            }
        }
        n_cycle++;
    }
    /*
    if( !is_zhengchu )
        n_cycle = (n_cycle+1)/2;
    digitNum = isHasDigit(d, n_cycle);
    if(!digitNum)
        return 0;
    return m*n_cycle +digitNum;
    */
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int count, i, a, b, m, d;
    scanf("%d", &count);
    for( i=0; i<count; i++)
    {
    	scanf("%d %d %d %d", &a, &b, &m, &d);
        printf("%d\n", findtheNum(a, b, m, d));
    }
    return 0;
}
