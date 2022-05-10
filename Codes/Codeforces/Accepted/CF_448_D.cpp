/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int i;
    ll sum, ans, n, m, k, t, temp;

    scanf("%lld %lld %lld", &n, &m, &k);

    ll hi, lo, mid;
    hi = ans = m * n;
    lo = 1;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        sum = 0;
        for (i = 1; i <= n; i++)
            sum += (min(m * i, mid)) / i;
        if (sum < k)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    ans = m * n;
    t = ceil((lo * 1.0) / (n * 1.0));
    for (i = t; i <= m; i++)
    {
        temp = ceil((lo * 1.0) / (i * 1.0)) * i;
        ans = min(ans, temp);
    }
    printf("%lld\n", ans);

    return 0;
}
