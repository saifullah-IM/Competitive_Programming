/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std; /*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;*/

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define infll (1LL << 62)
#define abs(X) ((X) > 0 ? (X) : (-(X)))
#define fbo(k) find_by_order(k)    ///returns iterator to the kth largest element counting from 0
#define ook(val) order_of_key(val) ///returns the number of items in a set that are strictly smaller than val

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 2e5 + 5;
const int MOD = 1e9 + 7;
vi graph[mx];
int n, k, dp[mx][6];
ll ans, cnt[6];
bool vis[mx];
int dfs(int u)
{
    vis[u] = true;
    dp[u][0] = 1;
    int sz = 1;
    for (int v : graph[u])
    {
        if (vis[v])
            continue;
        int sv = dfs(v);
        sz += sv;
        ans += (ll)sv * (n - sv);
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cnt[(i + j + 1) % k] += (ll)dp[u][i] * dp[v][j];
            }
        }
        for (int i = 0; i < k; i++)
        {
            dp[u][(i + 1) % k] += dp[v][i];
        }
    }
    ///cout<<u<<' '<<dp[u][1]<<endl;
    return sz;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs(1);
    ///cout<<ans<<endl;
    for (int i = 1; i < k; i++)
    {
        ans += (k - i) * cnt[i];
        ///cout<<i<<' '<<temp[i]<<endl;
    }
    ans /= k;
    cout << ans << endl;

    return 0;
}
