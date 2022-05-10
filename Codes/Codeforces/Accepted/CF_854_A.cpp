/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

int GCD(int m, int n)
{
    int t;
    while (n > 0)
    {
        t = n;
        n = m % n;
        m = t;
    }
    return m;
}

int main()
{
    int i, n, a, b, k;

    scanf("%d", &n);
    k = (n - 1) / 2;
    for (i = 1; i <= k; i++)
    {
        if (GCD(i, n - i) == 1)
        {
            a = i;
            b = n - i;
        }
    }
    cout << a << ' ' << b;

    return 0;
}
