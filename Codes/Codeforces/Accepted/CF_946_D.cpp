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

const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
ll skip[505][505], dp[505][505], cnt[505];
string str[505];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    /*freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);*/
    int n, m, k, sum = 0;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        for (int j = 0; j < m; j++)
            if (str[i][j] == '1')
                cnt[i]++;
    }

    memset(skip, 1, sizeof(skip));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (str[i][j] == '0')
                continue;
            int temp = 0;
            for (int l = j; l < m; l++)
            {
                if (str[i][l] == '1')
                {
                    temp++;
                    int x = cnt[i] - temp;
                    skip[i][x] = min(skip[i][x], (ll)l - j + 1);
                }
            }
        }
        skip[i][cnt[i]] = 0;
    }

    memset(dp, 1, sizeof(dp));
    for (int i = 0; i <= k; i++)
        dp[0][i] = skip[0][i];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            for (int l = 0; l + j <= k; l++)
            {
                dp[i][j + l] = min(dp[i][j + l], dp[i - 1][j] + skip[i][l]);
            }
        }
    }
    ll ans = infll;
    for (int i = 0; i <= k; i++)
        ans = min(ans, dp[n - 1][i]);
    cout << ans << endl;

    return 0;
}
