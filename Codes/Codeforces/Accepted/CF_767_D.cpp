/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

struct info
{
    int first, id;
    bool second;
};
const int mx = 2000005;
vector<int> res;
info ara[mx];
bool sortFunction(info A, info B)
{
    if (A.first == B.first)
        return A.second < B.second;
    else
        return A.first < B.first;
}
int main()
{
    int i, n, m, k, ans, cnt, day;

    scanf("%d %d %d", &n, &m, &k);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ara[i].first);
        ara[i].second = false;
        ara[i].id = -1;
    }
    for (i = n; i < m + n; i++)
    {
        scanf("%d", &ara[i].first);
        ara[i].second = true;
        ara[i].id = i - n + 1;
    }
    sort(ara, ara + n, sortFunction);
    for (i = 0; i < n; i++)
        if ((i / k) > ara[i].first)
            break;
    if (i != n)
    {
        printf("-1\n");
        return 0;
    }
    day = ara[n - 1].first;
    cnt = 0;
    for (i = n - 1; i >= 0; i--)
    {
        if (ara[i].first == day)
            cnt++;
        else
        {
            day = ara[n - 1].first;
            cnt = 1;
        }
        if (cnt > k)
            ara[i].first -= (cnt - 1) / k;
    }
    sort(ara, ara + n + m, sortFunction);
    ans = day = 0;
    cnt = k;
    for (i = 0; i < m + n; i++)
    {
        if (cnt == 0)
        {
            day++;
            cnt = k;
        }
        if (day <= ara[i].first)
        {
            cnt--;
            if (ara[i].second)
            {
                ans++;
                res.push_back(ara[i].id);
            }
        }
    }
    printf("%d\n", ans);
    for (i = 0; i < res.size(); i++)
        printf("%d ", res[i]);

    return 0;
}
