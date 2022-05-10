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
const double eps = 1e-9;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double R, x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    double d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    d = sqrt(d);
    if (d >= R)
    {
        cout << fixed << setprecision(12) << x1 << ' ' << y1 << ' ' << R << endl;
    }
    else
    {
        double r = (d + R) / 2;
        double xx = abs(x1 - x2);
        double yy = abs(y1 - y2);
        double x, y;
        if (xx < eps)
        {
            x = x2;
            if (y1 > y2)
                y = y2 + r;
            else
                y = y2 - r;
        }
        else
        {
            double m = yy / xx;
            if (x1 > x2)
                x = x2 + r / sqrt(1 + m * m);
            else
                x = x2 - r / sqrt(1 + m * m);
            if (y1 > y2)
                y = y2 + r * m / sqrt(1 + m * m);
            else
                y = y2 - r * m / sqrt(1 + m * m);
        }

        cout << fixed << setprecision(12) << x << ' ' << y << ' ' << r << endl;
    }

    return 0;
}
