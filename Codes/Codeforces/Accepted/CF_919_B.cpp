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
typedef vector<int> VI;
typedef vector<PII> VP;

template <class T>
inline T bigmod(T p, T e, T M)
{
    ll ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1)
            ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T>
inline T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) { return bigmod(a, M - 2, M); }

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;
ll DP[15][11][2];
int t, ara[15];
int cnt(int pos, int sum, bool k)
{
    if (sum == 10)
        return 1;
    if (sum > 10)
        return 0;
    if (pos == t)
        return 0;
    if (DP[pos][sum][k] != -1)
        return DP[pos][sum][k];
    int ans = 0;
    if (pos == 0)
    {
        for (int i = 0; i < ara[0]; i++)
            ans += cnt(pos + 1, sum + i, 1);
        ans += cnt(pos + 1, sum + ara[0], 0);
    }
    else if (k)
    {
        for (int i = 0; i <= 9; i++)
            ans += cnt(pos + 1, sum + i, 1);
    }
    else
    {
        for (int i = 0; i < ara[pos]; i++)
            ans += cnt(pos + 1, sum + i, 1);
        ans += cnt(pos + 1, sum + ara[pos], 0);
    }
    return DP[pos][sum][k] = ans;
}
int solve(ll n)
{
    memset(DP, -1, sizeof(DP));
    ll m = n;
    int i = 0;
    while (m > 0)
    {
        ara[i++] = m % 10;
        m /= 10;
    }
    t = i;
    reverse(ara, ara + t);

    return cnt(0, 0, 0);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> n;
    ll hi, lo, mid, ans = 1;
    hi = 1000000000000;
    lo = 1;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        ll temp = solve(mid);
        ///cout<<mid<<' '<<temp<<' '<<lo<<endl;
        if (temp < n)
            lo = mid + 1;
        else
        {
            if (temp == n)
                ans = mid;
            hi = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}
