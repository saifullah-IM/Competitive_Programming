/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 3005;
vector<int> edges[mx];

int main()
{
    int i, n, m, u, v, k, j, l, t;
    ll ans, ara[3005];

    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
    }
    ans = 0;
    for (i = 1; i <= n; i++)
    {
        memset(ara, 0, sizeof(ara));
        k = edges[i].size();
        for (j = 0; j < k; j++)
        {
            u = edges[i][j];
            t = edges[u].size();
            for (l = 0; l < t; l++)
            {
                v = edges[u][l];
                ara[v]++;
            }
        }
        for (j = 1; j <= n; j++)
            if (i != j)
                ans += (ara[j] * (ara[j] - 1)) / 2;
    }
    printf("%lld\n", ans);

    return 0;
}
