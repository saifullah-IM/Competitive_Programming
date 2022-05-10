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

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;
vector<PII> edges[105];
int DP[105][105][27];
int solve(int u, int v, int x)
{
    if (edges[u].empty())
        return 0;
    if (DP[u][v][x] != -1)
        return DP[u][v][x];
    int ans = 0;
    for (PII A : edges[u])
    {
        if (A.second >= x)
        {
            int temp = solve(v, A.first, A.second);
            if (temp == 0)
            {
                ans = 1;
                break;
            }
        }
    }
    return DP[u][v][x] = ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        char ch;
        cin >> a >> b >> ch;
        edges[a].push_back(PII(b, ch - 'a'));
    }
    memset(DP, -1, sizeof(DP));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (solve(i, j, 0) == 1)
                cout << 'A';
            else
                cout << 'B';
        }
        cout << endl;
    }

    return 0;
}
