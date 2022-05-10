#include <bits/stdc++.h>
using namespace std;

vector<int> friends[150005];
vector<int> myints;
bool vis[150005];

bool dfs(int s, int m)
{
    if (vis[s])
        return true;
    myints.push_back(s);
    vis[s] = true;
    bool ans = true;
    int i, u, n;

    n = friends[s].size();
    if (m != n)
        return false;
    for (i = 0; i < n; i++)
    {
        u = friends[s][i];
        ans = (ans & dfs(u, n));
        if (!ans)
            break;
    }

    return ans;
}

int main()
{
    int i, m, n, u, v, k, A;
    bool ans = true;

    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        friends[u].push_back(v);
        friends[v].push_back(u);
    }

    for (i = 1; i <= n; i++)
        if (!vis[i])
        {
            k = friends[i].size();
            myints.clear();
            ans = (ans & dfs(i, k));
            A = myints.size() - 1;
            if (A != k)
                ans = false;
            if (!ans)
                break;
        }

    if (ans)
        printf("YES");
    else
        printf("NO");

    return 0;
}
