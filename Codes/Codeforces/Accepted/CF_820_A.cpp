#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, ans, c, v0, v1, v, a, l;

    scanf("%d %d %d %d %d", &c, &v0, &v1, &a, &l);
    i = v0;
    ans = 1;
    while (i < c)
    {
        v0 += a;
        if (v0 > v1)
            v0 = v1;
        i += v0 - l;
        ans++;
    }
    cout << ans;
    return 0;
}
