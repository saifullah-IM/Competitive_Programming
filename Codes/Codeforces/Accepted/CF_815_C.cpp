/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define infll ((ll)1 << 60)
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

const int mx = 5e3 + 5;
const int MOD = 1e9 + 7;
vi graph[mx];
ll dp[2][mx][mx];
int sz[mx], cost[mx], discount[mx];

void dfs(int u, int n)
{
    for (int i = 1; i <= n; i++)
    {
        dp[0][u][i] = dp[1][u][i] = infll;
    }
    dp[0][u][0] = 0, dp[0][u][1] = cost[u];
    dp[1][u][1] = cost[u] - discount[u], dp[1][u][0] = infll;
    sz[u] = 1;
    for (int v : graph[u])
    {
        dfs(v, n);
        for (int i = sz[u]; i > 0; i--)
        {
            for (int j = 1; j <= sz[v]; j++)
            {
                dp[1][u][i + j] = min(dp[1][u][i + j], min(dp[1][v][j], dp[0][v][j]) + dp[1][u][i]);
            }
        }
        for (int i = sz[u]; i >= 0; i--)
        {
            for (int j = 0; j <= sz[v]; j++)
            {
                dp[0][u][i + j] = min(dp[0][u][i + j], dp[0][u][i] + dp[0][v][j]);
            }
        }
        sz[u] += sz[v];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, b;
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i] >> discount[i];
        if (i > 1)
        {
            int p;
            cin >> p;
            graph[p].pb(i);
        }
    }
    dfs(1, n);

    for (int i = n; i >= 0; i--)
    {
        if (dp[0][1][i] <= b || dp[1][1][i] <= b)
        {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
