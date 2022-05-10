#include <bits/stdc++.h>
using namespace std;

bool chk[1005][1005][5];
int n, k, DP[1005];

int gargari_perm(int i)
{
    if (DP[i] != -1)
        return DP[i];

    int j, l, u, ans;
    bool ck;

    ans = 1;
    for (j = 1; j <= n; j++)
        if (chk[i][j][0])
        {
            ck = true;
            for (l = 1; l < k; l++)
                if (!chk[i][j][l])
                {
                    ck = false;
                    break;
                }
            if (ck)
            {
                ans = max(ans, 1 + gargari_perm(j));
            }
        }

    return DP[i] = ans;
}

int main()
{
    int i, j, l, ara[1005], ans;

    memset(DP, -1, sizeof(DP));
    scanf("%d %d", &n, &k);
    for (j = 0; j < k; j++)
    {
        for (i = 0; i < n; i++)
            scanf("%d", &ara[i]);
        DP[ara[n - 1]] = 1;
        for (i = 0; i < n; i++)
        {
            for (l = i + 1; l < n; l++)
            {
                chk[ara[i]][ara[l]][j] = true;
            }
        }
    }

    ans = -1;
    for (i = 1; i <= n; i++)
        ans = max(ans, gargari_perm(i));
    printf("%d", ans);

    return 0;
}
