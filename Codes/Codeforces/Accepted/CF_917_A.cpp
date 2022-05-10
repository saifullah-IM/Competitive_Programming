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

const int mx = 5e3 + 5;
const int MOD = 1e9 + 7;
string str;
bool open[mx][mx], close[mx][mx];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> str;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        bool ok = true;
        int cnt = 0;
        for (int j = i; j >= 0; j--)
        {
            if (str[j] == '(')
                cnt--;
            else
                cnt++;
            if (cnt < 0)
                ok = false;
            open[j][i] = ok;
        }
        ok = true;
        cnt = 0;
        for (int j = i; j < n; j++)
        {
            if (str[j] == ')')
                cnt--;
            else
                cnt++;
            if (cnt < 0)
                ok = false;
            close[i][j] = ok;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (open[i][j] && close[i][j] && (j - i + 1) % 2 == 0)
                ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
