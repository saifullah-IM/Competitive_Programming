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

int query(int idx, vi& tree){
    ll sum = 0;
    while (idx > 0) {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum % MOD;
}

void update(int idx, int x, int n, vi& tree)
{
    while (idx <= n) {
        tree[idx] = ((ll) x + tree[idx]) % MOD;
        idx += idx & (-idx);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int test = 1;
    cin >> test;
    while (test--) {
        int n, k;
        cin >> n >> k;
        vi forward(n + 1, 0), rev(n + 1, 0);
        bool go_forward = false;
        update(1, 1, n, forward);
        ll ans = 1;
        for (int i = k - 1; i >= 1; i--) {
            if (go_forward) {
                fill(forward.begin(), forward.end(), 0);
                for (int j = 1; j <= n; j++) {
                    int temp = query(n - j + 1, rev);
                    ans = (ans + temp) % MOD;
                    //cout << "----- " << i << ' ' << temp << ' ' << ans << endl;
                    if (j != n) {
                        update(j + 1, temp, n, forward);
                    }
                }
                go_forward = false;
            }
            else {
                fill(rev.begin(), rev.end(), 0);
                for (int j = n; j >= 1; j--) {
                    int temp = query(j, forward);
                    //cout << "----- " << i << ' ' << temp << ' ' << ans << endl;
                    ans = (ans + temp) % MOD;
                    if (j != 1) {
                        update(n - j + 2, temp, n, rev);
                    }
                }
                go_forward = true;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
