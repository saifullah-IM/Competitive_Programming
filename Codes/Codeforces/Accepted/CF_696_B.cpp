/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 100005;
int cnt[mx];
double ans[mx];
vector<int> edges[mx];

int dfs(int u)
{
    cnt[u] = 1;
    int i, m, v;

    m = edges[u].size();
    for (i = 0; i < m; i++)
    {
        v = edges[u][i];
        cnt[u] += dfs(v);
    }
    return cnt[u];
}

void solve(int u)
{
    int i, m, v;

    m = edges[u].size();
    for (i = 0; i < m; i++)
    {
        v = edges[u][i];
        ans[v] = ans[u] + 1.0 + ((cnt[u] - cnt[v] - 1) * 1.0) / 2.0;
        solve(v);
    }
}

int main()
{
    int i, n, u;

    scanf("%d", &n);
    for (i = 2; i <= n; i++)
    {
        scanf("%d", &u);
        edges[u].push_back(i);
    }
    dfs(1);
    ans[1] = 1.0;
    solve(1);
    for (i = 1; i <= n; i++)
        printf("%lf ", ans[i]);

    return 0;
}
