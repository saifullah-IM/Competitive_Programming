#include <bits/stdc++.h>
using namespace std;

set<int> edges[100005];
int ara[100005];
bool chk[100005];

int main()
{
    int i, m, n, u, v, ans, mx;

    mx = -1;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &ara[i]);
        chk[ara[i]] = true;
        mx = max(mx, ara[i]);
    }
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        if (ara[u] != ara[v])
        {
            edges[ara[u]].insert(ara[v]);
            edges[ara[v]].insert(ara[u]);
        }
    }

    u = -1;
    for (i = 1; i <= mx; i++)
        if (chk[i])
        {
            v = edges[i].size();
            if (v > u)
            {
                u = v;
                ans = i;
            }
        }
    printf("%d", ans);

    return 0;
}
