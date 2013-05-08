#include<stdio.h>

void changeChar(char *a)
{
    *a = 'a';
}

int main()
{
    /*
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("%d %d", (int)a, (int)b);
    */
    /*
    int a;
    while( scanf("%d", &a) )
    {
        if( 10< a <10)
            printf("5<a<10");
        else
           printf("not");
    }
    */

    char *a;
    scanf("%s", a);

    /*
    char *a = "hello, world";
    changeChar(a);
    printf("after change a is %s, %d, %d\n", a, *a, 'h');
    */

    return 0;
}

