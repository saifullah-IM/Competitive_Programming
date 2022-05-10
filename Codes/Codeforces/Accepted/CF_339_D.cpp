#include <bits/stdc++.h>
using namespace std;

int power(int x, int n)
{
    int ans = 1;
    while (n--)
        ans *= x;
    return ans;
}

int i, N, ara[132000], tree[263000];

int build(int n, bool flag)
{
    if (n >= N)
        return ara[i++];

    int x = n * 2;
    flag = !flag;
    tree[x] = build(x, flag);
    tree[x + 1] = build(x + 1, flag);

    if (flag)
        tree[n] = (tree[x] | tree[x + 1]);
    else
        tree[n] = (tree[x] ^ tree[x + 1]);

    return tree[n];
}

int update(int n, int L, int R, int p, int b, bool flag)
{
    if (L == p && p == R)
        return tree[n] = ara[p - 1] = b;

    int mid = (L + R) / 2, x = n * 2;
    flag = !flag;

    if (p <= mid)
        tree[x] = update(x, L, mid, p, b, flag);
    else
        tree[x + 1] = update(x + 1, mid + 1, R, p, b, flag);

    if (flag)
        tree[n] = (tree[x] | tree[x + 1]);
    else
        tree[n] = (tree[x] ^ tree[x + 1]);

    return tree[n];
}

int main()
{
    int m, n, j, ans, p, b;
    bool flag;

    scanf("%d %d", &n, &m);
    N = power(2, n);
    for (j = 0; j < N; j++)
        scanf("%d", &ara[j]);

    if (n % 2 == 0)
        flag = true;
    else
        flag = false;

    build(1, flag);

    while (m--)
    {
        scanf("%d %d", &p, &b);
        ans = update(1, 1, N, p, b, flag);
        printf("%d\n", ans);
    }

    return 0;
}
