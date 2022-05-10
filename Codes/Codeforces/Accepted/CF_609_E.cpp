/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<PII, PII> PPI;
const int mx = 2e5 + 5;
vector<PII> mst[mx];
PPI edges[mx];
int path[mx];
ll cost;
bool chk[mx];

int Find(int u)
{
    if (path[u] == u)
        return u;
    else
        return path[u] = Find(path[u]);
}

void kruskal(int n, int m)
{
    sort(edges, edges + m);
    for (int i = 1; i <= n; i++)
        path[i] = i;

    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v, w, p, q;
        u = edges[i].second.first;
        v = edges[i].second.second;
        w = edges[i].first.first;
        p = Find(u);
        q = Find(v);
        if (p != q)
        {
            path[p] = q;
            mst[u].push_back(PII(v, w));
            mst[v].push_back(PII(u, w));
            ++cnt;
            chk[i] = true;
            cost += w;
            if (cnt == n - 1)
                break;
        }
    }
}

bool vis[mx];
int lg, D, parent[mx][20], maxi[mx][20], level[mx];
void dfs(int u, int d)
{
    vis[u] = true;
    level[u] = d;
    D = max(D, d);

    int i, m;
    m = mst[u].size();
    for (i = 0; i < m; i++)
    {
        int v, w;
        v = mst[u][i].first;
        w = mst[u][i].second;
        if (!vis[v])
        {
            parent[v][0] = u;
            maxi[v][0] = w;
            dfs(v, d + 1);
        }
    }
}

void sparse_table(int n)
{
    D = 0;
    dfs(1, 0);

    for (lg = 1; (1 << lg) <= D; lg++)
        ;
    lg--;
    parent[1][0] = -1, maxi[1][0] = 0;
    for (int i = 1; i <= lg; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            parent[j][i] = -1;
            maxi[j][i] = 0;
        }
    }

    for (int i = 1; i <= lg; i++)
    {
        for (int j = 1; j <= n; j++)
            if (parent[j][i - 1] != -1)
            {
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
                maxi[j][i] = max(maxi[j][i - 1], maxi[parent[j][i - 1]][i - 1]);
            }
    }
}

int solve(int u, int v)
{
    int ans = 0;
    if (level[u] < level[v])
        swap(u, v);
    for (int i = lg; i >= 0; i--)
    {
        if (level[u] - (1 << i) >= level[v])
        {
            ans = max(ans, maxi[u][i]);
            u = parent[u][i];
        }
    }
    if (u == v)
        return ans;

    for (int i = lg; i >= 0; i--)
    {
        if (parent[u][i] != -1 && parent[u][i] != parent[v][i])
        {
            ans = max(ans, max(maxi[u][i], maxi[v][i]));
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    ans = max(ans, max(maxi[u][0], maxi[v][0]));
    return ans;
}

ll ans[mx];
int main()
{
    int cs, i, j, n, m;
    int u, v, w;

    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = PPI(PII(w, i), PII(u, v));
    }
    kruskal(n, m);
    sparse_table(n);

    for (i = 0; i < m; i++)
    {
        j = edges[i].first.second;
        if (chk[i])
            ans[j] = cost;
        else
        {
            ll temp;
            temp = solve(edges[i].second.first, edges[i].second.second);
            ans[j] = cost - temp + edges[i].first.first;
        }
    }
    for (i = 0; i < m; i++)
        printf("%lld\n", ans[i]);

    return 0;
}
