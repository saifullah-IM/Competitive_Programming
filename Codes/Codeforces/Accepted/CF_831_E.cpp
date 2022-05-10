/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
using namespace std;

struct info
{
    int x, idx;
};

bool compare(info A, info B)
{
    if (A.x == B.x)
        return A.idx < B.idx;
    else
        return A.x < B.x;
}

int tree[263000];

void update(int pos, int L, int R, int k)
{
    if (L > k || R < k)
        return;
    if (L == k && R == k)
    {
        tree[pos] = 1;
        return;
    }

    int x = pos * 2, mid = (L + R) / 2;
    update(x, L, mid, k);
    update(x + 1, mid + 1, R, k);
    tree[pos] = tree[x] + tree[x + 1];
}

int query(int pos, int L, int R, int l, int r)
{
    if (L > r || R < l)
        return 0;
    if (l <= L && r >= R)
        return tree[pos];

    int x = pos * 2, mid = (L + R) / 2;
    int y = query(x, L, mid, l, r);
    int z = query(x + 1, mid + 1, R, l, r);
    return y + z;
}

int main()
{
    int i, j, k, n, prev, crnt;
    long long ans;
    info ara[100005];

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &ara[i].x);
        ara[i].idx = i;
    }
    sort(ara + 1, ara + n + 1, compare);
    ara[n + 1].x = ara[n + 1].idx = 100005;

    crnt = ara[1].x;
    ans = j = 0;
    i = 1;
    while (i <= n)
    {
        bool chk = false;
        prev = j;
        while (ara[i].x == crnt && ara[i].idx < j)
        {
            if (ara[i].idx > prev)
            {
                ans += ara[i].idx - prev;
                ans -= query(1, 1, n, prev + 1, ara[i].idx);
            }
            else
            {
                ans += n - prev;
                ans -= query(1, 1, n, prev + 1, n);
                ans += ara[i].idx;
                ans -= query(1, 1, n, 1, ara[i].idx);
            }
            update(1, 1, n, ara[i].idx);
            prev = ara[i].idx;
            chk = true;
            i++;
        }

        k = i;
        prev = j;
        while (ara[i].x == crnt && ara[i].idx > j)
        {
            if (!chk && ara[i].idx > prev)
            {
                ans += ara[i].idx - prev;
                ans -= query(1, 1, n, prev + 1, ara[i].idx);
            }
            else if (!chk)
            {
                ans += n - prev;
                ans -= query(1, 1, n, prev + 1, n);
                ans += ara[i].idx;
                ans -= query(1, 1, n, 1, ara[i].idx);
            }
            update(1, 1, n, ara[i].idx);
            prev = ara[i].idx;
            i++;
        }

        if (!chk)
            j = ara[i - 1].idx;
        else
            j = ara[k - 1].idx;
        crnt = ara[i].x;
    }

    printf("%lld", ans);

    return 0;
}
