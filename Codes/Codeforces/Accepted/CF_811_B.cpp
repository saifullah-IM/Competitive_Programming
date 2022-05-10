#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, m, n, l, r, x, ara[10005], cnt;

    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
        scanf("%d", &ara[i]);
    while (m--)
    {
        cnt = 0;
        scanf("%d %d %d", &l, &r, &x);
        for (i = l; i <= r; i++)
            if (ara[i] < ara[x])
                cnt++;
        if (l + cnt == x)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
