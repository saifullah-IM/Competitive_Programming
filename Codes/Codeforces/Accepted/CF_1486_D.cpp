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

bool check (int x, int k, vi& arr)
{
    int n = arr.size();
    vi new_arr(n);
    for (int i = 0; i < n; i++) {
        if (arr[i] < x) new_arr[i] = -1;
        else new_arr[i] = 1;
    }

    vi prefix_sum(n + 1);
    prefix_sum[0] = 0;
    for (int i = 0; i < n; i++) prefix_sum[i + 1] = prefix_sum[i] + new_arr[i];
    
    int prefix_sum_min = 0;
    for (int i = 1; i + k - 1 <= n; i++) {
        int max_diff = prefix_sum[i + k - 1] - prefix_sum_min;
        if (max_diff > 0) return true;
        prefix_sum_min = min(prefix_sum_min, prefix_sum[i]);
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    vi arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int lo, hi, ans;
    ans = lo = 1;
    hi = n;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (check(mid, k, arr)) {
            ans = max(ans, mid);
            lo = mid + 1;
        }
        else hi = mid - 1;
    }

    cout << ans << endl;

    return 0;
}