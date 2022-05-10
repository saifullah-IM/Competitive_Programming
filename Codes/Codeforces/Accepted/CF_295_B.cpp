#include <bits/stdc++.h>
using namespace std;

int mat[505][505];
long long ans[505];

int main()
{
    int i, j, k, x, y, z, n, ara[505];

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &mat[i][j]);
    for (i = n; i > 0; i--)
        scanf("%d", &ara[i]);

    for (k = 1; k <= n; k++)
    {
        z = ara[k];
        for (i = 1; i <= n; i++)
        {
            x = ara[i];
            for (j = 1; j <= n; j++)
            {
                y = ara[j];
                if (mat[x][y] > mat[x][z] + mat[z][y])
                    mat[x][y] = mat[x][z] + mat[z][y];
                if (i <= k && j <= k)
                    ans[k] += mat[x][y];
            }
        }
    }

    for (i = n; i > 0; i--)
        printf("%lld ", ans[i]);

    return 0;
}
