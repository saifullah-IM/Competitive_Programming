#include <bits/stdc++.h>
#define PII pair<int, int>
#define inf 2000000000
using namespace std;

int ans, nodes[100005];
vector<PII> edges[100005];
bool vis[100005];

void dfs(int u, long long dis, bool chk)
{
    if (vis[u])
        return;
    vis[u] = true;
    if (dis > nodes[u] || chk)
    {
        chk = true;
        ans++;
    }

    int i, n, v;
    long long k;
    PII A;
    n = edges[u].size();
    for (i = 0; i < n; i++)
    {
        A = edges[u][i];
        v = A.first;
        k = A.second;
        if (dis > 0)
            k += dis;
        dfs(v, k, chk);
    }
}

int main()
{
    int i, n, u, w;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &nodes[i]);
    for (i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &w);
        edges[i + 1].push_back(make_pair(u, w));
        edges[u].push_back(make_pair(i + 1, w));
    }
    dfs(1, -inf, false);
    printf("%d", ans);

    return 0;
}
