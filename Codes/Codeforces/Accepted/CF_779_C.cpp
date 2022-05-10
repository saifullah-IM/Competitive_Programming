#include <bits/stdc++.h>
using namespace std;

int A[200000], B[200000], dif[200000];
int main()
{
    int n, k, d, i, j, ans = 0, x;

    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &B[i]);
        ans += B[i];
    }

    j = 0;
    x = 0;
    for (i = 0; i < n; i++)
    {
        d = A[i] - B[i];
        if (d < 0)
        {
            ans += d;
            x++;
        }
        else
            dif[j++] = d;
    }

    x = k - x;
    if (x > 0)
    {
        sort(dif, dif + j);
        for (i = 0; i < x; i++)
            ans += dif[i];
    }

    printf("%d", ans);

    return 0;
}
