/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n, m, ara1[12], ara2[12], ans, x, y, temp;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%d", &ara1[i]);
    for (i = 0; i < m; i++)
        scanf("%d", &ara2[i]);

    ans = 999;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            x = min(ara1[i], ara2[j]);
            y = max(ara1[i], ara2[j]);
            if (x == y)
                temp = x;
            else
                temp = 10 * x + y;
            ans = min(ans, temp);
        }
    cout << ans << endl;

    return 0;
}
