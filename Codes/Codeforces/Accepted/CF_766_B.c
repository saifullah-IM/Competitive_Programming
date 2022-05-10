#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int i, n, x, y;
    scanf("%d", &n);
    int ara[n];

    for (i = 0; i < n; i++)
        scanf("%d", &ara[i]);
    qsort(ara, n, sizeof(int), compare);

    y = n - 2;
    x = 0;
    for (i = 0; i < y; i++)
    {
        if (ara[i] + ara[i + 1] > ara[i + 2])
        {
            x = 1;
            break;
        }
    }

    if (x)
        printf("YES");
    else
        printf("NO");

    return 0;
}
