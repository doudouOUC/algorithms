#include<stdio.h>
#include<stdlib.h>

#define N 10

void findMaxPath(int start, int end, int grid[][N], int d[][N])
{
}

int main()
{
    int i, j, grid[N][N], start, end, d[N][N];
    srand(30);
    for(i = 0; i < N; i++)
    {
        for( j = 0; j < N; j++)
        {
            d[N][N] = 0;
            grid[i][j] = rand()%100 - 20;
            printf("%3d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("input start point");
    scanf("%d", &start);
    printf("input end point");
    scanf("%d", &end);
    findMaxPath(start, end, grid, d);
    return 0;
}

