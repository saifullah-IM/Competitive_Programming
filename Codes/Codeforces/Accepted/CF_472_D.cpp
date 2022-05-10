#include <bits/stdc++.h>
#define PII pair<int, int>
#define inf 2000000000
using namespace std;

struct edge
{
    int u, v, w;
};

int mat[2002][2002];
edge cost[2002];
bool taken[2002];
vector<int> tree[2002];

bool dfs(int u, int w, int p)
{
    if (taken[u])
        return true;
    taken[u] = true;

    if (mat[u][p] != w)
        return false;
    int i, v, n;
    bool ans = true;

    n = tree[u].size();
    for (i = 0; i < n; i++)
    {
        v = tree[u][i];
        ans = (ans & dfs(v, w + mat[u][v], p));
        if (!ans)
            return ans;
    }
    return ans;
}

int main()
{
    int i, j, n, m, k, l, mn;
    bool chk;
    edge A;

    chk = true;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &mat[i][j]);
            if (i == j && mat[i][j] != 0)
                chk = false;
            if (i != j)
            {
                if (mat[i][j] == 0)
                    chk = false;
                if (i > j && mat[i][j] != mat[j][i])
                    chk = false;
            }
        }

    if (!chk)
    {
        printf("NO");
        return 0;
    }

    memset(cost, 63, sizeof(cost));
    cost[1].w = 0;
    cost[1].u = 1;
    cost[1].v = 0;
    l = 0;

    for (i = 1; i <= n; i++)
    {
        mn = inf;
        for (j = 1; j <= n; j++)
            if (!taken[j])
            {
                if (cost[j].w < mn)
                {
                    mn = cost[j].w;
                    A = cost[j];
                }
            }

        k = A.u;
        taken[k] = true;
        tree[A.u].push_back(A.v);
        tree[A.v].push_back(A.u);

        for (j = 1; j <= n; j++)
            if (!taken[j])
            {
                if (cost[j].w > mat[k][j])
                {
                    cost[j].u = j;
                    cost[j].v = k;
                    cost[j].w = mat[k][j];
                }
            }
    }

    for (i = 1; i < n; i++)
    {
        memset(taken, 0, sizeof(taken));
        taken[0] = true;
        chk = dfs(i, 0, i);
        if (!chk)
        {
            printf("NO");
            return 0;
        }
    }

    printf("YES");

    return 0;
}
