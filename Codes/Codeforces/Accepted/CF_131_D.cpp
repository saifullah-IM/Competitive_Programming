#include <bits/stdc++.h>
using namespace std;

vector<int> edges[3005];
vector<int> cycle;
vector<int> rec;

bool vis[3005], chk[3005];
int ans[3005];

void dfs(int u, int p)
{
    if (vis[u])
    {
        if (cycle.empty())
        {
            int i, n, x;
            n = rec.size();
            for (i = n - 1; i >= 0; i--)
            {
                x = rec[i];
                cycle.push_back(x);
                ans[x] = 0;
                if (x == u)
                    break;
            }
        }
        return;
    }

    vis[u] = true;
    rec.push_back(u);

    int i, v, n;
    n = edges[u].size();
    for (i = 0; i < n; i++)
    {
        v = edges[u][i];
        if (v != p)
            dfs(v, u);
    }

    rec.pop_back();
}

void bfs()
{
    queue<int> myQ;
    int i, u, v, n;

    n = cycle.size();
    for (i = 0; i < n; i++)
        myQ.push(cycle[i]);

    while (!myQ.empty())
    {
        u = myQ.front();
        myQ.pop();
        n = edges[u].size();
        for (i = 0; i < n; i++)
        {
            v = edges[u][i];
            if (ans[v] == -1)
            {
                ans[v] = 1 + ans[u];
                myQ.push(v);
            }
        }
    }
}

int main()
{
    int i, n, u, v;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    memset(ans, -1, sizeof(ans));
    rec.clear();
    dfs(1, 0);
    bfs();
    for (i = 1; i <= n; i++)
        printf("%d ", ans[i]);

    return 0;
}
