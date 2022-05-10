#include <bits/stdc++.h>
using namespace std;

long long ans;
bool vis[50005];
int m, k, t, DP[50005][505];
vector<int> edges[50005];

bool dfs(int u)
{
    if (vis[u])
        return false;
    vis[u] = true;
    DP[u][0] = 1;

    int i, j, v, n;
    bool chk;
    n = edges[u].size();
    for (i = 0; i < n; i++)
    {
        v = edges[u][i];
        chk = dfs(v);
        if (chk)
        {
            for (j = 0; j < t; j++)
            {
                ans += (long long)DP[u][j] * (long long)DP[v][k - j - 1];
                if (j != k - j - 1)
                    ans += (long long)DP[v][j] * (long long)DP[u][k - j - 1];
            }
            for (j = 0; j <= m; j++)
            {
                if (j > 0)
                    DP[u][j] += DP[v][j - 1];
                if (k > j && j != k - j)
                    DP[u][k - j] += DP[v][k - j - 1];
            }
        }
    }

    return true;
}

int main()
{
    int i, n, u, v;

    scanf("%d %d", &n, &k);
    for (i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    m = k / 2;
    t = (k + 1) / 2;
    dfs(1);
    printf("%lld", ans);
    //cout<<DP[3][1];

    return 0;
}
