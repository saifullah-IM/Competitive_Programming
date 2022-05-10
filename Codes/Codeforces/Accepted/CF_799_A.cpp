#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t, d, k, ans1, ans2, p, m, r;

    scanf("%d %d %d %d", &n, &t, &k, &d);
    ans1 = ceil((n * 1.0) / (k * 1.0)) * t;
    p = floor(d * 1.0) / (t * 1.0);
    m = n - p * k;
    r = n - (p + 1) * k;
    ans2 = min((d + ceil((m * 1.0) / (2.0 * k)) * t), (p + 1 + ceil((r * 1.0) / (2.0 * k))) * t);
    if (ans2 < ans1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
