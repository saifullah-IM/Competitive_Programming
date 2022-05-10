#include <bits/stdc++.h>
using namespace std;

vector<int> edges[100005];
int DP[100005];
long long ans;

int dfs(int u)
{
    if (DP[u] != 0)
        return DP[u];

    int i, v;
    long long n;
    n = edges[u].size();
    for (i = 0; i < n; i++)
    {
        v = edges[u][i];
        if (v < u)
            DP[u] = max(DP[u], dfs(v));
    }
    DP[u] += 1;
    ans = max(ans, n * DP[u]);

    return DP[u];
}

int main()
{
    int i, m, n, u, v;

    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    for (i = n; i > 0; i--)
        if (DP[i] == 0)
            dfs(i);
    printf("%lld", ans);

    return 0;
}
