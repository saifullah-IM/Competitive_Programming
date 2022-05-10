#include <bits/stdc++.h>
using namespace std;/*
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
#define inf INT_MAX/2
#define infll (1LL<<62)
#define abs(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define fbo(k) find_by_order(k) ///returns iterator to the kth largest element counting from 0
#define ook(val) order_of_key(val) ///returns the number of items in a set that are strictly smaller than val

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef set <int> si;
typedef multiset <int> msi;
typedef map <int, int> mii;
typedef map <int, int>::iterator miit;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;

vi graph[mx];
bool vis[mx];
vi odd, even;

void dfs_tree(int u, bool is_even)
{
    vis[u] = true;
    if (is_even) even.pb(u);
    else odd.pb(u);

    for (int v : graph[u]) {
        if (!vis[v]) {
            dfs_tree(v, !is_even);
        }
    }

    return;
}

void solve_for_tree(int n, int k)
{
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    dfs_tree(1, true);

    k = ceil(k / 2.0);
    cout << 1 << endl;
    if (odd.size() >= k) {
        for (int i = 0; i < k; i++) {
            cout << odd[i];
            if (i != k - 1) cout << ' ';
        }
    }
    else {
        for (int i = 0; i < k; i++) {
            cout << even[i];
            if (i != k - 1) cout << ' ';
        }
    }

    cout << endl;
    return;
}


int parent[mx];
int depth[mx];

pii find_minimum_cycle(int u, int d)
{
    vis[u] = true;
    depth[u] = d;
    //cout << "depth  (" << u << ", " << d << ")\n";
    pii ans = mp(inf, -1);
    
    for (int v : graph[u]) {
        if (!vis[v]) {
            parent[v] = u;
            pii temp = find_minimum_cycle(v, d + 1);
            if (temp.fi < ans.fi) ans = temp;
        }
        else if (v != parent[u]) {
            if (depth[u] > depth[v]) {
                pii temp = mp(depth[u] - depth[v] + 1, u);
                if (temp.fi < ans.fi) ans = temp;
            }
        }
    }

    return ans;
}

void solve_for_cycle(int n, int m, int k)
{
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    parent[1] = -1;
    pii temp = find_minimum_cycle(1, 0);

    int u = temp.se;
    int len = temp.fi;
    vi ans;

    for (int i = 1; i <= len; i++) {
        assert(u >= 1);
        ans.pb(u);
        u = parent[u];
    }

    if (len <= k) {
        cout << 2 << endl;
        cout << len << endl;
        k = len;
        for (int i = 0; i < k; i++) {
            cout << ans[i];
            if (i != k - 1) cout << ' ';
        }
    }
    else {
        cout << 1 << endl;
        k = ceil(k / 2.0);
        for (int i = 0; i < k; i++) {
            cout << ans[2 * i];
            if (i != k - 1) cout << ' ';
        }
    }

    cout << endl;
    return;
}

int main ()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    if (m == n - 1) solve_for_tree(n, k);
    else solve_for_cycle(n, m, k);

    return 0;
}
