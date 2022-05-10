/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;
vector<int> edges[mx], people[mx], table[mx][20];
int parent[mx][20], level[mx];
inline void add(vector<int> &a, vector<int> &b, vector<int> &c)
{
    int i = 0, j = 0, k = 0, p, q, r;
    vector<int> temp;
    p = a.size();
    q = b.size();
    r = c.size();
    a.push_back(mx);
    b.push_back(mx);
    c.push_back(mx);
    while ((i < p || j < q || k < r) && i + j + k < 10)
    {
        if (i < p && a[i] < b[j] && a[i] < c[k])
            temp.push_back(a[i++]);
        else if (j < q && b[j] < a[i] && b[j] < c[k])
            temp.push_back(b[j++]);
        else
            temp.push_back(c[k++]);
    }
    c.clear();
    a.pop_back();
    b.pop_back();
    for (int x : temp)
        c.push_back(x);
}
inline void add(vector<int> &a, vector<int> &b)
{
    int i = 0, j = 0, p, q;
    vector<int> temp;
    p = a.size();
    q = b.size();
    a.push_back(mx);
    b.push_back(mx);
    while ((i < p || j < q) && i + j < 10)
    {
        if (i < p && a[i] < b[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(b[j++]);
    }
    a.pop_back();
    b.clear();
    for (int x : temp)
        b.push_back(x);
}
bool vis[mx];
void dfs(int u, int d)
{
    vis[u] = true;
    level[u] = d;
    for (int v : edges[u])
    {
        if (!vis[v])
        {
            dfs(v, d + 1);
            parent[v][0] = u;
            add(people[u], table[v][0]);
        }
    }
}
void sparse_table(int n)
{
    dfs(1, 0);
    parent[1][0] = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; (1 << j) < n; j++)
            parent[i][j] = -1;
    }
    for (int j = 1; (1 << j) < n; j++)
    {
        for (int i = 1; i <= n; i++)
            if (parent[i][j - 1] != -1)
            {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
                if (parent[i][j] != -1)
                    add(table[i][j - 1], table[parent[i][j - 1]][j - 1], table[i][j]);
            }
    }
}
void print(vector<int> &a, int k)
{
    cout << "********" << k << endl;
    for (int x : a)
        cout << x << "  ";
    cout << endl
         << "********" << endl;
}
void query(int u, int v, vector<int> &ret)
{
    if (level[u] < level[v])
        swap(u, v);
    int p = u;
    int q = v;
    for (int i = 19; i >= 0; i--)
    {
        if (level[u] - (1 << i) >= level[v])
        {
            add(table[u][i], ret);
            u = parent[u][i]; ///print(ret,1);
        }
    }
    if (u == v)
    {
        add(people[p], ret); ///print(ret,3);
        return;
    }
    for (int i = 19; i >= 0; i--)
    {
        if (parent[u][i] != -1 && parent[u][i] != parent[v][i])
        {
            add(table[u][i], table[v][i], ret); ///print(ret,2);
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    add(table[v][0], ret); ///cout<<"LCA   "<<p<<' '<<q<<' '<<parent[v][0]<<endl;
    add(people[p], people[q], ret);
}
int main()
{
    int i, n, m, q, u, v, a;

    scanf("%d %d %d", &n, &m, &q);
    for (i = 1; i < n; i++)
    {
        scanf("%d %d", &u, &v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (i = 1; i <= m; i++)
    {
        scanf("%d", &u);
        people[u].push_back(i);
    }
    for (i = 1; i <= n; i++)
        sort(people[i].begin(), people[i].end());
    sparse_table(n);
    while (q--)
    {
        scanf("%d %d %d", &u, &v, &a);
        vector<int> ans;
        ans.clear();
        query(u, v, ans);
        while (ans.size() > a)
            ans.pop_back();
        printf("%d ", ans.size());
        for (int x : ans)
            printf("%d ", x);
        printf("\n");
    }

    return 0;
}
