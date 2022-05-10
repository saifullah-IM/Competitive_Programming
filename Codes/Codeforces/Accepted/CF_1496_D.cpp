#include <bits/stdc++.h>
using namespace std;/*
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
#define inf (1<<30)
#define infll (1LL<<62)
#define abs(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define fbo(k) find_by_order(k) ///returns iterator to the kth largest element counting from 0
#define ook(val) order_of_key(val) ///returns the number of items in a set that are strictly smaller than val

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef set <int> si;
typedef multiset <int> msi;
typedef multiset <int>::iterator mit;
typedef map <int, int> mii;
typedef map <int, int>::iterator miit;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;

int ara[mx], dp_inc[mx], dp_dec[mx];

int solve_inc(int idx, int n)
{
    if (idx == n || ara[idx] > ara[idx + 1]) return 1;
    if (dp_inc[idx] != -1) return dp_inc[idx];
    return dp_inc[idx] = 1 + solve_inc(idx + 1, n);
}

int solve_dec(int idx, int n)
{
    if (idx == n || ara[idx] < ara[idx + 1]) return 1;
    if (dp_dec[idx] != -1) return dp_dec[idx];
    return dp_dec[idx] = 1 + solve_dec(idx + 1, n);
}

int maxL;
vi inc_max, dec_max;

void update(int len, int start, int type)
{
    if (maxL > len) return;
    if (maxL != len) {
        inc_max.clear();
        dec_max.clear();
        maxL = len;
    }
    if (type == 1) inc_max.pb(start);
    else dec_max.pb(start);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> ara[i];

    maxL = -1;
    memset(dp_inc, -1, sizeof(dp_inc));
    memset(dp_dec, -1, sizeof(dp_dec));
    for (int i = 1; i <= n; i++) {
        int inc = solve_inc(i, n);
        int dec = solve_dec(i, n);
        update(inc, i, 1);
        update(dec, i, 0);
    }

    if (inc_max.size() == 1 && dec_max.size() == 1) {
        if (maxL % 2 == 1) {
            if (inc_max[0] + maxL - 1 == dec_max[0]) {
                cout << "1\n";
                return 0;
            }
        }
    }

    cout << "0\n";

    return 0;
}