/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
#define inf 1061109567
using namespace std;

int n, ara[100005], DP[100005][2][3];

int max_sum(int i, int j, int k)
{
    if (i == n)
        return 0;
    if (DP[i][j][k] != inf)
        return DP[i][j][k];

    int ans, temp;
    temp = -inf;

    if (j == 0)
        ans = ara[i];
    else
        ans = -ara[i];

    if (k == 0)
    {
        temp = max(temp, max_sum(i + 1, j, 0));
        temp = max(temp, max_sum(i + 1, j ^ 1, 1));
        temp = max(temp, max_sum(i + 1, j, 2));
    }
    else if (k == 1)
    {
        temp = max(temp, max_sum(i + 1, j, 1));
        temp = max(temp, max_sum(i + 1, j ^ 1, 2));
    }
    else
        temp = max(temp, max_sum(i + 1, j, k));

    return DP[i][j][k] = ans + temp;
}

int main()
{
    int i, ans;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &ara[i]);
    memset(DP, 63, sizeof(DP));
    ans = -inf;
    ans = max(ans, max_sum(0, 1, 0));
    ans = max(ans, max_sum(0, 0, 1));
    printf("%d", ans);

    return 0;
}
