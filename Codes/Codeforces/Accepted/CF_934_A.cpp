/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>*/
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define infll (1LL << 62)
#define abs(X) ((X) > 0 ? (X) : (-(X)))
#define fbo(k) find_by_order(k)    ///returns iterator to the kth largest element counting from 0
#define ook(val) order_of_key(val) ///returns the number of items in a set that are strictly smaller than val

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n, q;

    int ara[55], num[55];
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> ara[i];
    for (int i = 0; i < m; i++)
        cin >> num[i];
    sort(ara, ara + n);
    sort(num, num + m);
    ll ans = infll;

    for (int k = 0; k < n; k++)
    {
        ll ans2 = -infll;
        for (int i = 0; i < n; i++)
        {
            if (i == k)
                continue;
            for (int j = 0; j < m; j++)
            {
                ans2 = max(ans2, (ll)ara[i] * num[j]);
            }
        }
        ans = min(ans, ans2);
    }
    cout << ans << endl;

    return 0;
}
