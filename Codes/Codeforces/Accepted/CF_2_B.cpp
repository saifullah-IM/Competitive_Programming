#include <bits/stdc++.h>
#define inf 2000000000
using namespace std;

int n, ara[1005][1005], DP[1005][1005][2];
char path[1005][1005][2];

int least_round_way(int i, int j, int k)
{
    if (i >= n || j >= n)
        return inf;
    if (DP[i][j][k] != -1)
        return DP[i][j][k];

    int a, m, u, v;
    a = 0;
    m = ara[i][j];

    if (k == 0)
    {
        while (m % 2 == 0)
        {
            a++;
            m /= 2;
        }
    }
    if (k == 1)
    {
        while (m % 5 == 0)
        {
            a++;
            m /= 5;
        }
    }

    if (i == n - 1 && j == n - 1)
        return DP[i][j][k] = a;
    u = least_round_way(i + 1, j, k);
    v = least_round_way(i, j + 1, k);
    if (u > v)
    {
        path[i][j][k] = 'R';
        return DP[i][j][k] = a + v;
    }
    else
    {
        path[i][j][k] = 'D';
        return DP[i][j][k] = a + u;
    }
}

int main()
{
    int i, j, ans, u, v, k;
    bool ck;

    ck = false;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
        {
            scanf("%d", &ara[i][j]);
            if (ara[i][j] == 0)
            {
                ara[i][j] = 10;
                ck = true;
                k = i;
            }
        }

    memset(DP, -1, sizeof(DP));
    u = least_round_way(0, 0, 0);
    v = least_round_way(0, 0, 1);
    ans = min(u, v);

    if (ck && ans > 0)
    {
        printf("1\n");
        for (i = 0; i < k; i++)
            printf("D");
        for (i = 1; i < n; i++)
            printf("R");
        for (i = k + 1; i < n; i++)
            printf("D");
    }
    else
    {
        i = 0, j = 0;
        if (u < v)
            k = 0;
        else
            k = 1;
        printf("%d\n", ans);
        while (i != n - 1 || j != n - 1)
        {
            printf("%c", path[i][j][k]);
            if (path[i][j][k] == 'R')
                j++;
            else
                i++;
        }
    }

    return 0;
}
