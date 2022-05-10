/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define infll (1LL << 62)
#define abs(X) ((X) > 0 ? (X) : (-(X)))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 2e5 + 5;
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
        fact[i] = (i * fact[i - 1]) % MOD;
        inv[i] = bigmod(fact[i], MOD - 2);
    }
}
ll chose(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    ll res = (fact[n] * inv[r]) % MOD;
    return (res * inv[n - r]) % MOD;
}
ll ara[2][mx];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    prep();
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ara[0][i];
    if (n == 1)
    {
        cout << ara[0][1] << endl;
        return 0;
    }
    else if (n % 2)
    {
        m = n - 1;
        int sign = 1;
        for (int i = 1; i <= m; i++)
        {
            ara[1][i] = ara[0][i] + sign * ara[0][i + 1];
            sign *= -1;
        }
    }
    else
        m = n;
    int k = m / 2;
    ll term1 = 0, term2 = 0;
    for (int i = 1; i <= m; i += 2)
        term1 = (term1 + (chose(k - 1, (i + 1) / 2 - 1) * ara[n % 2][i]) % MOD) % MOD;
    for (int i = 2; i <= m; i += 2)
        term2 = (term2 + (chose(k - 1, i / 2 - 1) * ara[n % 2][i]) % MOD) % MOD;

    ll ans;
    if (m % 4 == 0)
        ans = ((term1 - term2) % MOD + MOD) % MOD;
    else
        ans = ((term1 + term2) % MOD + MOD) % MOD;
    cout << ans << endl;

    return 0;
}
