#include <bits/stdc++.h>
using namespace std;

struct operations
{
    int l, r, d;
};

operations ops[100005];
int num[100005], treeops[263000];
long long treenum[263000];

void update(int pos, int L, int R, int l, int r, long long d)
{
    if (l > R || L > r)
        return;
    if (L >= l && r >= R)
    {
        treenum[pos] += d;
        return;
    }

    int mid = (L + R) / 2, x = pos * 2;
    update(x, L, mid, l, r, d);
    update(x + 1, mid + 1, R, l, r, d);
}

long long query(int pos, int L, int R, int node)
{
    if (L > node || R < node)
        return 0;
    if (L == R && L == node)
        return treenum[pos];

    long long ans = treenum[pos];
    int mid = (L + R) / 2, x = pos * 2;

    if (node <= mid)
        ans += query(x, L, mid, node);
    else
        ans += query(x + 1, mid + 1, R, node);

    return ans;
}

void UPD(int pos, int L, int R, int l, int r)
{
    if (L > r || l > R)
        return;
    if (l <= L && R <= r)
    {
        treeops[pos]++;
        return;
    }

    int mid = (L + R) / 2, x = pos * 2;
    UPD(x, L, mid, l, r);
    UPD(x + 1, mid + 1, R, l, r);
}

int QRY(int pos, int L, int R, int node)
{
    if (L > node || R < node)
        return 0;
    if (L == R && L == node)
        return treeops[pos];

    int ans = treeops[pos];
    int mid = (L + R) / 2, x = pos * 2;

    if (node <= mid)
        ans += QRY(x, L, mid, node);
    else
        ans += QRY(x + 1, mid + 1, R, node);

    return ans;
}

int main()
{
    int i, n, m, k, l, r, temp;
    long long ans;

    scanf("%d %d %d", &n, &m, &k);
    for (i = 1; i <= n; i++)
        scanf("%d", &num[i]);
    for (i = 1; i <= m; i++)
        scanf("%d %d %d", &ops[i].l, &ops[i].r, &ops[i].d);
    for (i = 1; i <= k; i++)
    {
        scanf("%d %d", &l, &r);
        UPD(1, 1, m, l, r);
    }
    for (i = 1; i <= m; i++)
    {
        temp = QRY(1, 1, m, i);
        update(1, 1, n, ops[i].l, ops[i].r, ((long long)temp) * ops[i].d);
    }
    for (i = 1; i <= n; i++)
    {
        ans = num[i] + query(1, 1, n, i);
        printf("%lld ", ans);
    }

    return 0;
}
