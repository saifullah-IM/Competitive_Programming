/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

const int mx = 2005;
char grid[mx][mx];
int degree[mx][mx];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool bfs(int n, int m, int F)
{
    int i, j, k, tx, ty, f = 0;
    bool res = true;
    PII A;
    queue<PII> myQ;
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
        {
            if (degree[i][j] == 1)
                myQ.push(make_pair(i, j));
            if (degree[i][j] >= 2)
                res = false;
        }
    if (myQ.empty() && !res)
        return false;

    while (!myQ.empty())
    {
        A = myQ.front();
        myQ.pop();
        degree[A.first][A.second] = 0;
        for (i = 0; i < 4; i++)
        {
            tx = A.first + dx[i];
            ty = A.second + dy[i];
            if (tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] == '.')
            {
                if (i == 0)
                {
                    grid[A.first][A.second] = '<';
                    grid[tx][ty] = '>';
                    ;
                }
                else if (i == 1)
                {
                    grid[A.first][A.second] = '^';
                    grid[tx][ty] = 'v';
                }
                else if (i == 2)
                {
                    grid[A.first][A.second] = '>';
                    grid[tx][ty] = '<';
                    ;
                }
                else
                {
                    grid[A.first][A.second] = 'v';
                    grid[tx][ty] = '^';
                }
                f += 2;
                A = make_pair(tx, ty);
                for (j = 0; j < 4; j++)
                {
                    tx = A.first + dx[j];
                    ty = A.second + dy[j];
                    if (tx >= 0 && tx < n && ty >= 0 && ty < m && grid[tx][ty] == '.')
                        degree[tx][ty]--;
                    if (degree[tx][ty] == 1)
                        myQ.push(make_pair(tx, ty));
                }
                break;
            }
        }
    }

    return f == F;
}

int main()
{
    int i, j, n, m, tx, ty, F = 0;
    bool ans;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf(" %c", &grid[i][j]);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (grid[i][j] == '.')
            {
                F++;
                for (int k = 0; k < 2; k++)
                {
                    tx = i + dx[k];
                    ty = j + dy[k];
                    if (tx < n && ty < m && grid[tx][ty] == '.')
                    {
                        degree[i][j]++;
                        degree[tx][ty]++;
                    }
                }
            }
    ans = bfs(n, m, F);
    if (!ans)
        printf("Not unique\n");
    else
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
                printf("%c", grid[i][j]);
            printf("\n");
        }

    return 0;
}
