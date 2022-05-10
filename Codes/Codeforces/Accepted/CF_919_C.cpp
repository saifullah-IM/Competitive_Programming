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
string str[2005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> str[i];
    ll ans = 0;
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (str[i][j] == '.')
                    ans++;
        cout << ans << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < m; j++)
        {
            if (str[i][j] == '.')
                cnt++;
            else
            {
                ans += max(0, cnt - k + 1);
                cnt = 0;
            }
        }
        ans += max(0, cnt - k + 1);
    }
    for (int j = 0; j < m; j++)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i][j] == '.')
                cnt++;
            else
            {
                ans += max(0, cnt - k + 1);
                cnt = 0;
            }
        }
        ans += max(0, cnt - k + 1);
    }
    cout << ans << endl;

    return 0;
}
