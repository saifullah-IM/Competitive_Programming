/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
using namespace std;

int DP[5005][5005], cnt[5005];
long long ans[5005];
char str[5005];

int palindrome(int i, int j)
{
    if (DP[i][j] != -1)
        return DP[i][j];
    if (i == j)
        return DP[i][j] = 1;
    if (i + 1 == j)
    {
        if (str[i] == str[j])
            return DP[i][j] = 2;
        else
            return DP[i][j] = 0;
    }

    if (str[i] != str[j] || palindrome(i + 1, j - 1) == 0)
        return DP[i][j] = 0;

    int m;
    m = ceil(((i + j) * 1.0) / 2.0) - 1;
    return DP[i][j] = palindrome(i, m) + 1;
}

int main()
{
    int i, j, n, k;

    scanf("%s", str);
    n = strlen(str);
    memset(DP, -1, sizeof(DP));
    palindrome(0, n - 1);
    k = -1;

    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
        {
            if (palindrome(i, j) > 0)
                cnt[DP[i][j]]++;
            k = max(k, DP[i][j]);
        }
    for (i = k; i > 0; i--)
        ans[i] = ans[i + 1] + cnt[i];
    for (i = 1; i <= n; i++)
        printf("%lld ", ans[i]);

    return 0;
}
