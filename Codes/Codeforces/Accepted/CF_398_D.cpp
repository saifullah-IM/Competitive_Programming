/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define mp make_pair
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define abs(X) ((X) > 0 ? (X) : (-(X)))
using namespace std;

//cout << fixed << setprecision(12) << p << endl;

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VP;

template <class T>
inline T bigmod(T p, T e, T M)
{
    ll ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1)
            ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T>
inline T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) { return bigmod(a, M - 2, M); }

const int mx = 5e4 + 5;
const int block = 450;
vector<int> graph[mx], inHeavy[mx];
map<int, int> edge[mx];
int online[mx], cntLight[mx];
void add(int u, int v)
{
    graph[u].push_back(v);
    edge[u][v] = graph[u].size() - 1;
    if (graph[u].size() <= block)
    {
        if (online[u])
            cntLight[v]++;
    }
    if (graph[u].size() == block)
    {
        for (int i = 0; i < graph[u].size(); i++)
        {
            int w = graph[u][i];
            if (w > 0)
            {
                cntLight[w] -= online[u];
                inHeavy[w].push_back(u);
            }
            else
                inHeavy[-w].push_back(-u);
        }
    }
    if (graph[u].size() > block)
        inHeavy[v].push_back(u);
}
void modify(int u, int v)
{
    int k = edge[u][v];
    graph[u][k] *= -1;
    if (graph[u].size() < block)
    {
        if (online[u])
            cntLight[v] += (graph[u][k] > 0 ? +1 : -1);
    }
    else
    {
        for (int i = 0; i < inHeavy[v].size(); i++)
        {
            int &w = inHeavy[v][i];
            if (w == -u)
            {
                w = u;
                return;
            }
            if (w == u)
            {
                w = -u;
                return;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n, q, on;
    cin >> n >> m >> q >> on;
    for (int i = 0; i < on; i++)
    {
        int x;
        cin >> x;
        online[x] = 1;
    }
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        add(u, v);
        add(v, u);
    }
    while (q--)
    {
        char ch;
        int u, v;
        cin >> ch >> u;
        if (ch == 'O' || ch == 'F')
        {
            online[u] ^= 1;
            if (graph[u].size() < block)
            {
                for (int i = 0; i < graph[u].size(); i++)
                {
                    int w = graph[u][i];
                    if (w > 0)
                        cntLight[w] += (online[u] ? +1 : -1);
                }
            }
        }
        else if (ch == 'A')
        {
            cin >> v;
            if (edge[u].find(v) == edge[u].end())
            {
                add(u, v);
                add(v, u);
            }
            else
            {
                modify(u, v);
                modify(v, u);
            }
        }
        else if (ch == 'D')
        {
            cin >> v;
            modify(u, v);
            modify(v, u);
        }
        else
        {
            int ans = cntLight[u];
            for (int v : inHeavy[u])
                if (v > 0)
                    ans += online[v];
            cout << ans << endl;
        }
    }

    return 0;
}