/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

const int mx = 2e5 + 5;
set<PII> myset;
vector<int> bids[mx];
int start[mx], finish[mx], ara[mx];

int main()
{
    int i, n, q, a, b;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &a, &b);
        bids[a].push_back(b);
    }
    for (i = 1; i <= n; i++)
        if (!bids[i].empty())
        {
            myset.insert(make_pair(-1 * bids[i].back(), i));
        }
    int t = n - 1;
    for (auto it : myset)
    {
        int m, k = it.second;
        m = bids[k].size();
        finish[k] = t;
        for (i = m - 1; i >= 0; i--)
            ara[t--] = bids[k][i];
        start[k] = t + 1;
    }

    scanf("%d", &q);
    for (i = 1; i <= q; i++)
    {
        int m;
        scanf("%d", &m);
        int ppl[m + 2];
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &ppl[j]);
            if (!bids[ppl[j]].empty())
                myset.erase(make_pair(-1 * bids[ppl[j]].back(), ppl[j]));
        }
        int u, v, k = myset.size();
        if (k == 0)
            printf("0 0\n");
        else if (k == 1)
        {
            u = myset.begin()->second;
            printf("%d %d\n", u, bids[u][0]);
        }
        else
        {
            auto it = myset.begin();
            u = it->second;
            it++;
            v = it->second;
            int ans = *lower_bound(ara + start[u], ara + finish[u] + 1, bids[v].back());
            printf("%d %d\n", u, ans);
        }
        for (int j = 0; j < m; j++)
        {
            if (!bids[ppl[j]].empty())
                myset.insert(make_pair(-1 * bids[ppl[j]].back(), ppl[j]));
        }
    }

    return 0;
}
