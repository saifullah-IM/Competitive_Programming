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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while (test--) {
        int maxi = -1;
        int n;
        cin >> n;
        vi ara(n);
        for (int i = 0; i < n; i++) {
            cin >> ara[i];
            maxi = max(maxi, ara[i]);
        }
        if (n == 1) {
            cout << "0\n";
            continue;
        }

        bool neg = false;
        bool pos = false;
        bool ok = true;
        int neg_val = 1;
        int pos_val = -1;
        for (int i = 1; i < n; i++) {
            int k = ara[i] - ara[i - 1];
            if (k < 0) {
                if (neg && k != neg_val) {
                    ok = false;
                    break;
                }
                else {
                    neg = true;
                    neg_val = k;
                }
            }
            else {
                if (pos && k != pos_val) {
                    ok = false;
                    break;
                }
                else {
                    pos = true;
                    pos_val = k;
                }
            }
        }
        if (!ok) {
            cout << -1 << '\n';
        }
        else {
            if (pos && !neg || !pos && neg) {
                cout << 0 << '\n';
            } 
            else {
                int m  = pos_val + abs(neg_val); 
                if (m <= maxi) cout << -1 << '\n';
                else cout << m << ' ' << pos_val << '\n';
            }
        }
    }

    return 0;
}
