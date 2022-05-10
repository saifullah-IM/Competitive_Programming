#include <bits/stdc++.h>
using namespace std;

const int mx = 3e5 + 5;
vector<int> tree[mx];
int mark[mx], parent[mx];

int solve(int u)
{
    if (tree[u].empty())
        return 1;
    int ans1 = mx, ans2 = 0;
    for (int v : tree[u])
    {
        int x = solve(v);
        ans1 = min(ans1, x);
        ans2 += x;
    }
    if (mark[u] == 0)
        return ans2;
    else
        return ans1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> mark[i];
    for (int i = 2; i <= n; i++)
    {
        cin >> parent[i];
        tree[parent[i]].push_back(i);
    }

    int leaf = 0;
    for (int i = 1; i <= n; i++)
        if (tree[i].empty())
            leaf++;
    int ans = leaf - solve(1) + 1;
    cout << ans << endl;

    return 0;
}
