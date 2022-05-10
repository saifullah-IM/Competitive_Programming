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

const int MX = 505;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;

int cost[2][MX][MX];
int dist[MX][MX];
bool vis[MX][MX];

struct node
{
    int x, y, w, d;
    node(int _x, int _y, int _w, int _d)
    {
        x = _x;
        y = _y;
        w = _w;
        d = _d;
    }
};

auto comp = [](node A, node B) {
    return A.w > B.w;
};
priority_queue<node, vector<node>, decltype(comp)> myPQ(comp);

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int get_cost(int x, int y, int fx, int fy)
{
    if (x == fx)
        return cost[0][x][min(y, fy)];
    else if (y == fy)
        return cost[1][min(x, fx)][y];
    else
        exit(-1);
}

int dijkstra(int _x, int _y, int k, int n, int m)
{
    for (int i = max(0, i - k); i < _x + k; i++)
        for (int j = max(0, j - k); j < _y + k; j++)
        {
            if (abs(_x - i) + abs(_y - j) > k)
                break;
            dist[i][j] = inf;
            vis[i][j] = false;
        }

    dist[_x][_y] = 0;
    while (!myPQ.empty())
        myPQ.pop();
    myPQ.push(node(_x, _y, 0, 0));

    int ans = inf;
    int half_k = k / 2;
    while (!myPQ.empty())
    {
        auto it = myPQ.top();
        myPQ.pop();
        int x = it.x;
        int y = it.y;
        int d = it.d;
        if (vis[x][y] || d)
            continue;
        vis[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int fx = x + dx[i];
            int fy = y + dy[i];

            if (fx < 0 || fx >= m || fy < 0 || fy >= m)
                continue;

            int w = dist[x][y] + get_cost(x, y, fx, fy);
            if (w < dist[fx][fy])
            {
                path[v] = path[u] + edges[u][i].x;
                dist[v] = w;
                myPQ.push(node(v, path[v], w));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    //cin >> test;
    while (test--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m - 1; j++)
                cin >> cost[0][i][j];
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < m; j++)
                cin >> cost[1][i][j];
    }

    return 0;
}