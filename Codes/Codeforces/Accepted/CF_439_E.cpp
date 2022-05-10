/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long
#define mx 100005
using namespace std;

ll bigmod(ll x, int n)
{
    ll res = 1;
    while (n > 0)
    {
        if (n % 2)
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        n /= 2;
    }
    return res;
}

ll fact[mx], inv[mx];
void prep()
{
    fact[0] = inv[0] = 1;
    for (int i = 1; i < mx; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = bigmod(fact[i], MOD - 2);
    }
}

ll nCr(int n, int r)
{
    ll ans;
    ans = (((fact[n] * inv[n - r]) % MOD) * inv[r]) % MOD;
    return ans;
}

int prmdivs[mx];
vector<int> divs[mx];
bool sqr[mx], flag[mx];

void sieve()
{
    ll i, j, k;
    for (i = 2; i < mx; i++)
    {
        if (sqr[i])
            continue;
        if (!flag[i])
        {
            for (j = i; j < mx; j += i)
            {
                prmdivs[j]++;
                divs[j].push_back(i);
                if (i != j)
                    flag[j] = true;
            }
            k = i * i;
            for (j = k; j < mx; j += k)
                sqr[j] = true;
        }
        else
            for (j = i; j < mx; j += i)
                divs[j].push_back(i);
    }
}

int main()
{
    int i, n, q, f, j, k, n1, t;
    ll ans;

    prep();
    sieve();

    scanf("%d", &q);
    while (q--)
    {
        scanf("%d %d", &n, &f);
        if (n < f)
            ans = 0;
        else if (f == 1)
            ans = (n == 1 ? 1 : 0);
        else
        {
            ans = nCr(n - 1, f - 1);
            k = divs[n].size();
            for (i = 0; i < k; i++)
            {
                t = divs[n][i];
                n1 = n / t;
                if (n1 >= f)
                {
                    if (!sqr[t])
                    {
                        if (prmdivs[t] % 2 == 1)
                            ans -= nCr(n1 - 1, f - 1);
                        else
                            ans += nCr(n1 - 1, f - 1);
                    }
                }
                else
                    break;
            }
            ans = (ans % MOD + MOD) % MOD;
        }
        printf("%lld\n", ans);
    }

    return 0;
}
