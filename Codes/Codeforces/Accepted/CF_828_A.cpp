#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, a, b, c, x, ans;

    scanf("%d %d %d", &n, &a, &b);
    ans = c = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x == 1)
        {
            if (a > 0)
                a--;
            else if (b > 0)
            {
                b--;
                c++;
            }
            else if (c > 0)
                c--;
            else
                ans++;
        }
        else if (x == 2)
        {
            if (b > 0)
                b--;
            else
                ans += 2;
        }
    }
    cout << ans;

    return 0;
}
