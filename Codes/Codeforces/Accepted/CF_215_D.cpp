/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, m;
    long long ans, t, T, x, y, z, C;

    ans = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%lld %lld %lld %lld", &t, &T, &x, &C);
        if (t + m <= T)
            ans += C;
        else if (t >= T)
            ans += C + x * m;
        else
        {
            y = C + x * m;
            z = T - t;
            z = ceil((m * 1.0) / (z * 1.0));
            z *= C;
            ans += min(y, z);
        }
    }
    printf("%lld\n", ans);

    return 0;
}
