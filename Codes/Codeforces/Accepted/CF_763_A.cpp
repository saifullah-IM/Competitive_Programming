#include <bits/stdc++.h>
using namespace std;

vector<int> edges[100005];
int x, y, color[100005];
bool vis[100005];

void DFS(int u)
{
    if (vis[u])
        return;
    vis[u] = true;

    int i, n, v;
    n = edges[u].size();
    for (i = 0; i < n; i++)
    {
        v = edges[u][i];
        if (color[u] != color[v])
        {
            x = u;
            y = v;
            return;
        }
        else
            DFS(v);
    }
}

bool dfs(int u, int c)
{
    if (vis[u])
        return true;
    vis[u] = true;
    if (c != color[u])
        return false;

    int i, m, v;
    bool ans = true;
    m = edges[u].size();
    for (i = 0; i < m; i++)
    {
        v = edges[u][i];
        ans = (ans & dfs(v, c));
        if (!ans)
            break;
    }
    return ans;
}

int main()
{
    int i, n, m, k, u, v, w;
    bool ans;

    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (i = 1; i <= n; i++)
        scanf("%d", &color[i]);

    x = y = -1;
    DFS(1);
    if (x == -1 && y == -1)
    {
        printf("YES\n");
        printf("1");
        return 0;
    }
    else
    {
        m = edges[x].size();
        memset(vis, 0, sizeof(vis));
        ans = vis[x] = true;
        for (i = 0; i < m; i++)
        {
            u = edges[x][i];
            k = color[u];
            ans = (ans & dfs(u, k));
            if (!ans)
                break;
        }

        if (ans)
        {
            printf("YES\n");
            printf("%d", x);
            return 0;
        }

        m = edges[y].size();
        memset(vis, 0, sizeof(vis));
        ans = vis[y] = true;
        for (i = 0; i < m; i++)
        {
            u = edges[y][i];
            k = color[u];
            ans = (ans & dfs(u, k));
            if (!ans)
                break;
        }

        if (ans)
        {
            printf("YES\n");
            printf("%d", y);
            return 0;
        }
    }
    printf("NO");

    return 0;
}
