#include <bits/stdc++.h>
using namespace std;

struct crdnt
{
    int x1, y1, x2, y2;
};

crdnt pos[26];
bool grid[102][102][3], tren[26];
int n, DP[102][102][3];

int dfs(int sx, int sy, int t)
{
    if (sy == n - 1)
        return 1;
    if (DP[t][sy][sx] != -1)
        return DP[t][sy][sx];

    int ans = 0;
    if (!grid[t][sy + 1][sx])
    {
        if (!grid[t + 1][sy + 1][sx])
            ans = dfs(sx, sy + 1, t + 1);
        if (ans == 1)
            return DP[t][sy][sx] = ans;
        if (sx < 2 && !grid[t][sy + 1][sx + 1] && !grid[t + 1][sy + 1][sx + 1])
            ans = dfs(sx + 1, sy + 1, t + 1);
        if (ans == 1)
            return DP[t][sy][sx] = ans;
        if (sx > 0 && !grid[t][sy + 1][sx - 1] && !grid[t + 1][sy + 1][sx - 1])
            ans = dfs(sx - 1, sy + 1, t + 1);
        if (ans == 1)
            return DP[t][sy][sx] = ans;
    }
    return DP[t][sy][sx] = 0;
}

int main()
{
    int i, j, l, k, t, sx, sy, p, q, r;
    char ch;
    int ans;

    scanf("%d", &t);
    r = t;
    while (t--)
    {
        scanf("%d %d", &n, &k);
        memset(tren, 0, sizeof(tren));
        memset(grid, 0, sizeof(grid));
        memset(DP, -1, sizeof(DP));
        for (l = 0; l < 3; l++)
        {
            scanf("%*c");
            for (j = 0; j < n; j++)
            {
                scanf("%c", &ch);
                if (ch == 's')
                {
                    sx = l;
                    sy = j;
                }
                else if (ch == '.')
                    continue;
                else
                {
                    p = ch - 'A';
                    if (tren[p])
                    {
                        pos[p].x2 = l;
                        pos[p].y2 = j;
                    }
                    else
                    {
                        tren[p] = true;
                        pos[p].x1 = pos[p].x2 = l;
                        pos[p].y1 = pos[p].y2 = j;
                    }
                }
            }
        }

        for (i = 0; i < 26; i++)
            if (tren[i])
            {
                for (j = 0; j <= 100; j++)
                {
                    p = pos[i].x1;
                    for (l = pos[i].y1; l <= pos[i].y2; l++)
                    {
                        if (l >= 0)
                            grid[j][l][p] = true;
                    }
                    pos[i].y1 -= 2;
                    pos[i].y2 -= 2;
                    if (pos[i].y2 < 0)
                        break;
                }
            }
        ans = dfs(sx, sy, 0);
        if (ans == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
