/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 32000;
bool flag[mx];
int primes[3500], cnt[3500];
int sieve()
{
    int k = 0;
    for (int i = 2; i < mx; i++)
        if (!flag[i])
        {
            primes[k++] = i;
            for (int j = i * i; j < mx; j += i)
                flag[j] = true;
        }
    return k;
}

const int MOD = 1e9 + 7;
ll DP[505][16005];
ll solve(int pos, int n)
{
    if (n == 0)
        return 1;
    if (pos == 0)
        return 0;
    if (DP[pos][n] != -1)
        return DP[pos][n];
    ll &ret = DP[pos][n] = 0;
    ret += solve(pos, n - 1) + solve(pos - 1, n);
    ret %= MOD;
    return ret;
}
int main()
{
    int i, x, n, t, m;

    m = sieve();
    multiset<int> myset;
    scanf("%d", &n);
    memset(DP, -1, sizeof(DP));
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        for (int j = 0; j < m && primes[j] <= x; j++)
        {
            int k = 0;
            while (x % primes[j] == 0)
            {
                k++;
                x /= primes[j];
            }
            cnt[j] += k;
            if (k) ///cout<<primes[j]<<' '<<k<<endl;
                if (x == 1)
                    break;
        }
        if (x != 1)
            myset.insert(x);
    }
    ll ans = 1;
    for (i = 0; i < m; i++)
        ans = (ans * solve(n, cnt[i])) % MOD;
    while (!myset.empty())
    {
        auto it = myset.begin();
        ans = (ans * solve(n, myset.count(*it))) % MOD;
        myset.erase(*it);
    }
    printf("%lld\n", ans);

    return 0;
}
