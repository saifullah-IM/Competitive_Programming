/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define mp make_pair
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define abs(X) ((X) > 0 ? (X) : (-(X)))
using namespace std;

///cout << fixed << setprecision(12) << p << endl;

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VP;

const int mx = 2e5 + 5;
const int MOD = 1e9 + 7;
vector<int> graph[mx], cc[mx];
int n, parent[mx];
int Find(int u)
{
    if (parent[u] == u)
        return u;
    else
        return parent[u] = Find(parent[u]);
}
void Union(int u, int v)
{
    int m = Find(u);
    int n = Find(v);
    if (m != n)
    {
        parent[m] = n;
    }
}
set<int> nodes;
void dfs(int u)
{
    nodes.erase(u);
    int mini = 0;
    while (!nodes.empty())
    {
        auto vt = nodes.upper_bound(mini);
        if (vt == nodes.end())
            return;
        int v = *vt;
        mini = v;
        auto it = lower_bound(graph[u].begin(), graph[u].end(), v);
        if (it != graph[u].end() && *it == v)
        {
            continue;
        }
        ///cout<<"union       "<<u<<' '<<v<<endl;
        Union(u, v);
        dfs(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        nodes.insert(i);
        sort(graph[i].begin(), graph[i].end());
    }
    while (!nodes.empty())
    {
        auto it = nodes.begin();
        dfs(*it);
    }
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        int k = Find(i);
        cc[k].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        if (!cc[i].empty())
            ans.push_back(cc[i].size());
    cout << ans.size() << endl;
    sort(ans.begin(), ans.end());
    for (int u : ans)
        cout << u << ' ';
    cout << endl;

    return 0;
}
