#include <bits/stdc++.h>
using namespace std;

vector<int> tree[100005];
vector<int> ans;
int crnt[100005], goal[100005];
bool flag[2], vis[100005];

void dfs(int u, int k)
{
    if (vis[u])
        return;
    vis[u] = true;

    int i, v, n;
    bool ck = false;
    n = tree[u].size();

    if (flag[k])
        v = crnt[u] ^ 1;
    else
        v = crnt[u];

    if (v != goal[u])
    {
        ans.push_back(u);
        flag[k] ^= 1;
        ck = true;
    }

    for (i = 0; i < n; i++)
    {
        v = tree[u][i];
        dfs(v, k ^ 1);
    }

    if (ck)
        flag[k] ^= 1;
}

int main()
{
    int i, n, u, v;

    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    for (i = 1; i <= n; i++)
        scanf("%d", &crnt[i]);
    for (i = 1; i <= n; i++)
        scanf("%d", &goal[i]);
    dfs(1, 0);
    u = ans.size();
    printf("%d\n", u);
    for (i = 0; i < u; i++)
    {
        v = ans[i];
        printf("%d\n", v);
    }

    return 0;
}
