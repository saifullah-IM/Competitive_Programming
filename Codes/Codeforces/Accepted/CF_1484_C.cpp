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

vi friends[mx];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int test;
    cin >> test;
    while (test--) {
        int n, m;
        cin >> n >> m;

        vi taken(n + 1, 0);
        vi ans(m);
        bool ok = true;
        int limit = (m + 1) / 2;

        for (int i = 0; i < m; i++) {
            int k;
            cin >> k;
            friends[i].resize(k);
            for (int j = 0; j < k; j++) cin >> friends[i][j];
            if (k == 1) {
                taken[friends[i][0]] += 1;
                ans[i] = friends[i][0];
                if (taken[friends[i][0]] > limit) ok = false;
            }
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        for (int i = 0; i < m; i++) {
            int to_take = -1;
            int take_mini = inf;
            int k = friends[i].size();
            if (k == 1) continue;
            for (int j = 0; j < k; j++) {
                if (taken[friends[i][j]] < take_mini) {
                    take_mini = taken[friends[i][j]];
                    to_take = friends[i][j];
                }
            }
            assert(to_take != -1);
            taken[to_take] += 1;
            if (taken[to_take] > limit) {
                ok = false;
                break;
            }
            else ans[i] = to_take;
        }

        if (ok) {
            cout << "YES\n";
            for (int i = 0; i < m; i++) cout << ans[i] << ' ';
            cout << '\n';
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
