/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int mx = 1e5 + 5;
int parent[mx][18], start[mx], finish[mx], level[mx], timer;
vector<int> edges[mx];
vector<int> nodes[mx];
void dfs(int u, int d)
{
    level[u] = d;
    start[u] = ++timer;
    nodes[d].push_back(start[u]);
    for (int v : edges[u])
    {
        dfs(v, d + 1);
    }
    finish[u] = timer;
}
void sparse_table(int n)
{
    for (int i = 1; i < 18; i++)
        for (int j = 1; j <= n; j++)
            parent[j][i] = -1;
    for (int i = 1; i < 18; i++)
    {
        for (int j = 1; j <= n; j++)
            if (parent[j][i - 1] != -1)
            {
                parent[j][i] = parent[parent[j][i - 1]][i - 1];
            }
    }
}
int move_up(int v, int p)
{
    for (int i = 17; i >= 0; i--)
    {
        if ((1 << i) <= p && parent[v][i] != -1)
        {
            v = parent[v][i];
            p -= (1 << i);
        }
    }
    if (p != 0)
        return -1;
    else
        return v;
}
vector<int> root;
int main()
{
    int i, n, q;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &parent[i][0]);
        if (parent[i][0] == 0)
        {
            parent[i][0] = -1;
            root.push_back(i);
        }
        else
            edges[parent[i][0]].push_back(i);
    }
    for (int u : root)
        dfs(u, 0);
    sparse_table(n);
    int u, v, p;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d %d", &v, &p);
        u = move_up(v, p);
        if (u == -1)
            printf("0 ");
        else
        {
            int ans;
            auto it1 = lower_bound(nodes[level[v]].begin(), nodes[level[v]].end(), start[u]);
            auto it2 = upper_bound(nodes[level[v]].begin(), nodes[level[v]].end(), finish[u]);
            ans = (it2 - it1) - 1;
            printf("%d ", ans);
        }
    }

    return 0;
}
