/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

struct info
{
    int l, r, id;
    bool type;
};

bool sortFunction(info &A, info &B)
{
    if (A.l == B.l)
        return A.type < B.type;
    else
        return A.l < B.l;
}
const int mx = 100005;
info ara[2 * mx];
int cnt[mx], ans[mx];

struct compare
{
    bool operator()(const PII &A, const PII &B)
    {
        if (A.first == B.first)
            return A.second < B.second;
        else
            return A.first < B.first;
    }
};
set<PII, compare> actor;
set<PII, compare>::iterator it;

int main()
{
    int i, n, m;
    PII A;
    bool chk = true;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d %d", &ara[i].l, &ara[i].r);
        ara[i].id = i;
        ara[i].type = true;
    }
    scanf("%d", &m);
    for (i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &ara[n + i].l, &ara[n + i].r, &cnt[i]);
        ara[n + i].id = i;
        ara[n + i].type = false;
    }
    sort(ara + 1, ara + m + n + 1, sortFunction);
    for (i = 1; i <= m + n; i++)
    {
        if (!ara[i].type)
            actor.insert(make_pair(ara[i].r, ara[i].id));
        else
        {
            A.first = ara[i].r, A.second = 0;
            it = actor.upper_bound(A);
            if (it == actor.end())
            {
                chk = false;
                break;
            }
            else
            {
                ans[ara[i].id] = it->second;
                cnt[it->second]--;
                if (cnt[it->second] == 0)
                    actor.erase(it);
            }
        }
    }
    if (!chk)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for (i = 1; i <= n; i++)
            printf("%d ", ans[i]);
    }

    return 0;
}
