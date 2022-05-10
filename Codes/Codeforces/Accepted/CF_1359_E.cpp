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

const int MX = 5e5 + 5;
const int MOD = 998244353;

int binary_exp(ll x, int m)
{
    ll ans = 1;

    while (m > 0)
    {
        if (m % 2 == 1)
            ans = (ans * x) % MOD;
        x = (x * x) % MOD;
        m /= 2;
    }

    return ans;
}

int factorial[MX];
int inv_factorial[MX];

void preprocess()
{
    ll mult = 1;
    factorial[0] = inv_factorial[0] = 1;
    for (int i = 1; i < MX; i++)
    {
        mult = (mult * i) % MOD;
        factorial[i] = mult;
        inv_factorial[i] = binary_exp(mult, MOD - 2);
    }
}

int ncr(int n, int r)
{
    if (n < r)
        return 0;

    ll ans = factorial[n];
    ans = (ans * inv_factorial[r]) % MOD;
    ans = (ans * inv_factorial[n - r]) % MOD;

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    //cin >> test;
    preprocess();
    while (test--)
    {
        int n, k;
        cin >> n >> k;
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int m = n / i - 1;
            if (m < k - 1)
                break;

            ans = (ans + ncr(m, k - 1)) % MOD;
        }
        cout << ans << endl;
    }

    return 0;
}