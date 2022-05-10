/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 32000;
bool flag[mx];
int primes[3500];
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
ll GCD(ll a, ll b)
{
    while (b > 0)
    {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main()
{
    int i, n, t, m;

    m = sieve(); ///cout<<m<<' '<<primes[m-1]*primes[m-1];
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        ll u, v;
        int j = n;
        while (++j)
        {
            bool chk = true;
            for (i = 0; i < m && primes[i] < j; i++)
                if (j % primes[i] == 0)
                {
                    chk = false;
                    break;
                }
            if (chk)
            {
                u = j;
                break;
            }
        }
        j = n + 1;
        while (--j)
        {
            bool chk = true;
            for (i = 0; i < m && primes[i] < j; i++)
                if (j % primes[i] == 0)
                {
                    chk = false;
                    break;
                }
            if (chk)
            {
                v = j;
                break;
            }
        }
        ll p = u * v + 2 * n + 2 - 2 * (u + v);
        ll q = 2 * u * v;
        ll g = GCD(p, q);
        p /= g, q /= g;
        printf("%lld/%lld\n", p, q);
    }

    return 0;
}
