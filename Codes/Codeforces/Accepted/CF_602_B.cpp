#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, m, ans, k, mx, mn, crnt, idx, temp;

    scanf("%d", &n);
    scanf("%d", &crnt);
    mx = mn = crnt;
    ans = temp = 1;
    idx = 0;

    for (i = 1; i < n; i++)
    {
        scanf("%d", &k);
        if (k == crnt)
        {
            temp++;
        }
        else if (k == crnt + 1)
        {
            if (mx == k)
                temp++;
            else
            {
                temp = i - idx + 1;
                mn = crnt;
                mx = k;
            }
            crnt = k;
            idx = i;
        }
        else
        {
            if (mn == k)
                temp++;
            else
            {
                temp = i - idx + 1;
                mx = crnt;
                mn = k;
            }
            crnt = k;
            idx = i;
        }
        if (temp > ans)
            ans = temp;
    }
    printf("%d\n", ans);

    return 0;
}
