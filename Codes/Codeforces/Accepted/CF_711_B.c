#include <stdio.h>
#include <math.h>

int main()
{
    int i, j, n, x, y;
    scanf("%d", &n);
    long long int row[n], col[n], dia[2], ara[n][n];

    col[0] = 0;
    col[1] = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%I64d", &ara[i][j]);
            if (ara[i][j] == 0)
            {
                x = i;
                y = j;
            }
        }
        col[0] += ara[i][0];
        col[1] += ara[i][1];
    }

    for (i = 0, col[y] = 0; i < n; i++)
        col[y] += ara[i][y];

    if (y == 0)
        ara[x][y] = fabs(col[1] - col[y]);
    else
        ara[x][y] = fabs(col[0] - col[y]);
    col[y] += ara[x][y];

    if (ara[x][y])
    {
        dia[0] = 0;
        dia[1] = 0;
        for (i = 0; i < n; i++)
        {
            row[i] = 0;
            col[i] = 0;
            for (j = 0; j < n; j++)
            {
                row[i] += ara[i][j];
                col[i] += ara[j][i];
            }
            if (row[i] != col[y] || col[i] != col[y])
            {
                ara[x][y] = -1;
                break;
            }
            dia[0] += ara[i][i];
            dia[1] += ara[i][n - 1 - i];
        }

        if (col[y] != dia[0] || col[y] != dia[1])
            ara[x][y] = -1;

        printf("%I64d", ara[x][y]);
    }
    else
        printf("-1");

    return 0;
}