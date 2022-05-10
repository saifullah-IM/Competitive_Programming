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

const int mx = 1e6 + 5;
const int MOD = 1e9 + 7;
ll fact[mx], inv[mx];
ll bigmod(ll x, ll n)
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
void prep()
{
    fact[0] = inv[0] = 1;
    for (int i = 1; i < mx; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = bigmod(fact[i], MOD - 2);
    }
}
ll nCR(int n, int r)
{
    ll res = (fact[n] * inv[r]) % MOD;
    res = (res * inv[n - r]) % MOD;
    return res;
}
int ara[mx], cntless[mx];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    prep();
    int n, maxi;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ara[i];
    sort(ara, ara + n);
    for (int i = 0; i < n; i++)
    {
        int x = (lower_bound(ara, ara + n, ara[i]) - ara);
        cntless[i] = x;
        ///cout<<ara[i]<<' '<<x<<endl;
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (ara[i] == ara[n - 1])
            break;
        ll temp = (ara[i] * fact[cntless[i]]) % MOD;
        temp = (temp * fact[n - cntless[i] - 1]) % MOD;
        temp = (temp * nCR(n, n - cntless[i])) % MOD;
        ans += temp;
    }
    ans %= MOD;
    cout << ans << endl;

    return 0;
}
