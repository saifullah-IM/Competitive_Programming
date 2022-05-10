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

int gcd (int a, int b)
{
    while (b > 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vi ara(n);
        for (int i = 0; i < n; i++) {
            cin >> ara[i];
        }
        vi next(n);
        for (int i = 0; i < n; i++) {
            next[i] = (i + 1) % n;
        }
        set <pii> bad_pairs;
        for (int i = 0; i < n; i++) {
            if (gcd(ara[i], ara[next[i]]) == 1) {
                bad_pairs.insert(mp(0, i));
            }
        }
        vi ans;
        vector <bool> deleted(n, false);
        while(!bad_pairs.empty()) {
            auto it = *bad_pairs.begin();
            bad_pairs.erase(it);
            if (deleted[it.se]) {
                continue;
            }
            int to_del = next[it.se];
            ans.pb(to_del);
            deleted[to_del] = true;
            next[it.se] = next[to_del];
            if (gcd(ara[it.se], ara[next[it.se]]) == 1) {
                bad_pairs.insert(mp(it.fi + 1, it.se));
            }
        }
        cout << ans.size() << ' ';
        for (int x : ans) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }

    return 0;
}
