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
const int MOD = 1e6 + 3;
ll bigmod(ll x, ll n)
{
    ll ret = 1;
    while (n > 0)
    {
        if (n % 2)
            ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k, p, q;
    cin >> n >> k;
    if (n < 63 && k > (1LL << n))
    {
        cout << "1 1" << endl;
        return 0;
    }
    else
    {
        q = bigmod(2, n);
        if (k - 1 >= MOD)
            p = 0;
        else
        {
            p = 1;
            for (int i = 1; i < k; i++)
                p = (p * (q - i)) % MOD;
            p = (p + MOD) % MOD;
        }
        q = bigmod(q, k - 1);
        ll r = 0, x = 2;
        while (x <= k - 1)
        {
            r += (k - 1) / x;
            x *= 2;
        }
        r = bigmod(2, r);
        r = bigmod(r, MOD - 2);
        q = (q * r) % MOD;
        p = (q - p * r) % MOD;
        p = (p + MOD) % MOD;
        cout << p << ' ' << q << endl;
    }

    return 0;
}
