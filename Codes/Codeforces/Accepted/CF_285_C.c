#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int sorti(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int i, n, t, j;
    long long int R;
    scanf("%d", &n);
    int ara[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ara[i]);
    }
    qsort(ara, n, sizeof(int), sorti);
    for (i = 1, R = 0; i <= n; i++)
    {
        R += fabs(ara[i - 1] - i);
    }
    printf("%I64d", R);
    return 0;
}
