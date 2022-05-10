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
    int test = 1;
    scanf("%d", &test);
    for (int cas = 1; cas <= test; cas++) {
        int n;
        scanf("%d", &n);
        int count = 0;
        ll sum = 0;
        int maxi = -inf;
        bool pos = false;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            maxi = max(maxi, x);
            if (x == 0) continue;
            if (x < 0) {
                if (pos) count++;
                pos = false;
            }
            else {
                sum += x;
                pos = true;
            }
        }
        if (pos) count++;

        if (count) printf("Case %d: %lld %d\n",cas, sum, count - 1);
        else printf("Case %d: %d %d\n",cas, maxi, 0);
    }

    return 0;
}