#include <bits/stdc++.h>
#define inf 2000000000000000000
using namespace std;

string str[100005];
int n, cost[100005];
long long DP[100005][2];

long long strtask(int i, int k)
{
    if (i >= n - 1)
        return DP[i][k] = 0;
    if (DP[i][k] != -1)
        return DP[i][k];

    long long ans = inf, temp;
    string S = str[i], T = str[i + 1];
    if (k == 1)
        reverse(S.begin(), S.end());
    reverse(T.begin(), T.end());

    if (S <= str[i + 1])
    {
        temp = strtask(i + 1, 0);
        if (temp >= 0)
            ans = min(ans, temp);
    }
    if (S <= T)
    {
        temp = cost[i + 1] + strtask(i + 1, 1);
        if (temp >= 0)
            ans = min(ans, temp);
    }

    if (ans == inf)
        ans = -inf;
    return DP[i][k] = ans;
}

int main()
{
    int i;
    long long ans, temp;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &cost[i]);
    for (i = 0; i < n; i++)
        cin >> str[i];
    memset(DP, -1, sizeof(DP));
    ans = strtask(0, 0);
    temp = cost[0] + strtask(0, 1);
    if (ans >= 0 && temp >= 0)
        ans = min(ans, temp);
    else
        ans = max(ans, temp);

    if (ans >= 0)
        printf("%lld\n", ans);
    else
        printf("-1\n");

    return 0;
}
