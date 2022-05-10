/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 100005;
int money[mx], cost[mx];
ll sum[mx];

int main()
{
    int i, j, n, m, a, x, ans;
    ll temp;

    scanf("%d %d %d", &n, &m, &a);
    for (i = 0; i < n; i++)
        scanf("%d", &money[i]);
    for (i = 0; i < m; i++)
        scanf("%d", &cost[i]);
    sort(money, money + n);
    sort(cost, cost + m);
    sum[0] = cost[0];
    for (i = 1; i < m; i++)
        sum[i] = sum[i - 1] + cost[i];

    int HI, LO, MID;
    HI = min(m, n);
    LO = 1;
    x = ans = 0;
    while (LO <= HI)
    {
        MID = (LO + HI) / 2;
        int hi, lo, mid;
        bool chk = false;
        hi = n - MID;
        lo = 0;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            temp = 0;
            for (i = mid, j = 0; j < MID; i++, j++)
            {
                temp += max(cost[j] - money[i], 0);
            }
            if (temp <= a)
            {
                chk = true;
                x = MID;
                ans = max(sum[x - 1] - a, (ll)0);
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        if (chk)
            LO = MID + 1;
        else
            HI = MID - 1;
    }
    printf("%d %d", x, ans);

    return 0;
}
