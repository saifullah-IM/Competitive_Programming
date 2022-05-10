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

const int mx = 1e5 + 5;
///const int MOD=1e9+7;
vector<pii> graph[mx];
int MOD, n, PHI;

ll bigmod(ll x, ll n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * x) % MOD;
        n /= 2;
        x = (x * x) % MOD;
    }
    return res;
}
ll inv(int n)
{
    return bigmod(n, PHI - 1);
}
bool flag[mx];
vi primes;
void sieve()
{
    primes.pb(2);
    for (int i = 3; i < mx; i += 2)
        if (!flag[i])
        {
            primes.pb(i);
            for (ll j = (ll)i * i; j < mx; j += i)
                flag[j] = true;
        }
}
int phi(int n)
{
    int ans = n;
    for (int i = 0; (ll)primes[i] * primes[i] <= n; i++)
    {
        if (n % primes[i] == 0)
        {
            while (n % primes[i] == 0)
                n /= primes[i];
            ans -= ans / primes[i];
        }
    }
    if (n != 1)
        ans -= ans / n;
    return ans;
}

vi nodes;
int treesize, sz[mx];
bool vis[mx];
int dfs(int u, int p)
{
    if (p == -1)
        nodes.clear();
    nodes.pb(u);
    sz[u] = 1;
    for (auto it : graph[u])
    {
        int v = it.fi;
        if (!vis[v] && v != p)
        {
            sz[u] += dfs(v, u);
        }
    }
    if (p == -1)
        treesize = sz[u];
    return sz[u];
}

int findCent(int u, int p)
{
    for (auto it : graph[u])
    {
        int v = it.fi;
        if (!vis[v] && v != p)
        {
            if (sz[v] * 2 > treesize)
                return findCent(v, u);
        }
    }
    return u;
}

int parts = 0, dppart[mx], hi[mx];
ll down[mx], up[mx];
void prep(int u, int p, int cent)
{
    if (p == cent)
    {
        dppart[u] = parts;
        parts++;
    }
    else if (p != -1)
    {
        dppart[u] = dppart[p];
    }
    for (auto it : graph[u])
    {
        int v = it.fi;
        int w = it.se;
        if (!vis[v] && v != p)
        {
            hi[v] = hi[u] + 1;
            down[v] = (10 * down[u] + w) % MOD;
            up[v] = (bigmod(10, hi[u]) * w + up[u]) % MOD;
            prep(v, u, cent);
        }
    }
}

ll solve(int cent)
{
    for (int v : nodes)
    {
        up[v] = down[v] = hi[v] = 0;
    }
    parts = 0;
    prep(cent, -1, cent);
    dppart[cent] = -1;
    map<ll, ll> cnt;
    vector<map<ll, ll>> vec;
    vec.resize(parts + 1);
    cnt[0]++;
    for (int v : nodes)
    {
        if (v == cent)
            continue;
        cnt[up[v]]++;
        vec[dppart[v]][up[v]]++;
    }
    ll ans = 0;
    for (int v : nodes)
    {
        int pt = dppart[v];
        if (v == cent)
            ans += (cnt[0] - 1);
        else
        {
            ll val = (-down[v] % MOD + MOD) % MOD;
            val = (val * inv(bigmod(10, hi[v]))) % MOD;
            ans += (cnt[val] - vec[pt][val]);
        }
    }
    return ans;
}

ll comsolve(int u)
{
    dfs(u, -1);
    int cent = findCent(u, -1);
    ll ans = solve(cent);
    vis[cent] = true;
    for (auto it : graph[cent])
    {
        int v = it.fi;
        if (!vis[v])
            ans += comsolve(v);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> MOD;
    sieve();
    PHI = phi(MOD);
    if (MOD == 1)
    {
        cout << (ll)n * (n - 1) << endl;
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].pb(mp(v, w));
        graph[v].pb(mp(u, w));
    }
    cout << comsolve(0) << endl;

    return 0;
}
