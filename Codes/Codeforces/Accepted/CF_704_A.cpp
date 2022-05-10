#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

set<int> apps[300005];
int main()
{
    int i, j, n, q, u, v, p, ans;
    set<PII> myset;

    ans = 0;
    j = 1;
    scanf("%d %d", &n, &q);
    for (i = 1; i <= q; i++)
    {
        scanf("%d %d", &u, &v);
        if (u == 1)
        {
            ans++;
            myset.insert(make_pair(j, v));
            apps[v].insert(j);
            j++;
        }
        if (u == 2)
        {
            ans -= apps[v].size();
            apps[v].clear();
        }
        if (u == 3)
        {
            while (!myset.empty() && myset.begin()->first <= v)
            {
                p = myset.begin()->second;
                if (!apps[p].empty() && *apps[p].begin() <= v)
                {
                    ans--;
                    apps[p].erase(apps[p].begin());
                }
                myset.erase(myset.begin());
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
