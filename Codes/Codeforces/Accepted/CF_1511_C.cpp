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
#define inf (1 << 30)
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
typedef multiset<int>::iterator mit;
typedef map<int, int> mii;
typedef map<int, int>::iterator miit;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    //cin >> test;
    while (test--)
    {
        int n, q;
        cin >> n >> q;
        vi ara(60, inf);
        vi query(60, -1);
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            ara[x] = min(ara[x], i + 1);
        }
        vector<vector<bool>> came_in(52, vector<bool>(52, false));
        for (int i = 1; i <= q; i++)
        {
            int x;
            cin >> x;
            int ans;
            if (query[x] == -1)
            {
                ans = ara[x];
                for (int j = 1; j <= 50; j++)
                {
                    if (came_in[0][j])
                        if (ara[x] < ara[j])
                            ans++;
                }
            }
            else
            {
                ans = 1;
                for (int j = 1; j <= 50; j++)
                {
                    if (came_in[x][j])
                        ans++;
                }
            }
            cout << ans << ' ';
            query[x] = i;
            for (int j = 0; j <= 50; j++)
            {
                if (j == x)
                    fill(came_in[x].begin(), came_in[x].end(), false);
                else
                    came_in[j][x] = true;
            }
        }
    }

    return 0;
}