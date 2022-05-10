/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define inf 1061109567
using namespace std;

const int mx = 1e5 + 5;
typedef pair<int, int> PII;
PII table[mx][20];
int n, s, l, tree[3 * mx], ara[mx];

void sparse_table()
{
    for (int i = 1; i < n; i++)
        table[i][0] = PII(max(ara[i], ara[i + 1]), min(ara[i], ara[i + 1]));
    for (int j = 1; (1 << j) < n; j++)
    {
        int k = 1 << j;
        for (int i = 1; i <= n; i++)
            if (i + k <= n)
            {
                table[i][j] = PII(max(table[i][j - 1].first, table[i + k / 2][j - 1].first), min(table[i][j - 1].second, table[i + k / 2][j - 1].second));
            }
    }
}
PII Query(int u)
{
    if (u + l - 1 > n)
        return PII(-1, -1);
    int v, w, lg, maxi, mini;
    for (lg = 0; (1 << lg) < n; lg++)
        ;
    lg--;
    maxi = mini = ara[u];
    v = u;
    for (int i = lg; i >= 0; i--)
    {
        int k = 1 << i;
        if (v + k <= n)
        {
            int p = max(maxi, table[v][i].first);
            int q = min(mini, table[v][i].second); ///cout<<p<<' '<<q<<' '<<v+k<<endl;
            if (p - q <= s)
            {
                v += k;
                maxi = p;
                mini = q;
            }
        }
    } ///cout<<"VVVV    "<<v<<' '<<lg<<endl;
    if (u + l - 1 > v)
        return PII(-1, -1);
    maxi = mini = ara[u];
    w = u;
    for (int i = lg; i >= 0; i--)
    {
        int k = 1 << i;
        if (w + k < v)
        {
            int p = max(maxi, table[w][i].first);
            int q = min(mini, table[w][i].second);
            if (p - q > s)
            {
                w += k;
                maxi = p;
                mini = q;
            }
        }
    }
    return PII(v, max(w, u + l - 1));
}
void update(int pos, int L, int R, int k, int val)
{
    if (L == R && L == k)
    {
        tree[pos] = val;
        return;
    }
    int x = pos * 2, mid = (L + R) / 2;
    if (mid >= k)
        update(x, L, mid, k, val);
    else
        update(x + 1, mid + 1, R, k, val);
    tree[pos] = min(tree[x], tree[x + 1]); ///cout<<pos<<' '<<tree[pos]<<endl;
}
int query(int pos, int L, int R, int l, int r)
{
    if (L > r || l > R)
        return inf;
    if (L >= l && R <= r)
        return tree[pos];
    int x = pos * 2, mid = (L + R) / 2;
    int y = query(x, L, mid, l, r);
    int z = query(x + 1, mid + 1, R, l, r);
    return min(y, z);
}
int DP[mx];
int main()
{
    scanf("%d %d %d", &n, &s, &l);
    for (int i = 1; i <= n; i++)
        scanf("%d", &ara[i]);
    sparse_table();
    memset(tree, 63, sizeof(tree));
    update(1, 1, n + 1, n + 1, 0); ///cout<<query(1,1,8,7,8);
    for (int i = n; i > 0; i--)
    {
        PII A = Query(i);
        ///cout<<i<<' '<<A.first<<' '<<A.second<<endl;
        if (A.first != -1)
        {
            DP[i] = 1 + query(1, 1, n + 1, A.second + 1, A.first + 1);
            update(1, 1, n + 1, i, DP[i]);
        } ///cout<<i<<' '<<DP[i]<<endl;
    }
    if (DP[1] == 0 || DP[1] >= inf)
        printf("-1\n");
    else
        printf("%d\n", DP[1]);

    return 0;
}
