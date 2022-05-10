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
bool vis[mx], rec[mx];
ll dp[mx];
int edges[mx], level[mx];
void prep()
{
    dp[0] = 1;
    for (int i = 1; i < mx; i++)
        dp[i] = (dp[i - 1] * 2) % MOD;
}
int dfsCycle(int u, int d)
{
    level[u] = d;
    if (!vis[u])
    {
        vis[u] = true;
        rec[u] = true;
        int v = edges[u];
        if (!vis[v])
        {
            int x = dfsCycle(v, d + 1);
            if (x)
            {
                rec[u] = false;
                return x;
            }
        }
        else if (rec[v])
        {
            rec[u] = false;
            return level[u] - level[v] + 1;
        }
    }

    rec[u] = false;
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n, q;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        edges[i] = m;
    }
    prep();
    ll ans = 1;
    q = n;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int x = dfsCycle(i, 0);
            assert(x != 1);
            if (x > 1)
            {
                ans = (ans * (dp[x] - 2)) % MOD;
                q -= x;
            }
            ///cout<<ans<<' '<<x<<' '<<i<<endl;
        }
    }
    assert(q >= 0);
    ans = (ans * dp[q]) % MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << endl;

    return 0;
}
