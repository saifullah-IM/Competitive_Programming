#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

bool sortfnc(PII A, PII B)
{
    return A.first < B.first;
}

int n, ans, DP[100005];
PII ara[100005];

int chain_reaction(int u)
{
    if (u <= 0)
    {
        ans = min(ans, n - u - 1);
        return 0;
    }
    if (DP[u] != -1)
        return DP[u];

    int i, m, k, v, hi, lo, mid;
    m = ara[u].first - ara[u].second;
    hi = u;
    lo = 0;
    while (lo <= hi)
    {
        mid = (hi + lo) / 2;
        if (ara[mid].first < m)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    DP[u] = u - hi - 1 + chain_reaction(hi);
    chain_reaction(u - 1);
    ans = min(ans, n - u - 1 + DP[u]);

    return DP[u];
}

int main()
{
    int i, u, v;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        ara[i].first = u;
        ara[i].second = v;
    }
    sort(ara, ara + n, sortfnc);

    memset(DP, -1, sizeof(DP));
    ans = 2000000000;
    chain_reaction(n - 1);
    printf("%d\n", ans);

    return 0;
}
