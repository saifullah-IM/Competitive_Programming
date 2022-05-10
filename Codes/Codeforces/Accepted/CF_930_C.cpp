/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std; /*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;*/

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define infll (1LL << 62)
#define abs(X) ((X) > 0 ? (X) : (-(X)))
#define fbo(k) find_by_order(k)    ///returns iterator to the kth largest element counting from 0
#define ook(val) order_of_key(val) ///returns the number of items in a set that are strictly smaller than val

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
int tree[3 * maxn];
void propagate(int pos)
{
    int x = pos * 2;
    tree[x] += tree[pos];
    tree[x + 1] += tree[pos];
    tree[pos] = 0;
}
void update(int pos, int L, int R, int l, int r)
{
    if (L > r || l > R)
        return;
    if (L >= l && R <= r)
    {
        tree[pos]++;
        return;
    }
    if (tree[pos] != 0)
        propagate(pos);
    int x = pos * 2, mid = (L + R) / 2;
    update(x, L, mid, l, r);
    update(x + 1, mid + 1, R, l, r);
}
int query(int pos, int L, int R, int node)
{
    if (L == R && R == node)
        return tree[pos];
    if (tree[pos] != 0)
        propagate(pos);
    int x = pos * 2, mid = (L + R) / 2;
    if (node <= mid)
        return query(x, L, mid, node);
    else
        return query(x + 1, mid + 1, R, node);
}

int ara[maxn], len1[maxn], len2[maxn], aux[maxn];

void LIS1(int n)
{
    int i, lislen = 0;
    aux[0] = -inf;
    for (i = 1; i <= n; i++)
        aux[i] = inf;

    for (i = 0; i < n; i++)
    {
        int lo, hi, mid;
        lo = 0;
        hi = lislen;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (ara[i] >= aux[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        len1[i] = lo;
        aux[lo] = ara[i];
        if (lislen < lo)
            lislen = lo;
    }
}

void LIS2(int n)
{
    int i, lislen = 0;
    aux[0] = -inf;
    for (i = 1; i <= n; i++)
        aux[i] = inf;

    for (i = n - 1; i >= 0; i--)
    {
        int lo, hi, mid;
        lo = 0;
        hi = lislen;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (ara[i] >= aux[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        len2[i] = lo;
        aux[lo] = ara[i];
        if (lislen < lo)
            lislen = lo;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        update(1, 1, m, l, r);
    }
    for (int i = 1; i <= m; i++)
    {
        ara[i - 1] = query(1, 1, m, i);
        ///cout<<ara[i-1]<<endl;
    }
    LIS1(m);
    LIS2(m);
    int ans = 0;
    for (int i = 0; i < m; i++)
        ans = max(ans, len1[i] + len2[i] - 1);
    cout << ans << endl;

    return 0;
}
