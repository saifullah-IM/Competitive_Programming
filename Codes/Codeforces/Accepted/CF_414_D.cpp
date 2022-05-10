/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 1e5 + 5;
vector<int> edges[mx];
int D, cnt[mx];
bool vis[mx];

void dfs(int u, int d)
{
    vis[u] = true;
    cnt[d]++;
    D = max(D, d);

    int i, v, m;
    m = edges[u].size();
    for (i = 0; i < m; i++)
    {
        v = edges[u][i];
        if (!vis[v])
        {
            dfs(v, d + 1);
        }
    }
}

int main()
{
    int i, n, k, p;

    scanf("%d %d %d", &n, &k, &p);
    for (i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    dfs(1, 1);
    cnt[1] = 0;

    int hi, lo;
    ll s, t, x, y, ans;

    hi = lo = 2;
    ans = 0;
    s = cnt[2];
    t = 2 * cnt[2];
    while (hi <= D)
    {
        x = hi * s - t; ///if (hi==lo) cout<<hi<<' '<<s<<' '<<t<<' '<<cnt[hi]<<endl;
        if (x <= p)
        {
            y = min((ll)cnt[lo - 1], (p - x) / (hi - lo + 1));
            ans = max(ans, s + y); ///cout<<hi<<' '<<lo<<' '<<ans<<endl;
            hi++;
            s += cnt[hi];
            t += (ll)hi * cnt[hi];
        }
        else
        {
            s -= cnt[lo];
            t -= (ll)lo * cnt[lo];
            lo++;
        }
    } ///cout<<ans<<endl;
    ans = min(ans, (ll)k);
    printf("%lld\n", ans);

    return 0;
}
