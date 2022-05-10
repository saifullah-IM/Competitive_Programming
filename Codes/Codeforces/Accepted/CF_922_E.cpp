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

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;
ll dp[1005][10005], cost[1005];
int birds[1005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int sum = 0;
    ll n, w, b, x;
    cin >> n >> w >> b >> x;
    for (int i = 0; i < n; i++)
    {
        cin >> birds[i];
        sum += birds[i];
    }
    for (int i = 0; i < n; i++)
        cin >> cost[i];

    memset(dp, -1, sizeof(dp));
    dp[0][0] = w;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= sum && dp[i][j] != -1; j++)
        {
            for (int k = 0; k <= birds[i] && dp[i][j] - k * cost[i] >= 0; k++)
            {
                dp[i + 1][j + k] = max(dp[i + 1][j + k], min(dp[i][j] - k * cost[i] + x, w + (j + k) * b));
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= sum; i++)
        if (dp[n][i] != -1)
            ans = max(ans, i);
    cout << ans << endl;

    return 0;
}
