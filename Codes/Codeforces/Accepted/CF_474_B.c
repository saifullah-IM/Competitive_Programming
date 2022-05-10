#include <stdio.h>
int main()
{
    int m, n, i, a, start, mid, end;
    scanf("%d", &n);
    int W[n + 1];
    W[0] = 0;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        W[i] = W[i - 1] + a;
    }
    scanf("%d", &m);
    int J[m];
    for (i = 0; i < m; i++)
    {
        scanf("%d", &J[i]);
    }
    for (i = 0; i < m; i++)
    {
        start = 0;
        end = n;
        while (1)
        {
            mid = (start + end) / 2;
            if (J[i] > W[mid] && J[i] <= W[mid + 1])
            {
                J[i] = mid + 1;
                break;
            }
            if (J[i] > W[mid])
                start = mid + 1;
            else
                end = mid - 1;
        }
        printf("%d\n", J[i]);
    }
    return 0;
}
