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

const int MX = 1e5 + 5;
const int MOD = 998244353;

inline int add(int x, int y)
{
    return (x + y) % MOD;
}

inline int mult(int x, int y)
{
    return ((ll)x * y) % MOD;
}

int nCr[502][502];

void preCalcNCR()
{
    for (int i = 0; i <= 500; i++)
        nCr[i][0] = 1;

    for (int n = 1; n <= 500; n++)
        for (int r = 1; r <= n; r++)
            nCr[n][r] = add(nCr[n - 1][r], nCr[n - 1][r - 1]);
}

int dp[502][502];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    preCalcNCR();

    int test = 1;
    // cin >> test;
    while (test--)
    {
        int n, x;
        cin >> n >> x;
        dp[n][0] = 1;

        for (int i = n; i > 1; i--)
            for (int j = 0; j < x; j++)
            {
                if (dp[i][j] == 0)
                    continue;

                int pw = 1;
                int nj = min(x, j + i - 1);

                for (int k = i; k >= 0; k--)
                {
                    dp[k][nj] = add(dp[k][nj], mult(dp[i][j], mult(nCr[i][k], pw)));
                    pw = mult(pw, nj - j);
                }
            }

        int ans = 0;
        for (int j = 0; j <= x; j++)
            ans = add(ans, dp[0][j]);

        cout << ans << '\n';
    }

    return 0;
}