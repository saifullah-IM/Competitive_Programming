/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define mp make_pair
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define abs(X) ((X) > 0 ? (X) : (-(X)))
using namespace std;

///cout << fixed << setprecision(12) << p << endl;

typedef long long ll;
typedef pair<int, int> PII;

const int mx = 1e6 + 5;
const int MOD = 1e9 + 7;
ll bigmod(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n % 2 == 1)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return res;
}
ll fact[mx], inv[mx];
void prep(int k)
{
    fact[0] = 1;
    for (int i = 1; i <= k; i++)
        fact[i] = (fact[i - 1] * i) % MOD;
    for (int i = 1; i < 2005 && i <= k; i++)
    {
        inv[i] = bigmod(fact[i], MOD - 2);
        int x = k - i;
        inv[x] = bigmod(fact[x], MOD - 2);
    }
}
ll nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r == 0 || r == n)
        return 1;

    r = min(r, n - r);
    ll res = fact[n];
    res = (res * inv[r]) % MOD;
    return (res * inv[n - r]) % MOD;
}
ll DP[1005][1005];
ll solve(int n, int x)
{

    if (x == 1)
        return 1;
    if (n == 1)
        return 0;
    if (DP[n][x] != -1)
        return DP[n][x];
    ll res = (solve(n - 1, x) * x) % MOD + (solve(n - 1, x - 1) * x) % MOD;
    return DP[n][x] = res % MOD;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k;
    cin >> n >> m >> k;
    ll ans;
    if (m == 1)
        ans = bigmod(k, n);
    else
    {
        memset(DP, -1, sizeof(DP));
        prep(k);
        ans = 0;
        for (int i = 1; i <= n && i <= k; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                ll cnt = 1;
                cnt = (cnt * nCr(k, 2 * i - j)) % MOD;
                cnt = (cnt * nCr(2 * i - j, i - j)) % MOD;
                cnt = (cnt * nCr(i, i - j)) % MOD;
                ///cout<<"----"<<cnt<<endl;
                cnt = (cnt * solve(n, i)) % MOD;
                cnt = (cnt * solve(n, i)) % MOD;
                cnt = (cnt * bigmod(j, n * m - 2 * n)) % MOD;
                ///cout<<i<<' '<<j<<' '<<cnt<<endl;
                ans = (ans + cnt) % MOD;
            }
        }
    } ///cout<<solve(2,2)<<endl;
    cout << ans << endl;

    return 0;
}
