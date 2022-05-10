#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

struct road
{
    int u, w, x;
};
struct node
{
    int u, id;
    long long dis;
    node(int a, int b, long long c) { u = a, id = b, dis = c; }
};

vector<road> edges[100005];
int tren[100005], path[100005];
long long dist[100005];
auto comp = [](node A, node B)
{
    if (A.dis == B.dis)
        return A.id < B.id;
    return A.dis > B.dis;
};
priority_queue<node, vector<node>, decltype(comp)> myPQ(comp);
bool vis[100005];
void dijkstra()
{
    memset(dist, 63, sizeof(dist));
    dist[1] = 0;

    int i, n;
    long long w;
    myPQ.push(node(1, 0, 0));

    while (!myPQ.empty())
    {
        auto it = myPQ.top();
        myPQ.pop();
        int u = it.u;
        if (vis[u])
            continue;
        vis[u] = true;
        n = edges[u].size();
        for (i = 0; i < n; i++)
        {
            int v = edges[u][i].u;
            w = dist[u] + edges[u][i].w;
            if (w == dist[v])
                path[v] = max(path[v], path[u] + edges[u][i].x);
            if (w < dist[v])
            {
                path[v] = path[u] + edges[u][i].x;
                dist[v] = w;
                myPQ.push(node(v, path[v], w));
            }
        }
    }
}

int main()
{
    int i, n, m, k, u, v, w, ans;
    road A;

    scanf("%d %d %d", &n, &m, &k);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        A.w = w;
        A.x = 2;
        A.u = v;
        edges[u].push_back(A);
        A.u = u;
        edges[v].push_back(A);
    }

    for (i = 0; i < k; i++)
    {
        scanf("%d %d", &u, &w);
        tren[u]++;
        A.u = u;
        A.w = w;
        A.x = 1;
        edges[1].push_back(A);
    }

    dijkstra();
    ans = 0;
    for (i = 2; i <= n; i++)
    {
        if (path[i] == 1)
            ans += tren[i] - 1;
        else
            ans += tren[i];
    }
    printf("%d", ans);

    return 0;
}
