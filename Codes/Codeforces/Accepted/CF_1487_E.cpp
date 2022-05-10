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
#define inf INT_MAX/2
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

    vector <int> ns(4);
    for (int i = 0; i < 4; i++) cin >> ns[i];
    
    vector <vi> cost(4);
    for (int i = 0; i < 4; i++) {
        cost[i].resize(ns[i]);
        for (int j = 0; j < ns[i]; j++) cin >> cost[i][j];
    }

    vector <vector <vi>> bad(3);
    for (int i = 0; i < 3; i++) {
        bad[i].resize(ns[i + 1]);
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            bad[i][y].push_back(x);
        }
    }

    vector <vi> dp(4);
    dp[0] = cost[0];
    for (int i = 0; i < 3; i++) {
        dp[i + 1].resize(ns[i + 1]);
        msi myset;
        for (auto it: dp[i]) myset.insert(it);
        for (int j = 0; j < ns[i + 1]; j++) {
            for (auto x: bad[i][j]) {
                myset.erase(myset.find(dp[i][x]));
            }

            if (myset.empty()) dp[i + 1][j] = int(4e8 + 5);
            else dp[i + 1][j] = cost[i + 1][j] + *myset.begin();

            for (auto x: bad[i][j]) {
                myset.insert(dp[i][x]);
            }
        }
    }

    int ans = *min_element(dp[3].begin(), dp[3].end());
    if (ans > int(4e8)) ans = -1;
    cout << ans << endl;

    return 0;
}