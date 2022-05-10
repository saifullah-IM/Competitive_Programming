#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

vector<PII> edges[100005];
vector<int> ans;
bool vis[100005];

bool dfs(int u)
{
    int i, n, v;
    PII A;
    bool ret, chk;
    n = edges[u].size();
    ret = false;

    for (i = 0; i < n; i++)
    {
        A = edges[u][i];
        v = A.first;
        if (!vis[v])
        {
            vis[v] = true;
            chk = dfs(v);
            ret = (ret | chk);
            if (A.second == 2)
            {
                ret = true;
                if (!chk)
                    ans.push_back(v);
            }
        }
    }

    return ret;
}

int main()
{
    int i, n, x, y, t;

    scanf("%d", &n);
    for (i = 1; i < n; i++)
    {
        scanf("%d %d %d", &x, &y, &t);
        edges[x].push_back(make_pair(y, t));
        edges[y].push_back(make_pair(x, t));
    }

    vis[1] = true;
    dfs(1);
    n = ans.size();
    printf("%d\n", n);
    for (i = 0; i < n; i++)
    {
        x = ans[i];
        printf("%d ", x);
    }

    return 0;
}
