/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

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

const int mx = 2e3 + 5;
const int MOD = 1e9 + 7;
int ara[mx], dp[mx][4];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ara[i];
    for (int i = 1; i <= n; i++)
    {
        if (ara[i] == 1)
        {
            dp[i][1] = dp[i - 1][1];
            dp[i][3] = dp[i - 1][3];
            dp[i][0] = max(dp[i][0], 1 + dp[i - 1][0]);
            dp[i][2] = max(dp[i][2], 1 + max(dp[i - 1][2], dp[i - 1][1]));
            ans = max(ans, max(dp[i][0], dp[i][2]));
        }
        else
        {
            dp[i][0] = dp[i - 1][0];
            dp[i][2] = dp[i - 1][2];
            dp[i][1] = max(dp[i][1], 1 + max(dp[i - 1][1], dp[i - 1][0]));
            dp[i][3] = max(dp[i][3], 1 + max(dp[i - 1][3], dp[i - 1][2]));
            ans = max(ans, max(dp[i][1], dp[i][3]));
        }

        /*for (int j=0;j<4;j++) cout<<dp[i][j]<<"  ";
        cout<<endl<<"-----"<<endl;*/
    }
    cout << ans << endl;

    return 0;
}
