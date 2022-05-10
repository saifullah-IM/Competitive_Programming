#include <bits/stdc++.h>
using namespace std;

vector<int> edges[205];
bool vis[205];
int ans;

string to_lower(string S)
{
    int i, n;
    n = S.size();
    for (i = 0; i < n; i++)
        S[i] = (S[i] | 32);

    return S;
}

void dfs(int s, int k)
{
    if (vis[s])
        return;
    vis[s] = true;
    if (k > ans)
        ans = k;
    int i, v, n;

    n = edges[s].size();
    for (i = 0; i < n; i++)
    {
        v = edges[s][i];
        dfs(v, k + 1);
    }
}

int main()
{
    int i, n, u, v, k;
    map<string, int> mymap;
    string S1, S2, S3;
    mymap["polycarp"] = 0;

    scanf("%d", &n);
    k = 1;
    for (i = 0; i < n; i++)
    {
        cin >> S1 >> S2 >> S3;
        S1 = to_lower(S1);
        S3 = to_lower(S3);
        if (mymap.count(S1) == 0)
            mymap[S1] = k++;
        if (mymap.count(S3) == 0)
            mymap[S3] = k++;
        u = mymap[S1];
        v = mymap[S3];
        edges[v].push_back(u);
    }
    dfs(0, 1);
    printf("%d\n", ans);

    return 0;
}
