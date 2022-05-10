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

const int mx = 1e6 + 5;
const int MOD = 1e9 + 7;
pii edge[mx], info[mx];
int comp[1005], grp[1005];
vi vertex[1005];
int m, n, q;
void init()
{
    for (int i = 1; i <= n; i++)
    {
        comp[i] = i;
        grp[i] = 0;
        vertex[i].clear();
        vertex[i].pb(i);
    }
}
void merge(int u, int v)
{
    int k = grp[u] == grp[v];
    u = comp[u], v = comp[v];
    if (vertex[u].size() < vertex[v].size())
        swap(u, v);
    while (!vertex[v].empty())
    {
        int x = vertex[v].back();
        vertex[v].pop_back();
        comp[x] = u;
        grp[x] ^= k;
        vertex[u].pb(x);
    }
}
int query(int l, int r)
{
    init();
    for (int i = m; i > 0; i--)
    {
        if (edge[i].second > r || edge[i].second < l)
            continue;
        int j = edge[i].second;
        int u = info[j].first, v = info[j].second;
        if (comp[u] == comp[v])
        {
            if (grp[u] == grp[v])
                return edge[i].first;
            continue;
        }
        merge(u, v);
    }
    return -1;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edge[i] = mp(w, i);
        info[i] = mp(u, v);
    }
    sort(edge + 1, edge + m + 1);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << endl;
    }

    return 0;
}
