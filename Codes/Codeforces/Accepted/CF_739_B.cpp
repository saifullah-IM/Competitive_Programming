/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, ll>
using namespace std;

const int mx = 200005;
int ara[mx], cnt[mx], ans[mx];
vector<PII> edges[mx];
vector<PII> stk;
vector<PII>::iterator it;

bool compare(PII A, PII B)
{
    return A.second < B.second;
}

int dfs(int p, int u, ll dist)
{
    PII temp;
    temp.first = u;
    temp.second = dist - ara[u];
    stk.push_back(make_pair(u, dist));
    it = lower_bound(stk.begin(), stk.end(), temp, compare);
    if (it != stk.begin() && it != stk.end())
    {
        it--; //cout<<it->first<<' '<<u<<endl;
        if (p != it->first)
            cnt[it->first]++;
    }
    int i, v, m;

    m = edges[u].size();
    for (i = 0; i < m; i++)
    {
        v = edges[u][i].first;
        if (edges[u][i].second <= ara[v])
            ans[u]++;
        ans[u] += dfs(u, v, dist + edges[u][i].second);
    }
    stk.pop_back(); //cout<<u<<' '<<ans[u]<<' '<<cnt[u]<<endl;
    ans[u] -= cnt[u];
    return ans[u];
}

int main()
{
    int i, n, u, w;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &ara[i]);
    for (i = 2; i <= n; i++)
    {
        scanf("%d %d", &u, &w);
        edges[u].push_back(make_pair(i, w));
    }
    dfs(0, 1, 0);
    for (i = 1; i <= n; i++)
        printf("%d ", ans[i]);

    return 0;
}
