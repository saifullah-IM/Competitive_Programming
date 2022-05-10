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
//const int MOD = 998244353;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int test = 1;
    //cin >> test;
    while (test--) {
        int L, R;
        cin >> L >> R;
        int k = 0;
        int d = R - L;
        while (d != 0) {
            k++;
            d /= 2;
        }

        int n = 2;
        d = R - L;
        vector <vi> graph(k + 5, vi(k + 5, -1));
        graph[0][1] = L;

        for (int i = 1; i <= k; i++) {
            for (int j = i + 1; j <= k + 1; j++) {
                graph[i][j] = (1 << max(0, i - 2));
                n = max(n, j + 1);
            }
        }

        if (d > 0 && d != (1 << (k - 1))) {
            int x = d = d - 1;
            int u = 0;
            while (x != 0) {
                if (x % 2 == 1) {       
                    graph[u + 2][k + 2] = 1 + ((d >> (u + 1)) << (u + 1));
                    n = max(n, k + 3);
                }
                u++;
                x /= 2;
            }
            graph[1][n - 1] = 1;
        }
        graph[0][n - 1] = L;
        
        vector <pair <pii, int>> edges;
        for (int i = 0; i < k + 5; i++) {
            for (int j = i + 1; j < k + 5; j++) {
                if (graph[i][j] != -1) {
                    edges.pb(mp(mp(i + 1, j + 1), graph[i][j]));
                }
            }
        }

        cout << "YES\n";
        cout << n << ' ' << edges.size() << '\n';
        for (auto it : edges) {
            cout << it.fi.fi << ' ' << it.fi.se << ' ' << it.se << '\n';
        }
    }

    return 0;
}