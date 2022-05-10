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
#define infll (1LL<<60)
#define abs(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define fbo(k) find_by_order(k) ///returns iterator to the kth largest element counting from 0
#define ook(val) order_of_key(val) ///returns the number of items in a set that are strictly smaller than val

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <int, ll> pll;
typedef vector <int> vi;
typedef set <int> si;
typedef multiset <int> msi;
typedef multiset <int>::iterator mit;
typedef map <int, int> mii;
typedef map <int, int>::iterator miit;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;

vector <pii> original_graph[mx];
vector <pii> modified_graph[mx * 102];

void build_graph(int n)
{
    for (int u = 1; u <= n; u++) {
        si weight_set;
        for (auto it: original_graph[u]) {
            modified_graph[it.fi].pb(mp(mx + 100 * u - 100 + it.se, it.se * it.se));
            modified_graph[mx + 100 * u - 50 + it.se].pb(mp(it.fi, it.se * it.se));
            weight_set.insert(it.se);
        }
        vi weights(weight_set.begin(), weight_set.end());
        for (auto it1: weights) {
            for (auto it2: weights) {
                modified_graph[mx + 100 * u - 100 + it1].pb(mp(mx + 100 * u - 50 + it2, 2 * it1 * it2));
            }
        }
    }
}

ll dist[mx * 102];
bool vis[mx * 102];

auto comp = [](pll A, pll B) {
    return A.se > B.se;
};
priority_queue <pll, vector <pll>, decltype(comp)> myPQ(comp);

void dijkstra()
{
    memset(dist, 63, sizeof(dist));
    dist[1] = 0; 
    myPQ.push(mp(1, 0));
 
    while (!myPQ.empty()) {
        pll A = myPQ.top();
        myPQ.pop();
        int u = A.fi;
        if (vis[u]) continue;
        vis[u] = true;

        for (auto it: modified_graph[u]) { 
            int v = it.fi;
            ll w = dist[u] + it.se;
            if (w < dist[v]) {
                dist[v] = w;
                myPQ.push(mp(v, w));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        original_graph[u].pb(mp(v, w));
        original_graph[v].pb(mp(u, w));
    }

    build_graph(n);
    dijkstra();
    for (int i = 1; i <= n; i++) {
        if (dist[i] > infll) cout << -1 << ' ';
        else cout << dist[i] << ' ';
    }

    return 0;
}