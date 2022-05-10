#include <stdio.h>

int main()
{
    int n, l, i, j, k, m, S, ck;
    scanf("%d %d", &n, &l);
    int A[n], B[n], X[n], Y[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &B[i]);
    }

    S = 0;
    for (i = 1; i < n; i++)
    {
        X[i - 1] = A[i] - A[i - 1];
        S += X[i - 1];
    }
    X[n - 1] = l - S;

    S = 0;
    for (i = 1; i < n; i++)
    {
        Y[i - 1] = B[i] - B[i - 1];
        S += Y[i - 1];
    }
    Y[n - 1] = l - S;

    for (j = 0; j < n; j++)
    {
        if (X[0] == Y[j])
        {
            k = 1;
            m = j + 1;
            ck = 1;
            while (k < n)
            {
                if (m == n)
                    m = 0;
                if (X[k] != Y[m])
                {
                    ck = 0;
                    break;
                }
                k++;
                m++;
            }
        }
        if (ck)
            break;
    }

    if (ck)
        printf("YES");
    else
        printf("NO");

    return 0;
}