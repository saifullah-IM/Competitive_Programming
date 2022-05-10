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

const int mx = 2e6 + 5;
const int MOD = 1e9 + 7;
int mobius[mx];
bool flag[mx];
inline ll bigmod(ll x, int n)
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
ll add[mx], rmv[mx];
ll powx[mx];
inline void prep(int n, int k)
{
    for (int i = 1; i <= k; i++)
        powx[i] = bigmod(i, n);
}
inline void sieve()
{
    for (int i = 1; i < mx; i += 2)
        mobius[i] = 1;
    for (int i = 2; i < mx; i += 2)
        mobius[i] = -1;
    for (int i = 4; i < mx; i += 4)
        mobius[i] = 0;
    int root = sqrt(mx);
    for (int i = 3; i < mx; i += 2)
    {
        if (flag[i])
            continue;
        for (int j = i; j < mx; j += i)
        {
            flag[j] = true;
            mobius[j] *= -1;
        }
        if (i > root)
            continue;
        int k = i * i;
        for (int j = k; j < mx; j += k)
            mobius[j] = 0;
    }

    for (int i = 1; i < mx; i++)
    {
        if (mobius[i] == 0)
            continue;
        for (int j = i; j < mx; j += i)
        {
            add[j] += powx[j / i] * mobius[i];
            if (j != i)
                rmv[j] += powx[(j - 1) / i] * mobius[i];
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;
    prep(n, k);
    sieve();

    ll ans = 0;
    ll temp = 1;
    for (int i = 2; i <= k; i++)
    {
        temp += add[i];
        temp -= rmv[i];
        temp = (temp % MOD + MOD) % MOD;
        ans += (temp ^ i);
    }
    ans %= MOD;
    cout << ans << endl;

    return 0;
}
