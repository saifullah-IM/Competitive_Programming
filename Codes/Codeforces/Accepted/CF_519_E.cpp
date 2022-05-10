/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;
vector<int> edges[mx];
int parent[mx][18], cnt[mx], st[mx], ed[mx], timer, level[mx];
bool vis[mx];
int dfs(int u, int d)
{
    vis[u] = true;
    level[u] = d;
    st[u] = ++timer;
    cnt[u] = 1;
    for (int v : edges[u])
    {
        if (!vis[v])
        {
            parent[v][0] = u;
            cnt[u] += dfs(v, d + 1);
        }
    }
    ed[u] = ++timer;
    return cnt[u];
}
void sparse_table(int n)
{
    dfs(1, 0);
    parent[1][0] = -1;
    for (int i = 1; i < 18; i++)
        for (int j = 1; j <= n; j++)
            parent[j][i] = -1;
    for (int i = 1; (1 << i) < n; i++)
    {
        for (int j = 1; j <= n; j++)
            if (parent[j][i - 1] != -1)
            {
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
            }
    }
}
int find(int u, int v)
{
    if (level[u] < level[v])
        swap(u, v);
    int p = u;
    int q = v;
    for (int i = 17; i >= 0; i--)
    {
        if (level[u] - (1 << i) >= level[v])
        {
            u = parent[u][i];
        }
    }
    if (u == v)
    {
        int d = level[p] - level[q]; ///cout<<d<<endl;
        if (d % 2 != 0)
            return -1;
        int t = level[p] - d / 2;
        u = p;
        for (int i = 17; i >= 0; i--)
        { ///cout<<"XXX   "<<i<<"  "<<u<<endl;
            if (level[u] - (1 << i) >= t)
            { ///cout<<"BBB   "<<u<<' '<<i<<' '<<parent[u][i]<<endl;
                u = parent[u][i];
            }
            ///cout<<u<<"meeee"<<endl;
        }
        return u;
    }
    else
    {
        for (int i = 17; i >= 0; i--)
        {
            if (parent[u][i] != -1 && parent[u][i] != parent[v][i])
            { ///cout<<u<<' '<<v<<' '<<i<<endl;
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        u = parent[u][0];
        int d = level[p] + level[q] - 2 * level[u];
        if (d % 2 != 0)
            return -1;
        int t = level[p] - d / 2;
        u = p;
        for (int i = 17; i >= 0; i--)
        {
            if (level[u] - (1 << i) >= t)
            {
                u = parent[u][i];
            }
        }
        return u;
    }
}
int move(int from, int to)
{
    if (st[to] <= st[from] && ed[to] >= ed[from])
    {
        for (int i = 17; i >= 0; i--)
            if (parent[from][i] != -1 && st[to] < st[parent[from][i]])
                from = parent[from][i];
        return from;
    }
    else
        return parent[to][0];
}
int main()
{
    int i, n, q;

    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    sparse_table(n);
    scanf("%d", &q);
    while (q--)
    {
        int a, b, c, u, v;
        scanf("%d %d", &a, &b);
        if (a == b)
        {
            printf("%d\n", n);
            continue;
        }
        c = find(a, b);
        ///cout<<"mid = "<<c<<endl;
        if (c == -1)
            printf("0\n");
        else
        {
            u = move(a, c), v = move(b, c);
            int ans = n;
            if (u == parent[c][0])
                ans -= (n - cnt[c]);
            else
                ans -= cnt[u];
            if (v == parent[c][0])
                ans -= (n - cnt[c]);
            else
                ans -= cnt[v];
            printf("%d\n", ans);
        }
    }

    return 0;
}
