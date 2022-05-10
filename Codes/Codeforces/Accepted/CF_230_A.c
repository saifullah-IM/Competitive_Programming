#include <stdio.h>
int main()
{
    int i, s, n, max = 0, count;
    scanf("%d %d", &s, &n);
    int X[n], Y[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &X[i], &Y[i]);
        if (s > X[i])
        {
            s += Y[i];
            Y[i] = 0;
            continue;
        }
        if (X[i] > max)
            max = X[i];
    }
    if (s > max)
        printf("YES");
    else
    {
        while (1)
        {
            for (i = 0, count = 0; i < n; i++)
            {
                if (Y[i] == 0)
                    continue;
                if (s > X[i])
                {
                    s += Y[i];
                    Y[i] = 0;
                    count++;
                }
            }
            if (s > max)
            {
                printf("YES");
                break;
            }
            if (count == 0)
            {
                printf("NO");
                break;
            }
        }
    }
    return 0;
}