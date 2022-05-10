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

int f(int x)
{
    if (x < 0)
        return (360 + x);
    else if (x >= 360)
        return (x % 360);
    else
        return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, y;
    cin >> x >> y;

    int a = 0, b = 0, n1 = x, n2 = y;
    for (int i = x; i <= 720; i++)
    {
        int d = f(i);
        //cout << i << " " << d << endl;
        if (d == n2)
            break;
        else
            a++;
    }

    for (int i = x; i >= -720; i--)
    {
        int d = f(i);
        // cout << i << " " << d << endl;
        if (d == n2)
            break;
        else
            b++;
    }

    // cout << a << " " << b << endl;

    if (a <= b)
        cout << a << endl;
    else
        cout << -b << endl;

    return 0;
}
