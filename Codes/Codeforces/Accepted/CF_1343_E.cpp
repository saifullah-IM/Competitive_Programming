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
int weights[mx];
ll cumWeights[mx];
int dist[3][mx];

void bfs(int start, int flag)
{
    queue<int> myQ;
    dist[flag][start] = 0;
    myQ.push(start);

    while (!myQ.empty())
    {
        int u = myQ.front();
        myQ.pop();
        for (int v : graph[u])
        {
            if (dist[flag][v] != -1)
                continue;
            dist[flag][v] = dist[flag][u] + 1;
            myQ.push(v);
        }
    }
}

ll solve(int start, int m)
{
    sort(weights, weights + m);
    for (int i = 1; i <= m; i++)
        cumWeights[i] = cumWeights[i - 1] + weights[i - 1];

    ll ans = infll;
    queue<int> myQ;
    dist[1][start] = 0;
    myQ.push(start);

    while (!myQ.empty())
    {
        int u = myQ.front();
        myQ.pop();

        int edges = dist[0][u] + dist[1][u] + dist[2][u];
        if (edges <= m + 3)
        {
            ll temp = cumWeights[dist[1][u] - 1] + cumWeights[edges - 3];
            ans = min(ans, temp);
        }
        //cout << "debug " << ans << " u " << u << " edges " << edges << endl;

        for (int v : graph[u])
        { //cout<<"uv  " << u << ' '<<v<<endl;
            if (dist[1][v] != -1)
                continue;
            dist[1][v] = dist[1][u] + 1;
            myQ.push(v);
        }
    }

    return ans;
}

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
            dist[j][i] = -1;
        graph[i].clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin >> test;
    while (test--)
    {
        int n, m, a, b, c;
        cin >> n >> m >> a >> b >> c;
        init(n + 3);

        for (int i = 0; i < m; i++)
            cin >> weights[i];
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].pb(v);
            graph[v].pb(u);
        }
        graph[a].pb(n + 1);
        graph[n + 1].pb(a);
        graph[b].pb(n + 2);
        graph[n + 2].pb(b);
        graph[c].pb(n + 3);
        graph[n + 3].pb(c);

        bfs(n + 1, 0);
        bfs(n + 3, 2);
        cout << solve(n + 2, m) << endl;
    }

    return 0;
}
