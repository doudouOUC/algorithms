#include <stdio.h>
#include<stdlib.h>
typedef struct
{
	int begin;
    int end;
}Line;

void swap(Line *a, Line *b)
{
	Line temp;
    temp.begin = a->begin;
    temp.end = a->end;
    a->begin = b->begin;
    a->end = b->end;
    b->begin = temp.begin;
    b->end = temp.end;
}

void sortLines(Line *lines, int count)
{
    int i, j;
	for(i=0;i<count;i++)
    {
    	for(j=i+1;j<count;j++)
        {
        	if(lines[i].begin>lines[j].begin)
            {
            	swap(&lines[i], &lines[j]);
            }
        }
    }
}

int findLongestLine(Line *lines, int count)
{
    int max, i, first, temp, last;
    sortLines(lines, count);
    first = lines[0].begin;
    last = lines[0].end;
    max = lines[0].end - lines[0].begin;
    for( i=1; i<count; i++)
    {
        if(lines[i].begin > last)
        {
        	//duan kai
            temp = last - first;
            if( temp > max)
                max = temp;
            first = lines[i].begin;
            last = lines[i].end;
        }
        else
        {
        	if(lines[i].end > last)
                last = lines[i].end;
        }
    }
    return max;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int count, i, begin, end;
    Line *lines;
    while( scanf("%d", &count) != -1 )
    {
        lines = malloc( sizeof(Line)*count );
    	for(i=0; i<count;i++)
        {
        	scanf("%d %d", &lines[i].begin, &lines[i].end);
        }
        printf("%d\n", findLongestLine(lines, count));
        free(lines);
    }
    return 0;
}
