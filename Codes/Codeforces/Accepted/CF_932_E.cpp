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

const int mx = 5e3 + 5;
const int MOD = 1e9 + 7;
ll modexp(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return res;
}
ll dp[mx][mx];
ll solve(int a, int b, int c)
{
    if (a == 0)
        return modexp(2, c);
    if (dp[a][b] != -1)
        return dp[a][b];

    ll ans;
    if (b == 0)
        ans = (c * solve(a - 1, b + 1, c - 1)) % MOD;
    else
        ans = ((b * solve(a - 1, b, c)) % MOD + (c * solve(a - 1, b + 1, c - 1)) % MOD) % MOD;
    return dp[a][b] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n >> k;
    memset(dp, -1, sizeof(dp));
    cout << solve(k, 0, n) << endl;

    return 0;
}
