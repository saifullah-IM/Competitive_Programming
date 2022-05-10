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
vector<pll> graph[mx];
ll dist[mx];
bool vis[mx];
auto comp = [](pll A, pll B)
{ return A.se > B.se; };
priority_queue<pll, vector<pll>, decltype(comp)> myPQ(comp);
void dijkstra(int n)
{
    for (int i = 1; i <= n; i++)
        dist[i] = infll;
    myPQ.push(mp(0, 0));
    while (!myPQ.empty())
    {
        auto it = myPQ.top();
        myPQ.pop();
        if (vis[it.fi])
            continue;
        vis[it.fi] = true;
        for (auto A : graph[it.fi])
        {
            ll w = dist[it.fi] + A.se;
            if (w < dist[A.fi])
            {
                dist[A.fi] = w;
                myPQ.push(mp(A.fi, w));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].pb(mp(v, w * 2));
        graph[v].pb(mp(u, w * 2));
    }
    for (int i = 1; i <= n; i++)
    {
        ll w;
        cin >> w;
        graph[0].pb(mp(i, w));
    }
    dijkstra(n);
    for (int i = 1; i <= n; i++)
        cout << dist[i] << ' ';
    cout << endl;

    return 0;
}
