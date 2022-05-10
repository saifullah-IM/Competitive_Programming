/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
#define PII pair<int, int>
#define inf 2000000000
using namespace std;

int n, DP[1005][1005], ara[1005];
PII path[1005][1005];

int solve(int i, int j)
{
    if (j >= n)
    {
        path[i][j] = make_pair(i, j);
        return max(ara[i], ara[j]);
    }
    if (DP[i][j] != -1)
        return DP[i][j];

    int ans = -inf, temp;
    path[i][j] = make_pair(i, j);
    ans = max(ara[i], ara[j]) + solve(j + 1, j + 2);
    temp = max(ara[i], ara[j + 1]) + solve(j, j + 2);
    if (temp < ans)
    {
        ans = temp;
        path[i][j] = make_pair(i, j + 1);
    }
    temp = max(ara[j], ara[j + 1]) + solve(i, j + 2);
    if (temp < ans)
    {
        ans = temp;
        path[i][j] = make_pair(j, j + 1);
    }

    return DP[i][j] = ans;
}

int main()
{
    int i, k, ans, l, r;
    PII A;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &ara[i]);
    memset(DP, -1, sizeof(DP));
    ans = solve(0, 1);
    k = n / 2;

    printf("%d\n", ans);
    l = 0;
    r = 1;
    for (i = 0; i < k; i++)
    {
        A = path[l][r];
        printf("%d %d\n", A.first + 1, A.second + 1);
        if (l == A.first && r == A.second)
            l = r + 1;
        else if (l == A.first && r + 1 == A.second)
            l = r;
        r += 2;
    }
    if (n % 2)
        printf("%d\n", path[l][r].first + 1);

    return 0;
}
