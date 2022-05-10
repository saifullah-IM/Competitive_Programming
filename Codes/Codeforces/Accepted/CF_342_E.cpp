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

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;
const int block = 320;
vector<int> graph[mx], red;
int parent[mx][18], level[mx], fromRoot[mx];
bool vis[mx];
void dfs(int u, int d)
{
    vis[u] = true;
    fromRoot[u] = d;
    for (int v : graph[u])
    {
        if (!vis[v])
        {
            dfs(v, d + 1);
            parent[v][0] = u;
        }
    }
}
void sparseTable(int n)
{
    for (int j = 1; (1 << j) < n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[i][j - 1] != -1)
            {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}
int dist(int u, int v)
{
    if (fromRoot[u] < fromRoot[v])
        swap(u, v);
    int p = u, q = v;
    for (int i = 17; i >= 0; i--)
    {
        if (fromRoot[p] - (1 << i) >= fromRoot[q])
        {
            ///cout<<"-----"<<i<<' '<<p<<endl;
            p = parent[p][i];
            ///cout<<p<<endl;
        }
    } ///cout<<p<<' '<<q<<' '<<u<<' '<<v<<endl;
    if (p == q)
        return fromRoot[u] - fromRoot[v];
    for (int i = 17; i >= 0; i--)
    {
        if (parent[p][i] != -1 && parent[p][i] != parent[q][i])
        {
            p = parent[p][i];
            q = parent[q][i];
        }
    }
    return fromRoot[u] + fromRoot[v] - 2 * fromRoot[parent[p][0]];
}
void bfs()
{
    memset(level, -1, sizeof(level));
    queue<int> myQ;
    for (int u : red)
    {
        myQ.push(u);
        level[u] = 0;
    }
    while (!myQ.empty())
    {
        int u = myQ.front();
        myQ.pop();
        for (int v : graph[u])
        {
            if (level[v] == -1)
            {
                level[v] = 1 + level[u];
                myQ.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    memset(parent, -1, sizeof(parent));
    dfs(1, 0);
    sparseTable(n);
    red.push_back(1);
    vector<int> newred;
    int t, v;
    for (int i = 0; i < m; i++)
    {
        if (i % block == 0)
        {
            for (int u : newred)
                red.push_back(u);
            newred.clear();
            bfs();
        }
        cin >> t >> v;
        if (t == 1)
            newred.push_back(v);
        else
        {
            int ans = level[v];
            for (int u : newred)
                ans = min(ans, dist(u, v));
            cout << ans << endl;
        }
    }

    return 0;
}