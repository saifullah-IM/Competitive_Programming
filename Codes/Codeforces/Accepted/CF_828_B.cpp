#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n, m, R, C, x, y, p, q, r, k, ans;
    char ara[105][105], ch;

    scanf("%d %d", &n, &m);
    k = R = C = 0;
    x = y = 500;
    for (i = 0; i < n; i++)
    {
        scanf("%*c");
        for (j = 0; j < m; j++)
        {
            scanf("%c", &ara[i][j]);
            if (ara[i][j] == 'B')
            {
                k++;
                R = max(R, i);
                C = max(C, j);
                x = min(x, i);
                y = min(y, j);
            }
        }
    }

    if (k == 0)
    {
        cout << 1;
        return 0;
    }

    p = R - x + 1;
    q = C - y + 1;
    r = max(p, q);
    if (r <= n && r <= m)
        ans = r * r - k;
    else
        ans = -1;

    cout << ans;

    return 0;
}
