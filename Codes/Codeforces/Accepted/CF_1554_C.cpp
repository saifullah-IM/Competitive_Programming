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
const int MOD = 1e9 + 7;
//const int MOD = 998244353;

int solve(unsigned int n, unsigned int m)
{
    unsigned int ans = m + 1;
    for (int i = 0; i < 31; i++)
    {
        unsigned int mask = (1 << i);
        if ((m & mask) == 0)
        {
            unsigned int k;
            if ((n & mask) == 0)
                k = mask;
            else
                k = 0;
            unsigned int m1 = (m >> (i + 1));
            unsigned int n1 = (n >> (i + 1));
            unsigned int k1 = (m1 ^ n1);
            k1 = (k1 << (i + 1));
            if (m1 != 0)
                k = (k | k1);
            ans = min(ans, k);
        }
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    cin >> test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        cout << solve(n, m) << '\n';
    }

    return 0;
}