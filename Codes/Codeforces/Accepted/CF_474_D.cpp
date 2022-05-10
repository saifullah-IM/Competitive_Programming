/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

const int mx = 100005;
ll DP[mx], sum[mx];

ll solve(int n, int k)
{
    if (n < 0)
        return 0;
    if (n == 0)
        return 1;
    if (DP[n] != -1)
        return DP[n];
    return DP[n] = (solve(n - 1, k) + solve(n - k, k)) % MOD;
}

int main()
{
    int i, t, k, l, r;
    ll ans;

    memset(DP, -1, sizeof(DP));
    scanf("%d %d", &t, &k);
    for (i = 1; i < mx; i++)
        sum[i] = (solve(i, k) + sum[i - 1]) % MOD;
    while (t--)
    {
        scanf("%d %d", &l, &r);
        ans = sum[r] - sum[l - 1];
        ans = (ans % MOD + MOD) % MOD;
        printf("%lld\n", ans);
    }

    return 0;
}
