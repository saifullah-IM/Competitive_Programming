#include <bits/stdc++.h>
using namespace std;

int m, n, ara[50010][6], DP[50010][6], ans[50010];

void art_union(int j)
{
    if (j > n)
        return;

    int i;
    for (i = 1; i <= m; i++)
        DP[i][j] = ara[i][j] + max(DP[i - 1][j], DP[i][j - 1]);

    art_union(j + 1);
}

int main()
{
    int i, j;

    scanf("%d %d", &m, &n);
    for (i = 1; i <= m; i++)
    {
        DP[i][0] = 0;
        for (j = 1; j <= n; j++)
            scanf("%d", &ara[i][j]);
    }
    for (j = 1; j <= n; j++)
        DP[0][j] = 0;

    art_union(1);
    for (i = 1; i <= m; i++)
        printf("%d\n", DP[i][n]);

    return 0;
}
