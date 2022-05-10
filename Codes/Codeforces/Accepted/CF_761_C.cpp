#include <bits/stdc++.h>
#define inf 10000000
using namespace std;

int setbit(int m, int i)
{
    int mask = 1 << i;
    return mask | m;
}

bool chkbit(int m, int i)
{
    int mask = 1 << i;
    return (bool)(mask & m);
}

char str[55][55];
int n, m, ara[55][3], DP[55][8];

int password(int i, int mask)
{
    if (mask == 7)
        return 0;
    if (i == n)
        return inf;
    if (DP[i][mask] != -1)
        return DP[i][mask];

    int j, ans = inf;
    for (j = 0; j < 3; j++)
        if (!chkbit(mask, j))
        {
            ans = min(ans, ara[i][j] + password(i + 1, setbit(mask, j)));
        }
    ans = min(ans, password(i + 1, mask));

    return DP[i][mask] = ans;
}

int main()
{
    int i, j, u, ans;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%s", str[i]);

    memset(ara, 63, sizeof(ara));
    memset(DP, -1, sizeof(DP));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            u = min(j, m - j);
            if (str[i][j] >= '0' && str[i][j] <= '9')
                ara[i][0] = min(u, ara[i][0]);
            else if (str[i][j] >= 'a' && str[i][j] <= 'z')
                ara[i][1] = min(u, ara[i][1]);
            else
                ara[i][2] = min(u, ara[i][2]);
        }

    ans = password(0, 0);
    printf("%d", ans);

    return 0;
}
