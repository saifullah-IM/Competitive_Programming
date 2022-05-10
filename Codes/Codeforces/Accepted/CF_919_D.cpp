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

const int mx = 3e5 + 5;
const int MOD = 1e9 + 7;
vector<int> edges[mx];
string str;
int res, DP[mx][27];
bool vis[mx], rec[mx];
bool solve(int u)
{
    int i, v, n;
    int ans[26];
    memset(ans, 0, sizeof(ans));
    if (!vis[u])
    {
        vis[u] = true;
        rec[u] = true;
        n = edges[u].size();
        for (i = 0; i < n; i++)
        {
            v = edges[u][i];
            if (!vis[v])
            {
                bool temp = solve(v);
                if (!temp)
                    return false;
            }
            else if (rec[v])
                return false;
            for (int i = 0; i < 26; i++)
            {
                ans[i] = max(ans[i], DP[v][i]);
            }
        }
        DP[u][str[u - 1] - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            DP[u][i] += ans[i];
            res = max(res, DP[u][i]);
        }
    }

    rec[u] = false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> n >> m;
    cin >> str;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }
    bool ans = true;
    for (int i = 1; i <= n; i++)
        if (!vis[i])
            ans = (ans & solve(i));
    if (!ans)
        cout << -1 << endl;
    else
        cout << res << endl;

    return 0;
}
