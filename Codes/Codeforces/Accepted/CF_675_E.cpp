/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define PII pair<int, int>
#define ll long long
using namespace std;

const int mx = 1e5 + 5;
int ara[mx];
ll DP[mx];
PII tree[3 * mx];
void build(int pos, int L, int R)
{
    if (L == R)
    {
        tree[pos].first = ara[L - 1];
        tree[pos].second = L - 1;
        return;
    }
    int x = pos * 2, mid = (L + R) / 2;
    build(x, L, mid);
    build(x + 1, mid + 1, R);
    if (tree[x].first > tree[x + 1].first)
        tree[pos] = tree[x];
    else
        tree[pos] = tree[x + 1];
}
PII query(int pos, int L, int R, int l, int r)
{
    if (L > r || l > R)
        return make_pair(-1, -1);
    if (L >= l && R <= r)
        return tree[pos];
    int x = pos * 2, mid = (L + R) / 2;
    auto p = query(x, L, mid, l, r);
    auto q = query(x + 1, mid + 1, R, l, r);
    if (p.first > q.first)
        return p;
    else
        return q;
}

int main()
{
    int i, n;

    scanf("%d", &n);
    for (i = 0; i < n - 1; i++)
    {
        scanf("%d", &ara[i]);
        ara[i]--;
    }
    ara[n - 1] = n - 1;
    ll ans = 0;
    build(1, 1, n);
    for (i = n - 2; i >= 0; i--)
    {
        auto p = query(1, 1, n, i + 2, ara[i] + 1);
        int m = p.second;
        DP[i] = DP[m] + n - 1 - ara[i] + m - i;
        ans += DP[i];
    }
    printf("%lld\n", ans);

    return 0;
}
