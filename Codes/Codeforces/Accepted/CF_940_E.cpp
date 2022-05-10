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

int n, k, ara[mx], mini[3 * mx];
void build(int pos, int L, int R)
{
    if (L == R)
    {
        mini[pos] = ara[L];
        return;
    }
    int x = pos * 2, mid = (L + R) / 2;
    build(x, L, mid);
    build(x + 1, mid + 1, R);
    mini[pos] = min(mini[x], mini[x + 1]);
}
int query(int pos, int L, int R, int l, int r)
{
    if (L >= l && r >= R)
        return mini[pos];
    int x = pos * 2, mid = (L + R) / 2;
    int ans = inf;
    if (l <= mid)
        ans = min(ans, query(x, L, mid, l, r));
    if (mid < r)
        ans = min(ans, query(x + 1, mid + 1, R, l, r));
    return ans;
}
ll dp[mx], sum[mx];
ll solve(int pos)
{
    if (pos > n)
        return 0;
    if (dp[pos] != -1)
        return dp[pos];
    ll ans = ara[pos] + solve(pos + 1);
    if (pos + k - 1 <= n)
    {
        ll temp = sum[pos + k - 1] - sum[pos - 1] - query(1, 1, n, pos, pos + k - 1);
        ans = min(ans, temp + solve(pos + k));
    }
    return dp[pos] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> ara[i];
        sum[i] = sum[i - 1] + ara[i];
    }
    build(1, 1, n);
    memset(dp, -1, sizeof(dp));
    cout << solve(1) << endl;
    return 0;
}