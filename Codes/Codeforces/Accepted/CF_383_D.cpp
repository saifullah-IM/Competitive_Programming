/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

const int mx = 10005;
const int nx = 1005;

ll DP[nx][mx][2];
int n, ara[mx];

ll solve(int i, int m, bool k)
{
    if (DP[i][m][k] != -1)
        return DP[i][m][k];

    int M;
    if (k)
        M = (m + ara[i]) % mx;
    else
        M = ((m - ara[i]) % mx + mx) % mx;

    DP[i][m][k] = 0;
    if (i != n - 1)
        DP[i][m][k] = solve(i + 1, M, true) + solve(i + 1, M, false);
    if (M == 0)
        DP[i][m][k] += 1;
    DP[i][m][k] %= MOD;
    return DP[i][m][k];
}

int main()
{
    int i;
    ll ans;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &ara[i]);
    memset(DP, -1, sizeof(DP));
    for (i = ans = 0; i < n; i++)
        ans = (ans + solve(i, 0, 0) + solve(i, 0, 1)) % MOD;
    printf("%lld\n", ans);

    return 0;
}
