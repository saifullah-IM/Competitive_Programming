/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

char edge[305][305];
bool chk[305];
int main()
{
    int i, j, n, m, k, x, y, z, E;

    scanf("%d %d %d", &n, &m, &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d", &x);
        chk[x] = true;
    }
    y = (n * (n - 1)) / 2 - k + 1;
    if (k == n || m > y)
        printf("-1\n");
    else
    {
        for (i = 1; i <= n; i++)
            if (!chk[i])
            {
                y = i;
                break;
            }
        for (i = 1; i <= n; i++)
        {
            if (i != y)
            {
                if (i < y)
                    edge[i][y] = 1;
                else
                    edge[y][i] = 1;
            }
            if (chk[i])
            {
                if (i < x)
                    edge[i][x] = 2;
                else
                    edge[x][i] = 2;
            }
        }
        E = n - 1;
        for (i = 1; i <= n && E < m; i++)
            for (j = i + 1; j <= n && E < m; j++)
                if (edge[i][j] == 0)
                {
                    E++;
                    edge[i][j] = 1;
                }
        for (i = 1; i <= n; i++)
            for (j = i + 1; j <= n; j++)
                if (edge[i][j] == 1)
                    printf("%d %d\n", i, j);
    }

    return 0;
}
