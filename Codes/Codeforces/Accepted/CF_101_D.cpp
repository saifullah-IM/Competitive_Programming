/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
#define PII pair<ll, ll>
using namespace std;

const int mx = 100005;
vector<PII> edges[mx];
PII cost[mx];
bool vis[mx];

bool sortFunction(PII A, PII B)
{
    int u, v;
    u = A.first;
    v = B.first;
    if (cost[u].second * cost[v].first == cost[u].first * cost[v].second)
        return cost[u].second < cost[v].second;
    else
        return cost[u].second * cost[v].first < cost[u].first * cost[v].second;
}

PII dfs(int u)
{
    vis[u] = true;
    int i, v, m;
    m = edges[u].size();
    PII ans, A;

    ans.second = 0;
    ans.first = 1;
    for (i = 0; i < m; i++)
    {
        v = edges[u][i].first;
        if (!vis[v])
        {
            A = dfs(v);
            ans.first += A.first;
            ans.second += A.second + edges[u][i].second;
            cost[v].second += edges[u][i].second;
        }
    }
    sort(edges[u].begin(), edges[u].end(), sortFunction);
    return cost[u] = ans;
}

ll Tm, dist[mx];
void solve(int u)
{
    vis[u] = true;
    int i, v, m;
    m = edges[u].size();

    for (i = 0; i < m; i++)
    {
        v = edges[u][i].first;
        if (!vis[v])
        {
            Tm += edges[u][i].second;
            dist[v] = Tm;
            solve(v);
            Tm += edges[u][i].second;
        }
    }
}

int main()
{
    int i, n, u, v, w;
    ll sum;
    double ans;

    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        edges[u].push_back(make_pair(v, w));
        edges[v].push_back(make_pair(u, w));
    }
    dfs(1);
    memset(vis, 0, sizeof(vis));
    solve(1);
    sum = 0;
    for (i = 2; i <= n; i++)
        sum += dist[i];
    ans = (sum * 1.0) / ((n - 1) * 1.0);
    printf("%lf\n", ans);

    return 0;
}
