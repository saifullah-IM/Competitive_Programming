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

const int mx = 2e5 + 5;
const int MOD = 1e9 + 7;
ll fact[mx], inv[mx], dp[2005];
int n;
pii ara[2005];
ll bigmod(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * x) % MOD;
        n /= 2;
        x = (x * x) % MOD;
    }
    return res;
}
void prep()
{
    fact[0] = inv[0] = 1;
    for (int i = 1; i < mx; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = bigmod(fact[i], MOD - 2);
    }
}
ll nCr(int n, int r)
{
    if (n < 0 || r < 0 || n < r)
        return 0;
    ll ans = (fact[n] * inv[r]) % MOD;
    return (ans * inv[n - r]) % MOD;
}
ll cntWay(ll x, ll y)
{
    return nCr(x + y, y);
}
ll solve(int pos)
{
    if (dp[pos] != -1)
        return dp[pos];
    dp[pos] = cntWay(ara[pos].fi - 1, ara[pos].se - 1);
    for (int i = 0; i < pos; i++)
    {
        ll way = (solve(i) * (cntWay(ara[pos].fi - ara[i].fi, ara[pos].se - ara[i].se))) % MOD;
        dp[pos] = (dp[pos] - way) % MOD;
    }
    dp[pos] = (dp[pos] + MOD) % MOD;
    return dp[pos];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    prep();
    int h, w;
    cin >> h >> w >> n;
    for (int i = 0; i < n; i++)
        cin >> ara[i].fi >> ara[i].se;
    ara[n] = mp(h, w);
    sort(ara, ara + n + 1);
    memset(dp, -1, sizeof(dp));
    cout << solve(n) << endl;
    return 0;
}
