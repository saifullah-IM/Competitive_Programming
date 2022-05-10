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
typedef vector<ll> vl;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;

vl num;
ll pow2[31], pow3[20];

void prep()
{
    pow2[0] = pow3[0] = 1;
    for (int i = 1; i < 31; i++)
        pow2[i] = pow2[i - 1] * 2;
    for (int i = 1; i < 20; i++)
        pow3[i] = pow3[i - 1] * 3;
    for (int i = 0; i < 31; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            num.pb(pow2[i] * pow3[j]);
        }
    }
    sort(num.begin(), num.end());
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    prep();
    int l, r;
    cin >> l >> r;
    int ans = upper_bound(num.begin(), num.end(), r) - lower_bound(num.begin(), num.end(), l);
    cout << ans << endl;

    return 0;
}
