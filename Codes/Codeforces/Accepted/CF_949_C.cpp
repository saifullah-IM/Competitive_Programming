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
typedef vector<ll> vl;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;

vi graph[maxn], scc[maxn], stk;
bool vis[maxn], mark[maxn];
int ara[maxn], cnt, Tm, start[maxn], low[maxn], in[maxn];

void tarjan(int u)
{
    vis[u] = true;
    start[u] = low[u] = ++Tm;
    stk.pb(u);

    for (int v : graph[u])
    {
        if (!low[v])
            tarjan(v);
        if (vis[v])
            low[u] = min(low[u], low[v]);
    }

    if (low[u] == start[u])
    {
        while (true)
        {
            int v = stk.back();
            stk.pop_back();
            scc[cnt + 1].pb(v);
            in[v] = cnt + 1;
            vis[v] = false;
            if (u == v)
            {
                cnt++;
                break;
            }
        }
    }
}

void dfs(int u)
{
    vis[u] = true;
    for (int v : graph[u])
    {
        if (in[u] != in[v])
            mark[in[u]] = true;
        if (!vis[v])
            dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, h;
    cin >> n >> m >> h;
    for (int i = 1; i <= n; i++)
        cin >> ara[i];

    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        int u = ara[l];
        int v = ara[r];
        if ((u + 1) % h == v)
        {
            graph[l].pb(r);
        }
        if ((v + 1) % h == u)
        {
            graph[r].pb(l);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (graph[i].empty())
        {
            cout << 1 << endl
                 << i << endl;
            return 0;
        }
        if (!low[i])
            tarjan(i);
    }

    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i);
    }

    int mn, ans;
    mn = n + 1, ans = -1;
    for (int i = 1; i <= cnt; i++)
    {
        if (mark[i])
            continue;
        if (scc[i].size() < mn)
        {
            mn = scc[i].size();
            ans = i;
        }
    }

    cout << mn << endl;
    for (int u : scc[ans])
        cout << u << ' ';
    cout << endl;

    return 0;
}