#include <stdio.h>
int main()
{
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);
    char ara[n];
    scanf(" %[01]", ara);
    if (ara[a - 1] == ara[b - 1])
        printf("0");
    else
    {
        printf("1");
    }
    return 0;
}