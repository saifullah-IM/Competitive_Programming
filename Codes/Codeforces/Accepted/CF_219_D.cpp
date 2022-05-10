#include <bits/stdc++.h>
using namespace std;

vector<int> inedge[200005];
vector<int> outedge[200005];
vector<int> myans;
int mn;

int dfs_1(int u, int p)
{
    int i, v, n, ans;

    ans = 0;
    n = outedge[u].size();
    for (i = 0; i < n; i++)
    {
        v = outedge[u][i];
        if (v != p)
            ans += dfs_1(v, u);
    }

    n = inedge[u].size();
    for (i = 0; i < n; i++)
    {
        v = inedge[u][i];
        if (v != p)
            ans += 1 + dfs_1(v, u);
    }

    return ans;
}

void dfs_2(int u, int m, int p)
{
    if (m == mn)
        myans.push_back(u);
    if (m < mn)
    {
        mn = m;
        myans.clear();
        myans.push_back(u);
    }

    int i, v, n;

    n = outedge[u].size();
    for (i = 0; i < n; i++)
    {
        v = outedge[u][i];
        if (v != p)
            dfs_2(v, m + 1, u);
    }

    n = inedge[u].size();
    for (i = 0; i < n; i++)
    {
        v = inedge[u][i];
        if (v != p)
            dfs_2(v, m - 1, u);
    }
}

int main()
{
    int i, n, u, v;

    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        outedge[u].push_back(v);
        inedge[v].push_back(u);
    }

    mn = dfs_1(1, 0);
    dfs_2(1, mn, 0);
    sort(myans.begin(), myans.end());

    printf("%d\n", mn);
    v = myans.size();
    for (i = 0; i < v; i++)
    {
        u = myans[i];
        printf("%d ", u);
    }

    return 0;
}
