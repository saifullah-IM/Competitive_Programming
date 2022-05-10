/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

const int mx = 2004;

int N, K, DP[mx][mx];

int solve(int n, int k)
{
    if (k == K)
        return 1;
    if (DP[n][k] != 0)
        return DP[n][k];

    int i;
    ll ans = 0;
    for (i = n; i <= N; i += n)
        ans = (ans + solve(i, k + 1)) % MOD;
    return DP[n][k] = ans;
}

int main()
{
    ll ans = 0;
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++)
        ans = (ans + solve(i, 1)) % MOD;
    printf("%lld\n", ans);

    return 0;
}
