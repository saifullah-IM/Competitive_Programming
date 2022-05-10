#include <bits/stdc++.h>
using namespace std; /*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;*/

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define infll (1LL << 62)
#define abs(X) ((X) > 0 ? (X) : (-(X)))
#define fbo(k) find_by_order(k)    ///returns iterator to the kth largest element counting from 0
#define ook(val) order_of_key(val) ///returns the number of items in a set that are strictly smaller than val

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 1e3 + 5;
const int MOD = 1e9 + 7;

char grid[mx][mx];
short int dist[mx][mx];
short int dx[] = {0, 0, 1, -1};
short int dy[] = {1, -1, 0, 0};

void preprocess(int n, int m)
{
    queue<pii> myQ;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                int fx = i + dx[k];
                int fy = j + dy[k];
                if (fx >= 0 && fx < n && fy >= 0 && fy < m)
                {
                    if (grid[i][j] == grid[fx][fy])
                    {
                        dist[i][j] = 0;
                        myQ.push(mp(i, j));
                        //cout << "debug   original  " << i << j << endl;
                    }
                }
            }
        }
    }

    while (!myQ.empty())
    {
        pii A = myQ.front();
        myQ.pop();
        int x = A.fi;
        int y = A.se;
        for (int k = 0; k < 4; k++)
        {
            int fx = x + dx[k];
            int fy = y + dy[k];
            if (fx >= 0 && fx < n && fy >= 0 && fy < m)
            {
                if (dist[fx][fy] != -1)
                    continue;
                dist[fx][fy] = dist[x][y] + 1;
                myQ.push(mp(fx, fy));
                //cout << "debug   new  " << fx << fy << endl;
            }
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, t;
    cin >> n >> m >> t;

    memset(dist, -1, sizeof(dist));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    preprocess(n, m);

    while (t--)
    {
        int i, j;
        ll p;
        cin >> i >> j >> p;
        i--;
        j--;

        if (dist[i][j] == -1 || dist[i][j] >= p)
        {
            //cout << "debug " << dist[i][j] << endl;
            cout << grid[i][j] << endl;
            continue;
        }
        else
        {
            int flips = p - dist[i][j];
            //cout << "debug " << dist[i][j] << endl;
            if (flips % 2 == 0)
                cout << grid[i][j] << endl;
            else
                cout << ((grid[i][j] - '0') ^ 1) << endl;
        }
    }

    return 0;
}