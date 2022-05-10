/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/
/* credit: aymanrasheed7 */

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

int SA[maxn], SB[maxn], TA[maxn], TB[maxn];

void process(string &str, int A[], int B[])
{
    for (int i = 1; i <= str.size(); i++)
    {
        if (str[i - 1] == 'A')
        {
            A[i] = A[i - 1] + 1;
            B[i] = B[i - 1];
        }
        else
        {
            A[i] = 0;
            B[i] = B[i - 1] + 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string source, target;
    cin >> source >> target;
    process(source, SA, SB);
    process(target, TA, TB);

    int q;
    cin >> q;
    while (q--)
    {
        int l1, l2, r1, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int sa = min(SA[r1], r1 - l1 + 1);
        int sb = SB[r1] - SB[l1 - 1];
        int ta = min(TA[r2], r2 - l2 + 1);
        int tb = TB[r2] - TB[l2 - 1];
        int da = ta - sa;
        int db = tb - sb;

        if (db < 0 || db % 2 == 1 || da > 0 || (sb == 0 && tb != 0 && da == 0))
            cout << '0';
        else if (db > 0 || da % 3 == 0)
            cout << '1';
        else
            cout << '0';
    }

    return 0;
}
