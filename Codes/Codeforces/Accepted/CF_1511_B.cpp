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
#define inf (1 << 30)
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
typedef multiset<int>::iterator mit;
typedef map<int, int> mii;
typedef map<int, int>::iterator miit;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<pii> primes;

    primes.pb(mp(2, 3));
    primes.pb(mp(11, 13));
    primes.pb(mp(101, 103));
    primes.pb(mp(1087, 1091));
    primes.pb(mp(10007, 10009));
    primes.pb(mp(100003, 100019));
    primes.pb(mp(1000003, 1000033));
    primes.pb(mp(10000019, 10000169));
    primes.pb(mp(100030001, 100050001));

    int test = 1;
    cin >> test;
    while (test--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int gcd = 1;
        a -= c;
        b -= c;
        while (c != 1)
        {
            gcd *= 10;
            c--;
        }
        cout << gcd * primes[a].fi << ' ' << gcd * primes[b].se << endl;
    }

    return 0;
}