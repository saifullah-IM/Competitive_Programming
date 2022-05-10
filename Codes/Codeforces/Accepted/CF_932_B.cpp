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

const int mx = 1e6 + 5;
const int MOD = 1e9 + 7;
vi val[10];
int dp[mx];
void prep()
{
    for (int i = 1; i < 10; i++)
        dp[i] = i;
    for (int i = 1; i < mx; i++)
    {
        int k = i;
        int m = 1;
        while (k > 0)
        {
            if (k % 10 != 0)
                m *= k % 10;
            k /= 10;
        }
        dp[i] = dp[m];
    }
    for (int i = 1; i < mx; i++)
    {
        ///if (dp[i]==6) cout<<i<<endl;
        val[dp[i]].pb(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    prep();
    int q, l, r, k, ans;
    cin >> q;
    while (q--)
    {
        cin >> l >> r >> k;
        ans = upper_bound(val[k].begin(), val[k].end(), r) - lower_bound(val[k].begin(), val[k].end(), l);
        cout << ans << endl;
    }

    return 0;
}
