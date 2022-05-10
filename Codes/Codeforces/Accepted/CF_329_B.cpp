#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int sx, sy, r, c, level[1005][1005];
short int grid[1005][1005];

void bfs()
{
    memset(level, -1, sizeof(level));
    level[sx][sy] = 0;
    PII A, B;
    int i, tx, ty;
    queue<PII> myQ;
    myQ.push(make_pair(sx, sy));

    while (!myQ.empty())
    {
        A = myQ.front();
        myQ.pop();
        for (i = 0; i < 4; i++)
        {
            tx = A.first + dx[i];
            ty = A.second + dy[i];
            if (tx >= 0 && tx < r && ty >= 0 && ty < c && level[tx][ty] == -1 && grid[tx][ty] != -1)
            {
                level[tx][ty] = 1 + level[A.first][A.second];
                myQ.push(make_pair(tx, ty));
            }
        }
    }
}

int main()
{
    int i, j, mx, my, ans, k;
    char ch;

    scanf("%d %d", &r, &c);
    for (i = 0; i < r; i++)
    {
        scanf("%*c");
        for (j = 0; j < c; j++)
        {
            scanf("%c", &ch);
            if (ch == 'T')
                grid[i][j] = -1;
            else if (ch == 'E')
            {
                sx = i, sy = j;
                grid[i][j] = 0;
            }
            else if (ch == 'S')
            {
                mx = i, my = j;
                grid[i][j] = 0;
            }
            else
                grid[i][j] = ch - '0';
        }
    }

    bfs();
    ans = 0;
    k = level[mx][my];
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
        {
            if (level[i][j] <= k && level[i][j] != -1)
                ans += grid[i][j];
        }

    printf("%d", ans);

    return 0;
}
