#include <bits/stdc++.h>
using namespace std;

int height[200005], width[200005], tree[525000];

int build(int pos, int L, int R)
{
    if (L == R)
        return tree[pos] = height[L];

    int mid = (L + R) / 2, x = pos * 2;
    int y = build(x, L, mid);
    int z = build(x + 1, mid + 1, R);

    return tree[pos] = max(y, z);
}

int query(int pos, int L, int R, int l, int r)
{
    if (l > R || L > r)
        return 0;
    if (l <= L && R <= r)
        return tree[pos];

    int mid = (L + R) / 2, x = pos * 2;
    int y = query(x, L, mid, l, r);
    int z = query(x + 1, mid + 1, R, l, r);

    return max(y, z);
}

int main()
{
    int i, n, wsum = 0, ans;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &width[i], &height[i]);
        wsum += width[i];
    }
    build(1, 1, n);
    for (i = 1; i <= n; i++)
    {
        ans = max(query(1, 1, n, 1, i - 1), query(1, 1, n, i + 1, n));
        ans *= (wsum - width[i]);
        printf("%d ", ans);
    }

    return 0;
}
