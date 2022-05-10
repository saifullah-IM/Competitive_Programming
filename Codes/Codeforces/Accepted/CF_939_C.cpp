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

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;
int ara[mx];
int tree[mx * 3];
void propagate(int pos, int L, int R)
{
    int x = pos * 2, mid = (L + R) / 2;
    tree[x] += tree[pos];
    tree[x + 1] += tree[pos];
    tree[pos] = 0;
}
void update(int pos, int L, int R, int l, int r, int val)
{
    if (l > r)
        return;
    if (L > r || l > R)
        return;
    if (L >= l && R <= r)
    {
        tree[pos] += val;
        return;
    }
    if (tree[pos] != 0)
        propagate(pos, L, R);
    int x = pos * 2, mid = (L + R) / 2;
    update(x, L, mid, l, r, val);
    update(x + 1, mid + 1, R, l, r, val);
}
int query(int pos, int L, int R, int node)
{
    if (L > node || R < node)
        return -1;
    if (L == R && L == node)
        return tree[pos];
    if (tree[pos] != 0)
        propagate(pos, L, R);
    int x = pos * 2, mid = (L + R) / 2;
    if (mid >= node)
        return query(x, L, mid, node);
    else
        return query(x + 1, mid + 1, R, node);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, f, s;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ara[i];
    cin >> s >> f;
    for (int i = 0; i < n; i++)
    {
        int l = s - i;
        int r = f - i - 1;
        if (l < 1)
            l += n;
        if (r < 1)
            r += n;
        ///cout<<i<<' '<<l<<' '<<r<<endl;
        if (l <= r)
            update(1, 1, n, l, r, ara[i]);
        else
        {
            update(1, 1, n, l, n, ara[i]);
            update(1, 1, n, 1, r, ara[i]);
        }
    }
    int ans = -1, maxi = -1;
    for (int i = 1; i <= n; i++)
    {
        int x = query(1, 1, n, i);
        ///cout<<i<<' '<<x<<endl;
        if (x > maxi)
        {
            maxi = x;
            ans = i;
        }
    }
    cout << ans << endl;

    return 0;
}
