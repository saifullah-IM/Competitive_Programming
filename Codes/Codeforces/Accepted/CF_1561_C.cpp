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
#define inf (1 << 30)
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
typedef multiset<int>::iterator mit;
typedef map<int, int> mii;
typedef map<int, int>::iterator miit;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;

vi caves[MX];
vector<pii> order;

bool willWin(int n, int power)
{
    //cout << "------------   " << power << "   ------------\n";
    for (int i = 0; i < n; i++)
    {
        int cave = order[i].se;
        for (int u : caves[cave])
        {
            //cout << power << ' ' << u << '\n';
            if (power <= u)
                return false;
            else
                power += 1;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        order.resize(n);
        for (int i = 0; i < n; i++)
        {
            int ki, min_entry = 0;
            cin >> ki;
            caves[i].resize(ki);
            for (int j = 0; j < ki; j++)
            {
                cin >> caves[i][j];
                min_entry = max(min_entry, caves[i][j] - j + 1);
            }
            order[i] = mp(min_entry, i);
        }
        sort(order.begin(), order.end());

        int ans, lo = 0, hi = inf;
        while (lo <= hi)
        {
            int mid = (lo + hi) / 2;
            if (willWin(n, mid))
            {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }

        cout << ans << '\n';
    }

    return 0;
}