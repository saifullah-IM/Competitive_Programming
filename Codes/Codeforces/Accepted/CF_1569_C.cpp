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

const int MX = 2e5 + 5;
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
int mod_inv[MX];

void preprocess()
{
    ll mult = 1;
    factorial[0] = mod_inv[0] = 1;
    for (int i = 1; i < MX; i++)
    {
        mult = (mult * i) % MOD;
        factorial[i] = mult;
        mod_inv[i] = binary_exp(i, MOD - 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    preprocess();
    int test = 1;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vi ara(n);
        for (int i = 0; i < n; i++)
            cin >> ara[i];

        sort(ara.begin(), ara.begin() + n);
        if (ara[n - 1] == ara[n - 2])
            cout << factorial[n] << '\n';
        else if (ara[n - 1] - ara[n - 2] > 1)
            cout << "0\n";
        else
        {
            int k = 1;
            int idx = -2;
            while (ara[n - 2] == ara[n + idx])
            {
                k += 1;
                idx -= 1;
                if ((abs(idx)) > n)
                    break;
            }
            ll ans = factorial[n];
            ans = (ans * (k - 1)) % MOD;
            ans = (ans * mod_inv[k]) % MOD;
            cout << ans << '\n';
        }
    }

    return 0;
}