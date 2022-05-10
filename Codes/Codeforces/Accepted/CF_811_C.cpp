#include <bits/stdc++.h>
#define inf 2000000000
using namespace std;

int ara[5005], DP[5005], rngstr[5005], rngfns[5005], n;

int maxcomfort(int i)
{
    if (i >= n)
        return 0;
    if (DP[i] != -1)
        return DP[i];
    int X, j, ans, mx, mn, k;
    bool chk[5005];

    mx = ans = -inf;
    mn = i;
    X = 0;
    memset(chk, 0, sizeof(chk));
    for (j = i; j < n; j++)
    {
        mx = max(mx, rngfns[ara[j]]);
        mn = min(mn, rngstr[ara[j]]);
        if (!chk[ara[j]])
        {
            chk[ara[j]] = true;
            X ^= ara[j];
        }
        if (mx <= j && mn >= i)
            ans = max(ans, X + maxcomfort(j + 1));
        else
            ans = max(ans, maxcomfort(j + 1));
    }

    return DP[i] = ans;
}

int main()
{
    int i, ans;

    scanf("%d", &n);
    memset(rngfns, -1, sizeof(rngfns));
    memset(rngstr, 63, sizeof(rngstr));
    memset(DP, -1, sizeof(DP));

    for (i = 0; i < n; i++)
    {
        scanf("%d", &ara[i]);
        rngstr[ara[i]] = min(rngstr[ara[i]], i);
        rngfns[ara[i]] = max(rngfns[ara[i]], i);
    }
    ans = maxcomfort(0);
    printf("%d\n", ans);

    return 0;
}
