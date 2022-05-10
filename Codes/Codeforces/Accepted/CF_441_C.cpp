#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int n, m;
bool vis[305][305];
vector<PII> ans;

void dfs(int sx, int sy)
{
    if (vis[sx][sy])
        return;
    vis[sx][sy] = true;
    ans.push_back(make_pair(sx, sy));

    int i, tx, ty;
    for (i = 0; i < 4; i++)
    {
        tx = sx + dx[i];
        ty = sy + dy[i];
        if (tx > 0 && tx <= n && ty > 0 && ty <= m)
            dfs(tx, ty);
    }
}

int main()
{
    int i, j, l, a, b, k;
    PII A;

    scanf("%d %d %d", &n, &m, &k);
    memset(vis, 0, sizeof(vis));
    dfs(1, 1);
    a = (m * n) / k;
    b = a + m * n - a * k;
    j = 0;
    for (i = 1; i < k; i++)
    {
        printf("%d ", a);
        for (l = 0; l < a; l++, j++)
        {
            A = ans[j];
            cout << A.first << ' ' << A.second << ' ';
        }
        printf("\n");
    }
    printf("%d ", b);
    for (l = 0; l < b; l++, j++)
    {
        A = ans[j];
        cout << A.first << ' ' << A.second << ' ';
    }

    return 0;
}
