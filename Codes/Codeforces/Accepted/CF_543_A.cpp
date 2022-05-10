#include <bits/stdc++.h>
using namespace std;

int ara[502], DP[502][502], mod, m, n, b;

int main()
{
    int i, j, k, ans = 0;

    scanf("%d %d %d %d", &n, &m, &b, &mod);
    for (i = 0; i < n; i++)
        scanf("%d", &ara[i]);

    DP[0][0] = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            for (k = 0; k <= b; k++)
            {
                if (k >= ara[i])
                    DP[j][k] = (DP[j][k] + DP[j - 1][k - ara[i]]) % mod;
            }
        }
    }

    for (i = 0; i <= b; i++)
        ans = (ans + DP[m][i]) % mod;
    printf("%d", ans);

    return 0;
}
