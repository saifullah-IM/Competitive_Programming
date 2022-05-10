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

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;

ll cost[105][105], grid[105][105];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin >> test;
    while (test--)
    {

        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> grid[i][j];
        }

        ll ans = infll;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                ll base = grid[i][j] - (i + j);

                for (int x = i; x >= 0; x--)
                {
                    for (int y = j; y >= 0; y--)
                    {

                        cost[x][y] = -1;
                        cost[i][j] = 0;
                        ll height = base + (x + y);
                        if (grid[x][y] < height)
                            continue;

                        ll temp = infll;
                        if (y < j && cost[x][y + 1] != -1)
                        {
                            temp = min(temp, grid[x][y] - height + cost[x][y + 1]);
                        }
                        if (x < i && cost[x + 1][y] != -1)
                        {
                            temp = min(temp, grid[x][y] - height + cost[x + 1][y]);
                        }

                        if (temp != infll)
                            cost[x][y] = temp;
                    }
                }

                for (int x = i; x < n; x++)
                {
                    for (int y = j; y < m; y++)
                    {

                        cost[x][y] = -1;
                        cost[i][j] = 0;
                        ll height = base + (x + y);
                        if (grid[x][y] < height)
                            continue;

                        ll temp = infll;
                        if (y > j && cost[x][y - 1] != -1)
                        {
                            temp = min(temp, grid[x][y] - height + cost[x][y - 1]);
                        }
                        if (x > i && cost[x - 1][y] != -1)
                        {
                            temp = min(temp, grid[x][y] - height + cost[x - 1][y]);
                        }

                        if (temp != infll)
                            cost[x][y] = temp;
                    }
                }

                if (cost[0][0] != -1 && cost[n - 1][m - 1] != -1)
                {
                    ans = min(ans, cost[0][0] + cost[n - 1][m - 1]);
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}
