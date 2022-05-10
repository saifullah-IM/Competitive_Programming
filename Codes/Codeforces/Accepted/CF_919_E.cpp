/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define mp make_pair
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define abs(X) ((X) > 0 ? (X) : (-(X)))
using namespace std;

//cout << fixed << setprecision(12) << p << endl;

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VP;

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;

ll bigmod(ll x, ll n, ll p)
{
    ll res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * x) % p;
        x = (x * x) % p;
        n /= 2;
    }
    return res;
}
ll d, x, y;
void ExEcld(ll a, ll b)
{
    if (b == 0)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        ExEcld(b, a % b);
        ll t;
        t = x;
        x = y;
        y = t - (a / b) * y;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll a, b, p, m, ans = 0;
    cin >> a >> b >> p >> m;
    ll B = bigmod(b, p - 2, p);
    ll r = 1;
    for (int k = 0; k < p - 1; k++)
    {
        ll q = (B * r) % p;
        r = (r * a) % p;
        ExEcld(q, p);
        ///cout<<q<<' '<<p<<' '<<k<<endl;
        if (d != 1)
            continue;
        ll i = (x % p + p) % p;
        ll z = i * (p - 1) * (p - 1) + k * p;
        z %= (p * (p - 1));
        ///cout<<z<<' '<<i<<' '<<k<<endl;
        if (z > m)
            continue;
        ans += (m - z) / (p * (p - 1)) + 1;
        ///cout<<k<<' '<<ans<<endl;
    }
    cout << ans << endl;

    return 0;
}
