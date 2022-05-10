/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
using namespace std;

PII range[200005];
ll tree[525000];
int num[200005], coeff[200005], fns;
vector<int> edges[200005];

void dfs(int s, int k)
{
    if (coeff[s] != 0)
        return;
    coeff[s] = k;
    range[s].first = fns;

    int i, t, u;
    t = edges[s].size();
    for (i = 0; i < t; i++)
    {
        u = edges[s][i];
        dfs(u, -k);
    }

    range[s].second = fns;
    fns++;
}

void propagate(int pos)
{
    int x = pos * 2;

    tree[x] += tree[pos];
    tree[x + 1] += tree[pos];
    tree[pos] = 0;
}

void update(int pos, int L, int R, int l, int r, int val)
{
    if (L > r || l > R)
        return;
    if (L >= l && R <= r)
    {
        tree[pos] += val;
        return;
    }

    if (tree[pos] != 0)
        propagate(pos);

    int x = pos * 2, mid = (L + R) / 2;
    update(x, L, mid, l, r, val);
    update(x + 1, mid + 1, R, l, r, val);
}

ll query(int pos, int L, int R, int k)
{
    if (L > k || k > R)
        return 0;
    if (L == R)
        return tree[pos];

    if (tree[pos] != 0)
        propagate(pos);

    int x = pos * 2, mid = (L + R) / 2;
    ll y = query(x, L, mid, k);
    ll z = query(x + 1, mid + 1, R, k);
    return y + z;
}

int main()
{
    int n, m, i, j, u, v;
    ll ans;

    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    for (i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    fns = 1;
    dfs(1, 1);
    for (i = 0; i < m; i++)
    {
        scanf("%d", &j);
        if (j == 1)
        {
            scanf("%d %d", &u, &v);
            update(1, 1, n, range[u].first, range[u].second, v * coeff[u]);
        }
        else
        {
            scanf("%d", &u);
            ans = query(1, 1, n, range[u].second);
            ans = (ans * coeff[u]) + num[u];
            printf("%lld\n", ans);
        }
    }

    return 0;
}
