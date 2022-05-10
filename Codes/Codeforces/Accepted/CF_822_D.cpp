#include <bits/stdc++.h>
#define MOD 1000000007
#define mx 5000006
using namespace std;

bool flag[mx];
long long lstdiv[mx], DP[mx];

void sieve()
{
    long long i, j, k;
    memset(lstdiv, 63, sizeof(lstdiv));

    for (i = 4; i <= mx; i += 2)
    {
        flag[i] = true;
        lstdiv[i] = 2;
    }
    for (i = 3; i <= mx; i += 2)
        if (!flag[i])
        {
            for (j = i, j *= i; j <= mx; j += i)
            {
                flag[j] = true;
                lstdiv[j] = min(lstdiv[j], i);
            }
        }
}

long long cnt(long long n)
{
    if (n == 1)
        return 0;
    else if (DP[n] != 0)
        return DP[n];
    else if (!flag[n])
        return DP[n] = ((n * (n - 1)) / 2) % MOD;

    long long ans, k;
    k = lstdiv[n];
    ans = ((k * (k - 1)) / 2) % MOD;
    ans *= (n / k);
    ans += cnt(n / k);
    return DP[n] = ans % MOD;
}

int main()
{
    sieve();
    long long i, t, l, r, k, ans;

    scanf("%lld %lld %lld", &t, &l, &r);

    k = 1;
    ans = 0;
    for (i = l; i <= r; i++)
    {
        ans = (ans + k * cnt(i)) % MOD;
        k = (k * t) % MOD;
    }
    cout << ans;

    return 0;
}
