/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int mx = 1e5 + 5;
vector<PII> edges[mx];
int DP[3 * mx], temp[3 * mx];

int main()
{
    int i, n, m, ans = 0;
    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[w].push_back(PII(u, v));
    }
    for (i = 1; i < mx; i++)
    {
        for (int j = 0; j < edges[i].size(); j++)
            temp[edges[i][j].second] = 0;
        for (int j = 0; j < edges[i].size(); j++)
        {
            int u = edges[i][j].first, v = edges[i][j].second;
            temp[v] = max(temp[v], DP[u] + 1);
        }
        for (int j = 0; j < edges[i].size(); j++)
        {
            int u = edges[i][j].first, v = edges[i][j].second;
            DP[v] = max(temp[v], DP[v]);
        }
    }
    for (i = 1; i <= n; i++)
        ans = max(ans, DP[i]);
    printf("%d\n", ans);

    return 0;
}
