#include <bits/stdc++.h>
#define inf 2000000000
using namespace std;

int n, segtree[17000], ara[5005];

void build(int pos, int L, int R)
{
    if (L == R)
    {
        segtree[pos] = ara[L];
        return;
    }

    int x = pos * 2, mid = (L + R) / 2;
    build(x, L, mid);
    build(x + 1, mid + 1, R);
    segtree[pos] = min(segtree[x], segtree[x + 1]);
}

int query(int pos, int L, int R, int l, int r)
{
    if (L > r || l > R)
        return inf;
    if (L >= l && R <= r)
        return segtree[pos];

    int mid = (L + R) / 2, x = pos * 2;
    int y = query(x, L, mid, l, r);
    int z = query(x + 1, mid + 1, R, l, r);
    return min(y, z);
}

int paint_fence(int l, int r, int h)
{
    if (l == r)
        return 1;

    int i, m, u, v, ans, temp;
    ans = r - l + 1;
    m = query(1, 1, n, l, r);
    temp = m - h;
    if (temp >= ans)
        return ans;

    i = l;
    while (i <= r)
    {
        bool ck = false;
        for (; i <= r; i++)
            if (ara[i] != m)
            {
                ck = true;
                u = v = i;
                break;
            }
        for (; i <= r; i++)
        {
            if (ara[i] != m)
                v = i;
            if (ara[i] == m)
                break;
        }
        if (ck)
            temp += paint_fence(u, v, m);
        if (temp >= ans)
            return ans;
    }

    return min(ans, temp);
}

int main()
{
    int i, ans;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &ara[i]);
    build(1, 1, n);
    ans = paint_fence(1, n, 0);
    printf("%d", ans);

    return 0;
}