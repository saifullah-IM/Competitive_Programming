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

vi graph[mx];
int vis[mx], odd[mx], even[mx], oddpath[mx], evenpath[mx];
void dfs(int p, int u, int d)
{ ///cout<<u<<endl;
    vis[u]++;
    if (d % 2)
    {
        odd[u] = true;
        oddpath[u] = p;
    }
    else
    {
        even[u] = true;
        evenpath[u] = p;
    }
    for (int v : graph[u])
    {
        if (vis[v] == 0)
            dfs(u, v, d + 1);
        else if (vis[v] == 1)
        {
            if (odd[v] && d % 2 == 1)
                dfs(u, v, d + 1);
            else if (even[v] && d % 2 == 0)
                dfs(u, v, d + 1);
        }
    }
}

bool vv[mx], rec[mx];
bool dfsCycle(int u)
{
    int i, v, n;
    if (!vv[u])
    {
        vv[u] = true;
        rec[u] = true;
        n = graph[u].size();
        for (i = 0; i < n; i++)
        {
            v = graph[u][i];
            if (!vv[v] && !dfsCycle(v))
                return false;
            else if (rec[v])
                return false;
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
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        while (x--)
        {
            int u;
            cin >> u;
            graph[i].pb(u);
        }
    }
    int s;
    cin >> s;
    dfs(0, s, 0);
    int win;
    win = -1;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
            continue;
        if (odd[i] && graph[i].empty())
            win = i;
    }
    if (win == -1)
    {
        bool lose = dfsCycle(s);
        if (lose)
            cout << "Lose" << endl;
        else
            cout << "Draw" << endl;
    }
    else
    {
        vi path;
        int i = 0;
        while (win != 0)
        {
            path.pb(win);
            if (i % 2 == 0)
                win = oddpath[win];
            else
                win = evenpath[win];
            i++;
        }
        assert(path.back() == s);
        assert(path.size() % 2 == 0);
        cout << "Win" << endl;
        for (int i = path.size() - 1; i >= 0; i--)
            cout << path[i] << ' ';
        cout << endl;
    }

    return 0;
}
