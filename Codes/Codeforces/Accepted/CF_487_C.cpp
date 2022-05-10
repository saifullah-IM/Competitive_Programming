/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 1e5 + 5;
bool flag[mx];
void sieve()
{
    flag[1] = true;
    for (int i = 4; i < mx; i += 2)
        flag[i] = true;
    for (ll i = 3; i < mx; i += 2)
        if (!flag[i])
        {
            for (ll j = i * i; j < mx; j += i)
                flag[j] = true;
        }
}
int calc(int a, int n)
{
    ll x = a - 1;
    int m = n - 2;
    ll res = 1;
    while (m > 0)
    {
        if (m % 2 == 1)
            res = (res * x) % n;
        x = (x * x) % n;
        m /= 2;
    }
    res = (res * a) % n;
    return res;
}
int main()
{
    sieve();
    int i, n;
    scanf("%d", &n);
    if (n == 1)
        printf("YES\n%d\n", 1);
    else if (n == 4)
        printf("YES\n%d\n%d\n%d\n%d\n", 1, 3, 2, 4);
    else if (flag[n])
        printf("NO\n");
    else
    {
        printf("YES\n%d\n", 1);
        for (i = 2; i < n; i++)
            printf("%d\n", calc(i, n));
        printf("%d\n", n);
    }

    return 0;
}
