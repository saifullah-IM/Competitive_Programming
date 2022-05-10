/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
/* copied from solaimanope */

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

const int mx = 2e4 + 5;
const int MOD = 1e9 + 7;

char str[2 * mx];
int p, idx, candy[mx], stone[mx];
ll dp[2][mx], up[mx], down[mx];
inline int plusMod(int i, int j)
{
    return (candy[i] + stone[j] < p ? candy[i] + stone[j] : candy[i] + stone[j] - p);
}
ll solve(int lrow, int hrow, int lcol, int hcol)
{
    ll ans = 0;
    if (lrow == hrow)
    {
        ans += plusMod(lrow, lcol);
        for (int i = lcol + 1; i <= hcol; i++)
        {
            ans += plusMod(lrow, i);
            str[idx++] = 'S';
        }
        return ans;
    }

    int mid = (lrow + hrow) / 2, x;
    for (int i = lrow; i <= mid; i++)
    {
        x = i % 2;
        for (int j = lcol; j <= hcol; j++)
        {
            dp[x][j] = plusMod(i, j);
            ll temp = 0;
            if (j > lcol)
                temp = dp[x][j - 1];
            if (i > lrow)
                temp = max(temp, dp[x ^ 1][j]);
            dp[x][j] += temp;
        }
    }

    x = mid % 2;
    for (int i = lcol; i <= hcol; i++)
        down[i] = dp[x][i];

    for (int i = hrow; i > mid; i--)
    {
        x = i % 2;
        for (int j = hcol; j >= lcol; j--)
        {
            dp[x][j] = plusMod(i, j);
            ll temp = 0;
            if (j < hcol)
                temp = dp[x][j + 1];
            if (i < hrow)
                temp = max(temp, dp[x ^ 1][j]);
            dp[x][j] += temp;
        }
    }

    x = (mid + 1) % 2;
    for (int i = lcol; i <= hcol; i++)
        up[i] = dp[x][i];

    ll res = -1;
    int id;
    for (int i = lcol; i <= hcol; i++)
    {
        if (up[i] + down[i] > res)
        {
            res = up[i] + down[i];
            id = i;
        }
    }

    ll bam = solve(lrow, mid, lcol, id);
    str[idx++] = 'C';
    ll dan = solve(mid + 1, hrow, id, hcol);
    assert(bam + dan == res);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m >> p;
    for (int i = 0; i < n; i++)
    {
        cin >> candy[i];
        candy[i] %= p;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> stone[i];
        stone[i] %= p;
    }
    ll ans = solve(0, n - 1, 0, m - 1);
    str[idx] = '\0';
    cout << ans << endl
         << str << endl;

    return 0;
}
