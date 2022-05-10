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
bool flag[3000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int f1 = 1, f2 = 1;
    int f3 = 2;
    flag[1] = true;
    while (f3 < 1005)
    {
        f3 = f1 + f2;
        flag[f3] = true;
        f1 = f2;
        f2 = f3;
    }
    char str[1005];
    for (int i = 0; i < n; i++)
    {
        if (flag[i + 1])
            str[i] = 'O';
        else
            str[i] = 'o';
    }
    str[n] = '\0';
    cout << str << endl;

    return 0;
}
