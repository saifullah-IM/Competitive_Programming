#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long i, m, b, x, y, z, ans = -1, temp;

    scanf("%lld %lld", &m, &b);
    z = b * m;
    for (y = 0; y <= b; y++)
    {
        x = z - m * y;
        temp = (x + 1) * (y + 1) * (x + y);
        temp /= 2;
        ans = max(ans, temp);
    }
    cout << ans;

    return 0;
}
