#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int m, n, x, ans[1005][1005];
bool chk[1005][1005], vis[1005][1005];
char grid[1005][1005];

void dfs(int sx, int sy)
{
    if (vis[sx][sy])
        return;
    if (grid[sx][sy] == '*')
    {
        x++;
        return;
    }
    vis[sx][sy] = true;

    int i, tx, ty;
    for (i = 0; i < 4; i++)
    {
        tx = sx + dx[i];
        ty = sy + dy[i];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m)
            dfs(tx, ty);
    }
}

void cnt(int sx, int sy, int k)
{
    if (chk[sx][sy])
        return;
    if (grid[sx][sy] == '*')
        return;
    chk[sx][sy] = true;
    ans[sx][sy] = k;

    int i, tx, ty;
    for (i = 0; i < 4; i++)
    {
        tx = sx + dx[i];
        ty = sy + dy[i];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m)
            cnt(tx, ty, k);
    }
}

int main()
{
    int i, j, k, l;

    scanf("%d %d %d", &n, &m, &k);
    for (i = 0; i < n; i++)
        scanf(" %[^\n]", grid[i]);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (grid[i][j] == '.' && !vis[i][j])
            {
                x = 0;
                dfs(i, j);
                cnt(i, j, x);
            }
        }
    }

    for (i = 0; i < k; i++)
    {
        scanf("%d %d", &j, &l);
        printf("%d\n", ans[j - 1][l - 1]);
    }

    return 0;
}
