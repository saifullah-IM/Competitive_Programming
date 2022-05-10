/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1005;
char grid[mx][mx];
char ans[mx][mx];
int main()
{
    int i, j, k, n, m;
    bool chk = true, ara[4];
    char ch;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%s", grid[i]);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            if (grid[i][j] == 'b' && !ans[i][j])
            {
                if (j == 0 || j == m - 1 || grid[i][j - 1] != 'w' || ans[i][j - 1] || grid[i][j + 1] != 'w' || ans[i][j + 1])
                {
                    chk = false;
                    break;
                }
                memset(ara, 0, sizeof(ara));
                if (i > 0 && ans[i - 1][j])
                    ara[ans[i - 1][j] - 'a'] = true;
                if (j > 1 && ans[i][j - 2])
                    ara[ans[i][j - 2] - 'a'] = true;
                if (j + 2 < m && ans[i][j + 2])
                    ara[ans[i][j + 2] - 'a'] = true;
                for (k = 0; k < 4; k++)
                    if (!ara[k])
                    {
                        ch = 'a' + k;
                        break;
                    }
                ans[i][j - 1] = ans[i][j] = ans[i][j + 1] = ch;
            }
        if (!chk)
            break;
        for (j = 0; j < m; j++)
            if (grid[i][j] == 'w' && !ans[i][j])
            {
                if (i == n - 1 || i == n - 2 || grid[i + 1][j] != 'b' || grid[i + 2][j] != 'w')
                {
                    chk = false;
                    break;
                }
                memset(ara, 0, sizeof(ara));
                if (i > 0 && ans[i - 1][j])
                    ara[ans[i - 1][j] - 'a'] = true;
                if (j > 0 && ans[i][j - 1])
                    ara[ans[i][j - 1] - 'a'] = true;
                if (j + 1 < m && ans[i][j + 1])
                    ara[ans[i][j + 1] - 'a'] = true;
                for (k = 0; k < 4; k++)
                    if (!ara[k])
                    {
                        ch = 'a' + k;
                        break;
                    }
                ans[i][j] = ans[i + 1][j] = ans[i + 2][j] = ch;
            }
        if (!chk)
            break;
    }

    if (!chk)
        printf("NO\n");
    else
    {
        printf("YES\n");
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (grid[i][j] == '.')
                    printf("%c", '.');
                else
                    printf("%c", ans[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
