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
bool dp[2][505][505];
int coin[505];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n, q;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> coin[i];
    ///for (int i=0;i<=n;i++) for (int j=0;j<=m;j++) dp[i][j][0]=true;
    dp[0][0][0] = true;
    for (int i = 1; i <= n; i++)
    {
        int now = i % 2;
        int last = 1 - now;
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                dp[now][j][k] = dp[last][j][k];
                if (j >= coin[i])
                {
                    dp[now][j][k] |= dp[last][j - coin[i]][k];
                    if (k >= coin[i])
                        dp[now][j][k] |= dp[last][j - coin[i]][k - coin[i]];
                }
            }
        }
    }
    int ans = 0;
    vi vec;
    for (int i = 0; i <= m; i++)
    {
        if (dp[n % 2][m][i])
        {
            ans++;
            vec.pb(i);
        }
    }
    cout << ans << endl;
    for (int u : vec)
        cout << u << ' ';
    cout << endl;

    return 0;
}