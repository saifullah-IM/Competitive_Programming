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
#define inf (1<<30)
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
typedef multiset <int>::iterator mit;
typedef map <int, int> mii;
typedef map <int, int>::iterator miit;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 2e5 + 5;
const int MOD = 1e9 + 7;

vi graph[mx], dist_node_list[mx];
int node_value[mx];
int mini[mx], maxi[mx], parent[mx];
int max_dist;
bool vis[mx];
ll dp[mx];

void preprocess(int n)
{
    max_dist = 0;
    for (int i = 1; i <= n; i++) {
        graph[i].clear();
        dist_node_list[i-1].clear();
        mini[i] = inf;
        maxi[i] = -1;
    }
}

void dfs(int u, int dist)
{
    vis[u] = true;
    max_dist = max(max_dist, dist);
    dist_node_list[dist].pb(u);
    mini[dist] = min(mini[dist], node_value[u]);
    maxi[dist] = max(maxi[dist], node_value[u]);
    //cout << "-----  "<< u << "  --u  " << dist  << " -- dist  " << maxi[dist] << " -- maxi  " << mini[dist] << " -- mini\n";
    for (int v: graph[u]) {
        if (vis[v]) continue;
        parent[v] = u;
        dfs(v, dist + 1);
    }
}

ll solve()
{
    ll ans = 0;
    dp[1] = 0;

    for (int i = 1; i <= max_dist; i++) {
        ll temp_plus, temp_minus;
        temp_plus = temp_minus = -inf;
        for (int u: dist_node_list[i]) {
            temp_plus = max(temp_plus, dp[parent[u]] + node_value[u]);
            temp_minus = max(temp_minus, dp[parent[u]] - node_value[u]);
        }
        for (int u: dist_node_list[i]) {
            dp[u] = dp[parent[u]] + max(maxi[i] - node_value[u], node_value[u] - mini[i]);
            dp[u] = max(dp[u], temp_plus - node_value[u]);
            dp[u] = max(dp[u], temp_minus + node_value[u]);
            ans = max(ans, dp[u]);
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int test;
    cin >> test;

    while(test--) {
        int n;
        cin >> n;
        preprocess(n);
        for (int i = 2; i <= n; i++) {
            int v;
            cin >> v;
            graph[i].pb(v);
            graph[v].pb(i);
        }
        for (int i = 2; i <= n; i++) cin >> node_value[i];

        memset(vis, 0, sizeof(vis));
        dfs(1, 0);
        cout << solve() << endl;
    }

    return 0;
}