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

const int mx = 3e5 + 5;
const int MOD = 1e9 + 7;

ll seg_tree[mx * 4];

void build()
{
    for (int i = 0; i < mx * 4; i++) {
        seg_tree[i] = -inf;
    }
}

void update(int node, int L, int R, int pos, ll val)
{
    if (L == R) {
        seg_tree[node] = val;
        return;
    }

    int mid = (L + R) / 2;
    int left_node = node * 2;
    int right_node = node * 2 + 1;
    if (pos <= mid) update(left_node, L, mid, pos, val);
    else update(right_node, mid + 1, R, pos, val);
    seg_tree[node] = max(seg_tree[left_node], seg_tree[right_node]);
}

ll query(int node, int L, int R, int l, int r)
{
    if (r < L || l > R) {
        return -inf;
    }
    if (L >= l && R <= r) {
        return seg_tree[node];
    }
    
    int mid = (L + R) / 2;
    ll left = query(node * 2, L, mid, l, r);
    ll right = query(node * 2 + 1, mid + 1, R, l, r);
    return max(left, right);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int test = 1;
    //cin >> test;
    while (test--) {
        int n;
        cin >> n;
        vi height(n + 1);
        vi beauty(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> height[i];
        }
        for (int i = 1; i <= n; i++) {
           cin >> beauty[i];
        }
        vi closest_smaller(n + 1);
        stack <pii> mystk;
        mystk.push(mp(-inf, 0));
        for (int i = 1; i <= n; i++) {
            while (mystk.top().fi > height[i]) {
                mystk.pop();
            }
            auto it = mystk.top();
            closest_smaller[i] = it.se;
            mystk.push(mp(height[i], i));
        }
        build();
        vector <ll> dp(n + 1);
        update(1, 0, n, 0, 0);
        for (int i = 1; i <= n; i++) { 
            int prev = closest_smaller[i];
            dp[i] = query(1, 0, n, prev, i - 1) + beauty[i];
            if (prev != 0) dp[i] = max(dp[prev], dp[i]);
            update(1, 0, n, i, dp[i]);
        }
        cout << dp[n] << endl;
    }

    return 0;
}
