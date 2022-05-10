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

int n, dp[60][2], ara[60];

int solve(int pos, int chk)
{
    if (dp[pos][chk] != -1)
        return dp[pos][chk];

    int ans = 1;
    if (chk)
    {
        for (int i = pos + 1; i < n; i++)
        {
            if (ara[i] > ara[pos])
            {
                ans = max(ans, 1 + solve(i, 0));
            }
        }
    }
    else
    {
        for (int i = pos + 1; i < n; i++)
        {
            if (ara[i] < ara[pos])
            {
                ans = max(ans, 1 + solve(i, 1));
            }
        }
    }

    return dp[pos][chk] = ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ara[i];

    memset(dp, -1, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, max(solve(i, 0), solve(i, 1)));
        ///cout<<solve(i,0)<<' '<<solve(i,1)<<endl;
    }
    cout << ans << endl;

    return 0;
}
