/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

long long pow2[56];

void prep()
{
    pow2[0] = 1;
    for (int i = 1; i <= 55; i++)
        pow2[i] = 2 * pow2[i - 1];
}
int main()
{
    int i, j, n, m, k1, k2, ara[55][55];
    long long ans;

    prep();
    ans = 0;
    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &ara[i][j]);

    for (i = 0; i < n; i++)
    {
        k1 = k2 = 0;
        for (j = 0; j < m; j++)
        {
            if (ara[i][j] == 0)
                k1++;
            if (ara[i][j] == 1)
                k2++;
        }
        ans += pow2[k1] + pow2[k2] - 2;
    }

    for (i = 0; i < m; i++)
    {
        k1 = k2 = 0;
        for (j = 0; j < n; j++)
        {
            if (ara[j][i] == 0)
                k1++;
            if (ara[j][i] == 1)
                k2++;
        }
        ans += pow2[k1] + pow2[k2] - 2;
    }
    ans -= m * n;
    cout << ans;
    return 0;
}
