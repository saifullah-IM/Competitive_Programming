#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A[100], B[100], n, ans, i, A1[5], B1[5], x, ck = 1;

    memset(A1, 0, sizeof(A1));
    memset(B1, 0, sizeof(B1));
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
        A1[A[i] - 1]++;
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &B[i]);
        B1[B[i] - 1]++;
    }

    ans = 0;
    for (i = 0; i < 5; i++)
    {
        x = fabs(A1[i] - B1[i]);
        if (x % 2 == 1)
        {
            ck = 0;
            break;
        }
        else
            ans += x / 2;
    }

    if (ck)
    {
        if (ans % 2 == 0)
            printf("%d", ans / 2);
        else
            printf("-1");
    }
    else
        printf("-1");

    return 0;
}
