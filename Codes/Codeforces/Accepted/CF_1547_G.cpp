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
#define inf (1 << 30)
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
typedef multiset<int>::iterator mit;
typedef map<int, int> mii;
typedef map<int, int>::iterator miit;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int MX = 4e5 + 5;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;

void dfs_mark(int u, vector<vi> &graph, vi &mark)
{
    mark[u] = 1;
    for (int v : graph[u])
    {
        if (mark[v] == 0)
            dfs_mark(v, graph, mark);
        else if (mark[v] == 1)
            mark[v] = -1;
        else if (mark[v] == 3)
            mark[v] = 2;
    }
    if (mark[u] == 1)
        mark[u] = 3;
}

void dfs_ans(int u, vector<vi> &graph, vi &ans, int res)
{
    ans[u] = res;
    //cout << "--------   " << u << ' ' << res << ' ' << ans[u] << "\n\n";
    for (int v : graph[u])
    {
        //cout << "_________   " << u << ' ' << v << ' ' << res << "\n\n";
        if (ans[v] != res)
            dfs_ans(v, graph, ans, res);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tests;
    cin >> tests;

    for (int test = 1; test <= tests; test++)
    {
        int n, m;
        cin >> n >> m;
        vector<vi> graph(n + 2, vi());
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            graph[u].pb(v);
        }

        vi mark(n + 2, 0);
        dfs_mark(1, graph, mark);

        vi ans(mark);
        for (int i = 1; i <= n; i++)
        {
            if (mark[i] == 2)
                dfs_ans(i, graph, ans, 2);
        }
        for (int i = 1; i <= n; i++)
        {
            if (mark[i] == -1)
                dfs_ans(i, graph, ans, -1);
        }
        for (int i = 1; i <= n; i++)
        {
            if (ans[i] == 3)
                ans[i] = 1;
            cout << ans[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}