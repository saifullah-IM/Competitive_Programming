/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std; /*
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
set<pii> notWork;
int main()
{
    ///ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, q, ans;
    ///cin>>n>>q;
    scanf("%d %d", &n, &q);
    ans = n;
    while (q--)
    {
        int l, r, k;
        ////cin>>l>>r>>k;
        scanf("%d %d %d", &l, &r, &k);
        if (k == 1)
        {
            while (!notWork.empty())
            {
                auto it = notWork.lower_bound(pii(l, 0));
                if (it == notWork.end())
                    break;
                if (it->se > r)
                    break;
                l = min(l, it->se);
                r = max(r, it->fi);
                ans += it->fi - it->se + 1;
                notWork.erase(it);
            }
            ans -= r - l + 1;
            notWork.insert(pii(r, l));
        }
        else
        {
            while (!notWork.empty())
            {
                auto it = notWork.lower_bound(pii(l, 0));
                if (it == notWork.end())
                    break;
                if (it->se > r)
                    break;
                ans += it->fi - it->se + 1;
                if (l > it->se)
                {
                    ans -= l - it->se;
                    notWork.insert(pii(l - 1, it->se));
                }
                if (r < it->fi)
                {
                    ans -= it->fi - r;
                    notWork.insert(pii(it->fi, r + 1));
                }
                notWork.erase(it);
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}
