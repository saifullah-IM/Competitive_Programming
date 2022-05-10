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

const int mx = 1e6 + 5;
const int MOD = 1e9 + 7;
int A[mx/2], B[mx/2], C[mx/2], index[mx];
bool used[mx/2];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int test = 1;
    //cin >> test;
    while (test--) {
        int n, m;
        ll k;
        cin >> n >> m >> k;
        if (n > m) {
            for (int i = 0; i < n; i++) {
                cin >> A[i];
            }
            for (int i = 0; i < m; i++) {
                cin >> B[i];
            }
        }
        else {
            swap(n, m);
            for (int i = 0; i < m; i++) {
                cin >> B[i];
            }
            for (int i = 0; i < n; i++) {
                cin >> A[i];
            }
        }

        for (int i = 0; i < n; i++) {
            index[A[i]] = i + 1;
            C[i] = m;
        }

        for (int i = 0; i < m; i++) {
            if (index[B[i]] == 0) {
                continue;
            }
            int x = index[B[i]] - i;
            if (x < 1) {
                x += n;
            }
            x--;
            C[x]--;
        }

        int x = 0;
        vi match_ara;
        while(!used[x]) {
            used[x] = true;
            match_ara.pb(C[x]);
            x = (x + m) % n;
        }

        ll sum = 0;
        for (int v: match_ara) {
            sum += v;
        }

        ll ans = 0;
        ans += (ll)match_ara.size() * (ll)m * ((k - 1) / sum);

        k %=  sum;
        if (k == 0) {
            k = sum;
        }

        x = 0;
        while (k > C[x]) {
            k -= C[x];
            ans += m;
            x = (x + m) % n;
        }

        for (int i = 0; i < m; i++) {
            if (k == 0) {
                break;
            }
            if (B[i] != A[x]) {
                k--;
            }
            ans++;
            x = (x + 1) % n;
        }
        cout << ans << endl;
    }

    return 0;
}
