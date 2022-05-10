#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, a, k, ans;
    double x, y, z, p, q;

    scanf("%d %d", &n, &a);
    x = 180.0 / (n * 1.0);
    k = floor((a * 1.0) / x);
    y = a * 1.0 - k * 1.0 * x;
    z = (k + 1) * 1.0 * x - a * 1.0;

    if (k != 0 && y < z)
        ans = 1 + k;
    else
        ans = 2 + k;

    if (ans >= n)
        ans = n - 1;
    cout << 1 << ' ' << n << ' ' << ans;

    return 0;
}