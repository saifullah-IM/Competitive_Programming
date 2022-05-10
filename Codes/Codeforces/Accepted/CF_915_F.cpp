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
int parent[mx], val[mx], sz[mx], idx[mx];
bool cmp(int i, int j)
{
    return val[i] < val[j];
}
int Find(int u)
{
    if (parent[u] == u)
        return u;
    else
        return parent[u] = Find(parent[u]);
}
vi tree[mx];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
        idx[i] = i;
        parent[i] = i;
    }
    sort(idx + 1, idx + n + 1, cmp);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].pb(v);
        tree[v].pb(u);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = idx[i];
        ll temp = 1;
        for (int v : tree[u])
        {
            if (sz[v])
            {
                temp += sz[Find(v)];
                temp += (ll)sz[u] * sz[parent[v]];
                sz[u] += sz[parent[v]];
                parent[parent[v]] = u;
            }
        }
        sz[u]++;
        ans += temp * val[u];
    }

    for (int i = 1; i <= n; i++)
    {
        sz[i] = 0;
        parent[i] = i;
    }
    for (int i = n; i > 0; i--)
    {
        int u = idx[i];
        ll temp = 1;
        for (int v : tree[u])
        {
            if (sz[v])
            {
                temp += sz[Find(v)];
                temp += (ll)sz[u] * sz[parent[v]];
                sz[u] += sz[parent[v]];
                parent[parent[v]] = u;
            }
        }
        sz[u]++;
        ans -= temp * val[u];
    }
    cout << ans << endl;

    return 0;
}
