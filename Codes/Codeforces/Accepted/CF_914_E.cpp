/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define abs(X) ((X) > 0 ? (X) : (-(X)))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 2e5 + 5;
const int MOD = 1e9 + 7;
vi graph[mx];
int letter[mx], sz[mx], treesz;
bool vis[mx];

int dfs(int u, int p)
{
    sz[u] = 1;
    for (int v : graph[u])
    {
        if (!vis[v] && v != p)
            sz[u] += dfs(v, u);
    }
    if (p == -1)
        treesz = sz[u];
    return sz[u];
}
int findCent(int u, int p)
{
    for (int v : graph[u])
    {
        if (!vis[v] && v != p)
        {
            if (sz[v] * 2 > treesz)
                return findCent(v, u);
        }
    }
    return u;
}

ll sum, ans[mx];
int Timer;
int when[(1 << 21) + 5], cnt[(1 << 21) + 5];
void dfs1(int u, int p, int mask, int val)
{
    mask ^= letter[u];
    if (when[mask] != Timer)
    {
        when[mask] = Timer;
        cnt[mask] = 0;
    }
    cnt[mask] += val;
    for (int v : graph[u])
    {
        if (!vis[v] && v != p)
            dfs1(v, u, mask, val);
    }
}
ll dfs2(int u, int p, int mask)
{
    ll res = 0;
    mask ^= letter[u];
    for (int v : graph[u])
    {
        if (!vis[v] && v != p)
            res += dfs2(v, u, mask);
    }
    if (when[mask] == Timer)
        res += cnt[mask];
    if (mask == 0)
        sum++, res++;
    for (int i = 0; i < 21; i++)
    {
        int need = mask ^ (1 << i);
        if (when[need] == Timer)
            res += cnt[need];
        if (need == 0)
            res++, sum++;
    }
    ans[u] += res;
    return res;
}
void solve(int cent)
{
    Timer++;
    sum = 0;
    for (int v : graph[cent])
    {
        if (!vis[v])
            dfs1(v, cent, 0, 1);
    }
    for (int v : graph[cent])
    {
        if (!vis[v])
        {
            dfs1(v, cent, 0, -1);
            sum += dfs2(v, cent, letter[cent]);
            dfs1(v, cent, 0, 1);
        }
    }
    sum /= 2;
    ans[cent] += sum;
}
void compsolve(int u)
{
    dfs(u, -1);
    int cent = findCent(u, -1);
    solve(cent);
    vis[cent] = true;
    for (int v : graph[cent])
    {
        if (!vis[v])
            compsolve(v);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    string str;
    cin >> str;
    for (int i = 0; i < n; i++)
        letter[i + 1] = (1 << (str[i] - 'a'));
    compsolve(1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] + 1 << ' ';
    cout << endl;

    return 0;
}
