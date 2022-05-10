/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;
vector<int> edges[mx];
bool vis[mx];
int parent[mx][18], level[mx];
void dfs(int u, int d)
{
    vis[u] = true;
    level[u] = d;
    for (int v : edges[u])
    {
        if (!vis[v])
        {
            dfs(v, d + 1);
            parent[v][0] = u;
        }
    }
}
void sparse_table(int n)
{
    dfs(1, 0);
    parent[1][0] = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; (1 << j) < n; j++)
            parent[i][j] = -1;
    }
    for (int j = 1; (1 << j) < n; j++)
    {
        for (int i = 1; i <= n; i++)
            if (parent[i][j - 1] != -1)
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
    }
}
int lca(int u, int v)
{
    if (level[u] < level[v])
        swap(u, v);
    for (int i = 17; i >= 0; i--)
        if (level[u] - (1 << i) >= level[v])
        {
            u = parent[u][i];
        }
    if (u == v)
        return u;
    for (int i = 17; i >= 0; i--)
    {
        if (parent[u][i] != -1 && parent[v][i] != parent[u][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}
int main()
{
    int i, n, q;

    scanf("%d %d", &n, &q);
    for (i = 2; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        edges[i].push_back(x);
        edges[x].push_back(i);
    }
    sparse_table(n);
    int a, b, c, x, y, z;
    while (q--)
    {
        scanf("%d %d %d", &a, &b, &c);
        int ans;
        x = lca(a, b);
        y = lca(b, c);
        z = lca(c, a);
        if (x == y && x == z)
        {
            ans = level[a] - level[x] + 1;
            ans = max(ans, level[b] - level[x] + 1);
            ans = max(ans, level[c] - level[x] + 1);
        }
        else
        {
            if (x == y)
            {
                ans = level[c] - level[z] + 1;
                ans = max(ans, level[a] - level[z] + 1);
                ans = max(ans, level[b] - level[x] + level[z] - level[x] + 1);
            }
            else if (y == z)
            {
                ans = level[a] - level[x] + 1;
                ans = max(ans, level[b] - level[x] + 1);
                ans = max(ans, level[c] - level[y] + level[x] - level[y] + 1);
            }
            else
            {
                ans = level[b] - level[y] + 1;
                ans = max(ans, level[c] - level[y] + 1);
                ans = max(ans, level[a] - level[x] + level[y] - level[x] + 1);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
