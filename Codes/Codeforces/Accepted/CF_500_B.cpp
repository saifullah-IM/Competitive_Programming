#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

int n, ara[305];
bool chk[305], vis[305];
vector<int> edges[305];
vector<int> myidx, myints;

void dfs(int u)
{
    if (vis[u])
        return;
    vis[u] = true;
    myidx.push_back(u);
    myints.push_back(ara[u]);

    int i, j, m, k, v;
    m = edges[u].size();
    for (i = 0; i < m; i++)
    {
        v = edges[u][i];
        dfs(v);
    }
}

int main()
{
    int i, j, k, m;
    char x;
    bool ck;
    PII A, B;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &ara[i]);
    for (i = 0; i < n; i++)
    {
        scanf("%*c");
        for (j = 0; j < n; j++)
        {
            scanf("%c", &x);
            if (x == '1' && i < j)
            {
                edges[i].push_back(j);
                edges[j].push_back(i);
                chk[i] = chk[j] = true;
            }
        }
    }

    for (i = 0; i < n; i++)
        if (chk[i])
        {
            memset(vis, 0, sizeof(vis));
            myidx.clear();
            myints.clear();
            dfs(i);
            m = myints.size();
            sort(myidx.begin(), myidx.end());
            sort(myints.begin(), myints.end());
            for (j = 0; j < m; j++)
            {
                k = myidx[j];
                ara[k] = myints[j];
                chk[k] = false;
            }
        }

    for (i = 0; i < n; i++)
        printf("%d ", ara[i]);
    return 0;
}
