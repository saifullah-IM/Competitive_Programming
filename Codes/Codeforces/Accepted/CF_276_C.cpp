#include <bits/stdc++.h>
using namespace std;

int tree[525000], num[200005], ara[200005];
void update(int pos, int L, int R, int l, int r)
{
    if (l > R || L > r)
        return;
    if (L >= l && R <= r)
    {
        tree[pos]++;
        return;
    }

    int mid = (L + R) / 2, x = pos * 2;
    update(x, L, mid, l, r);
    update(x + 1, mid + 1, R, l, r);
}

int query(int pos, int L, int R, int node)
{
    int ans = 0;
    if (L > node || R < node)
        return 0;
    if (L == R && L == node)
        return tree[pos];
    if (L <= node && node <= R)
        ans += tree[pos];

    int mid = (L + R) / 2, x = pos * 2;
    if (node <= mid)
        ans += query(x, L, mid, node);
    else
        ans += query(x + 1, mid + 1, R, node);

    return ans;
}
int main()
{
    int i, n, q, l, r;
    long long ans = 0;

    scanf("%d %d", &n, &q);
    for (i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    for (i = 0; i < q; i++)
    {
        scanf("%d %d", &l, &r);
        update(1, 1, n, l, r);
    }
    for (i = 1; i <= n; i++)
        ara[i] = query(1, 1, n, i);

    sort(num + 1, num + n + 1);
    sort(ara + 1, ara + n + 1);
    for (i = 1; i <= n; i++)
        ans += ((long long)ara[i]) * ((long long)num[i]);
    printf("%lld\n", ans);

    return 0;
}
