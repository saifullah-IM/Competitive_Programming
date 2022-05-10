/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 3005;
vector<int> edges[mx];
int level[mx][mx];

void bfs(int s)
{
    int i, u, v, m;
    queue<int> myQ;
    level[s][s] = 0;
    myQ.push(s);

    while (!myQ.empty())
    {
        u = myQ.front();
        myQ.pop();
        m = edges[u].size();
        for (i = 0; i < m; i++)
        {
            v = edges[u][i];
            if (level[s][v] == -1)
            {
                level[s][v] = 1 + level[s][u];
                myQ.push(v);
            }
        }
    }
}

int main()
{
    int i, j, n, m, u, v, s1, t1, w1, s2, t2, w2, ans;

    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    scanf("%d %d %d", &s1, &t1, &w1);
    scanf("%d %d %d", &s2, &t2, &w2);

    memset(level, -1, sizeof(level));
    for (i = 1; i <= n; i++)
        bfs(i);
    ans = mx;
    if (level[s1][t1] <= w1 && level[s2][t2] <= w2)
        ans = min(ans, level[s1][t1] + level[s2][t2]);
    else
        ans = -1;
    if (ans == -1)
    {
        printf("-1\n");
        return 0;
    }
    ///cout<<ans<<endl;
    for (i = 1; i < n; i++)
    {
        for (j = i + 1; j <= n; j++)
        { ///cout<<i<<' '<<j<<' '<<ans<<endl;
            int x, y;
            x = level[i][s1] + level[i][j] + level[j][t1]; ///cout<<level[0][s1]<<' '<<level[0][j]<<' '<<level[1][t1]<<endl;
            y = level[i][s2] + level[i][j] + level[j][t2]; ///cout<<i<<' '<<j<<' '<<x<<' '<<y<<endl<<endl;;
            if (x <= w1 && y <= w2)
                ans = min(ans, x + y - level[i][j]);

            x = level[i][t1] + level[i][j] + level[j][s1];
            y = level[i][s2] + level[i][j] + level[j][t2];
            if (x <= w1 && y <= w2)
                ans = min(ans, x + y - level[i][j]);

            x = level[i][t1] + level[i][j] + level[j][s1];
            y = level[i][t2] + level[i][j] + level[j][s2];
            if (x <= w1 && y <= w2)
                ans = min(ans, x + y - level[i][j]);

            x = level[i][s1] + level[i][j] + level[j][t1];
            y = level[i][t2] + level[i][j] + level[j][s2];
            if (x <= w1 && y <= w2)
                ans = min(ans, x + y - level[i][j]);
        }
    } ///cout<<ans<<endl;
    ans = m - ans;
    printf("%d\n", ans);

    return 0;
}
