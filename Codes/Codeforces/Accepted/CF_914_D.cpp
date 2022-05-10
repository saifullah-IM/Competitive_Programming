/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef pair<PII, int> xxx;
const int maxn = (1 << 20);
const int mx = 5e5 + 5;
int ara[mx], tree[maxn];
int GCD(int a, int b)
{
    int t;
    while (b > 0)
    {
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
void build(int pos, int L, int R)
{
    if (L == R)
    {
        tree[pos] = ara[L];
        return;
    }
    int mid = (L + R) / 2, x = pos * 2;
    build(x, L, mid);
    build(x + 1, mid + 1, R);
    tree[pos] = GCD(tree[x], tree[x + 1]);
}
void update(int pos, int L, int R, int u, int val)
{
    if (L > u || R < u)
        return;
    if (L == u && L == R)
    {
        tree[pos] = ara[u] = val;
        return;
    }
    int mid = (L + R) / 2, x = pos * 2;
    if (mid >= u)
        update(x, L, mid, u, val);
    else
        update(x + 1, mid + 1, R, u, val);
    tree[pos] = GCD(tree[x], tree[x + 1]);
}
vector<xxx> range;
void rangeQ(int pos, int L, int R, int l, int r, int val)
{
    if (L > r || l > R)
        return;
    if (L >= l && R <= r)
    {
        if (tree[pos] % val != 0)
            range.push_back(xxx(PII(L, R), pos));
        return;
    }
    int mid = (L + R) / 2, x = pos * 2;
    rangeQ(x, L, mid, l, r, val);
    rangeQ(x + 1, mid + 1, R, l, r, val);
}
int divQ(int pos, int L, int R, int val)
{
    if (L == R)
    {
        if (tree[pos] % val == 0)
            return 0;
        else
            return 1;
    }
    int mid = (L + R) / 2, x = pos * 2;
    if (tree[x] % val != 0 && tree[x + 1] % val != 0)
        return 2;
    else if (tree[x] % val != 0)
        return divQ(x, L, mid, val);
    else
        return divQ(x + 1, mid + 1, R, val);
}
int main()
{
    int i, n;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &ara[i]);
    build(1, 1, n);
    int q;
    int l, r, x, k;
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &k);
        if (k == 2)
        {
            scanf("%d %d", &l, &x);
            update(1, 1, n, l, x);
        }
        else
        {
            scanf("%d %d %d", &l, &r, &x);
            range.clear();
            rangeQ(1, 1, n, l, r, x);
            if (range.size() > 1)
            {
                printf("NO\n");
                continue;
            }
            else if (range.empty())
            {
                printf("YES\n");
                continue;
            }
            else
            {
                int t = divQ(range[0].second, range[0].first.first, range[0].first.second, x);
                if (t > 1)
                    printf("NO\n");
                else
                    printf("YES\n");
            }
        }
    }

    return 0;
}
