#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;
typedef pair<int, int> pii;
vector<pii> src, des;

bool vis[55][55];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string grid[55];

void dfs(int x, int y, int n, vector<pii> &vec)
{
    vis[x][y] = true;
    vec.push_back(make_pair(x, y));
    for (int i = 0; i < 4; i++)
    {
        int fx = x + dx[i];
        int fy = y + dy[i];
        if (fx >= 0 && fy >= 0 && fx < n && fy < n && grid[fx][fy] == '0' && !vis[fx][fy])
        {
            dfs(fx, fy, n, vec);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int r1, c1, r2, c2;
    cin >> r1 >> c1;
    r1--;
    c1--;
    cin >> r2 >> c2;
    r2--;
    c2--;
    for (int i = 0; i < n; i++)
        cin >> grid[i];

    dfs(r1, c1, n, src);
    memset(vis, 0, sizeof(vis));
    dfs(r2, c2, n, des);
    int ans = inf;
    for (int i = 0; i < src.size(); i++)
    {
        for (int j = 0; j < des.size(); j++)
        {
            int dist = (src[i].first - des[j].first) * (src[i].first - des[j].first) + (src[i].second - des[j].second) * (src[i].second - des[j].second);
            ans = min(ans, dist);
            ///cout<<dist<<' '<<src[i].first<<' '<<src[i].second<<' '<<des[j].first<<' '<<des[j].second<<endl;
        }
    }
    cout << ans << endl;

    return 0;
}
