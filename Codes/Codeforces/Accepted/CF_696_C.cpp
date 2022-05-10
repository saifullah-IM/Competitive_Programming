/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;

ll bigmod(ll x, ll n)
{
    ll ret = 1;
    while (n > 0)
    {
        if (n % 2)
            ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return ret;
}

int main()
{
    bool chk = false;
    int i, n;
    ll ans, res, x;

    ans = 2;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &x);
        if (x % 2 == 0)
            chk = true;
        ans = bigmod(ans, x);
    }
    ans = (ans * bigmod(2, MOD - 2)) % MOD;
    if (chk)
        res = ((ans + 1) * bigmod(3, MOD - 2)) % MOD;
    else
        res = ((ans - 1) * bigmod(3, MOD - 2)) % MOD;
    printf("%lld/%lld\n", res, ans);

    return 0;
}
