#include<stdio.h>
#include<string.h>

#define M 1024
#define N 1024

static int c[M+1][N+1];

//traceback
void printLCS(char *a, char *b, int n, int m)
{
    int i = n, j = m, q = 0;
    char lcs[M];
    while(i > 0 && j > 0)
    {
        if( a[i+1] == b[j+1] )
        {
            lcs[q++] = b[j];
            i--;
            j--;
        }
        else
        {
            if( c[i-1][j] > c[i][j-1])
                i--;
            else
                j--;
        }
    }
    while(q >= 0 )
    {
        printf("%c", lcs[q--]);
    }
    printf("\n");
}

void lcs(char *a, char *b, int n, int m)
{
    int i, j;
    for(i = 0; i <= n;i++)
    {
       c[i][0] = 0;
    }
    for(j = 0; j <= m;j++)
    {
        c[0][j] = 0;
    }

    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= m; j++)
        {
            if ( a[i-1] == b[j-1] )
                c[i][j] = c[i-1][j-1] + 1;
            else
            {
                if ( c[i-1][j] > c[i][j-1] )
                   c[i][j] = c[i-1][j];
                else
                    c[i][j] = c[i][j-1];
            }
        }
    }
  //  printLCS(a, b, n, m);
}


int main()
{
    char a[M], b[N];
    int len_a, len_b;
    while( scanf("%s%s", a, b) != EOF )
    {
        len_a = 0;
        len_b = 0;
        while(a[len_a] != '\0')
        {
            len_a++;
        }
        while(b[len_b] != '\0')
        {
            len_b++;
        }
        lcs(a,b, len_a,len_b);
        printf("%d\n", c[len_a][len_b] );
    }
    return 0;
}

