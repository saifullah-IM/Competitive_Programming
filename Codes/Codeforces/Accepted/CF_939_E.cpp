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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 5e5 + 5;
const int MOD = 1e9 + 7;
ll sum[mx], num[mx];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    int n = 0;
    while (q--)
    {
        ll t, x;
        cin >> t;
        if (t == 1)
        {
            cin >> x;
            n++;
            num[n] = x;
            sum[n] = sum[n - 1] + x;
        }
        else
        {
            int lo = 1;
            int hi = n - 1;
            int mid1, mid2;
            double ans = 0;
            while (hi - lo > 2)
            {
                int k = (hi - lo) / 3;
                mid1 = lo + k;
                mid2 = mid1 + k;
                ll ss = num[n] + sum[mid1];
                double temp1 = (double)num[n] - (double)ss / (mid1 + 1);
                ss = num[n] + sum[mid2];
                double temp2 = (double)num[n] - (double)ss / (mid2 + 1);
                ans = max(ans, max(temp1, temp2));
                if (temp1 >= temp2)
                    hi = mid2 - 1;
                else
                    lo = mid1 + 1;
            }
            for (int i = lo; i <= hi; i++)
            {
                ll ss = num[n] + sum[i];
                double temp1 = (double)num[n] - (double)ss / (i + 1);
                ans = max(ans, temp1);
            }
            cout << fixed << setprecision(12) << ans << endl;
        }
    }

    return 0;
}
