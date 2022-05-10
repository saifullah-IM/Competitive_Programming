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
bitset<mx> flag;
vi primes;
void sieve()
{
    primes.pb(2);
    for (int i = 3; i < mx; i += 2)
    {
        if (flag[i])
            continue;
        primes.pb(i);
        for (ll j = (ll)i * i; j < mx; j += i)
            flag[j] = true;
    }
}
ll phi(ll n)
{
    ll ans = n;
    for (int u : primes)
    {
        if ((ll)u * u > n)
            break;
        if (n % u)
            continue;
        while (n % u == 0)
            n /= u;
        ans -= ans / u;
    }
    if (n != 1)
        ans -= ans / n;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();
    ll n;
    int m, k;
    cin >> n >> k;
    m = (k + 1) / 2;
    ll ans = n;
    while (m--)
    {
        if (ans == 1)
            break;
        ans = phi(ans);
    }
    cout << ans % MOD << endl;

    return 0;
}
