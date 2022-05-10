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

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;
vector<pii> graph[505], stk;
vi edges;
int baad;
bool vis[505], rec[505];
bool dfsCycle(int u, bool chk)
{
    if (!vis[u])
    {
        vis[u] = rec[u] = true;
        for (auto it : graph[u])
        {
            int v = it.fi;
            if (it.se == baad)
                continue;
            if (!vis[v])
            {
                if (chk)
                    stk.pb(mp(u, it.se));
                if (!dfsCycle(v, chk))
                    return false;
                if (chk)
                    stk.pop_back();
            }
            else if (rec[v])
            {
                if (!chk)
                    return false;
                edges.pb(it.se);
                while (true)
                {
                    auto A = stk.back();
                    stk.pop_back();
                    edges.pb(A.se);
                    if (A.fi == v)
                        break;
                }
                return false;
            }
        }
    }

    rec[u] = false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(mp(v, i));
    }
    bool chk = true;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            chk = dfsCycle(i, true);
        if (!chk)
            break;
    }
    if (chk)
    {
        cout << "YES" << endl;
        return 0;
    }
    for (int x : edges)
    {
        baad = x;
        chk = true;
        memset(vis, 0, sizeof(vis));
        memset(rec, 0, sizeof(rec));
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                chk = dfsCycle(i, false);
            if (!chk)
                break;
        }
        if (chk)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}
