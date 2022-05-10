#include <bits/stdc++.h>
using namespace std;

int m, n, k, ara[19][19], sat[19];
long long DP[1 << 18 + 2][19];

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

long long kefa_dishes(int mask, int x)
{
    if (DP[mask][x] != -1)
        return DP[mask][x];

    vector<int> zeros;
    int i, j, p = 0;
    long long ans, temp;

    for (i = 0; i < n; i++)
    {
        if (chkbit(mask, i))
            p++;
        else
            zeros.push_back(i);
    }

    if (p == m)
        return DP[mask][x] = 0;
    else
    {
        p = zeros.size();
        ans = -1;
        for (i = 0; i < p; i++)
        {
            j = zeros[i];
            temp = ara[x][j] + sat[j] + kefa_dishes(setbit(mask, j), j);
            ans = max(ans, temp);
        }
        return DP[mask][x] = ans;
    }
}

int main()
{
    int i, u, v, w;
    long long ans;

    scanf("%d %d %d", &n, &m, &k);
    for (i = 0; i < n; i++)
        scanf("%d", &sat[i]);
    for (i = 0; i < k; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        ara[u - 1][v - 1] = w;
    }
    memset(DP, -1, sizeof(DP));
    ans = kefa_dishes(0, 18);
    printf("%lld", ans);

    return 0;
}
