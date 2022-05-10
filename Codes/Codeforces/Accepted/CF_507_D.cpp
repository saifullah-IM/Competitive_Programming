/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k, MOD, POW10[1005];
ll pow10[1005];
void prep()
{
    pow10[0] = POW10[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        POW10[i] = (10 * POW10[i - 1]) % k;
        pow10[i] = (10 * pow10[i - 1]) % MOD;
    }
}

ll DP[1005][105][2];
ll solve(int i, int m, bool chk)
{
    if (i == n + 1)
    {
        if (m == 0)
            return 1;
        else
            return 0;
    }
    if (i != 1 && chk && m == 0)
    {
        DP[i][m][chk] = (9 * pow10[n - i]) % MOD;
        return DP[i][m][chk];
    }
    if (DP[i][m][chk] != -1)
        return DP[i][m][chk];

    int M;
    DP[i][m][chk] = 0;
    for (int j = 0; j < 10; j++)
    {
        if (i == n && j == 0)
            continue;
        M = (j * POW10[i - 1] + m) % k;
        DP[i][m][chk] += solve(i + 1, M, chk | j);
    }
    DP[i][m][chk] %= MOD;
    return DP[i][m][chk];
}

int main()
{
    scanf("%d %d %d", &n, &k, &MOD);
    memset(DP, -1, sizeof(DP));
    prep();
    cout << solve(1, 0, 0) << endl;

    return 0;
}
