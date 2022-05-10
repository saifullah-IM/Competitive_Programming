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

const int mx = 1e5 + 5;
const int block = 320;
typedef pair<PII, PII> PPI;
bool compare(PPI &A, PPI &B)
{
    int a = A.first.first / block;
    int b = B.first.first / block;
    if (a == b)
        return A.first.second < B.first.second;
    else
        return a < b;
}
int tree[mx], cnt[mx], start[mx], finish[mx], color[mx], ans[mx], ara[mx], res[mx], timer;
PPI query[mx];
vector<int> edges[mx];
bool vis[mx];
void dfs(int u)
{
    vis[u] = true;
    start[u] = ++timer;
    ara[timer] = u;
    for (int v : edges[u])
    {
        if (!vis[v])
            dfs(v);
    }
    finish[u] = timer;
}
void add(int u)
{
    ++res[++cnt[color[ara[u]]]];
}
void remove(int u)
{
    res[cnt[color[ara[u]]]--]--;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> color[i];
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs(1);
    for (int i = 0; i < m; i++)
    {
        int v, k;
        cin >> v >> k;
        query[i] = PPI(PII(start[v], finish[v]), PII(k, i));
    }
    sort(query, query + m, compare);
    int l = 0, r = -1;
    for (int i = 0; i < m; i++)
    {
        while (l > query[i].first.first)
            add(--l);
        while (r < query[i].first.second)
            add(++r);
        while (l < query[i].first.first)
            remove(l++);
        while (r > query[i].first.second)
            remove(r--);
        ans[query[i].second.second] = res[query[i].second.first];
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << endl;

    return 0;
}
