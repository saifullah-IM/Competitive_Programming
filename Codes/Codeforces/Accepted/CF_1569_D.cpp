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

const int MX = 1e6 + 5;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;

vi same[MX][2];

int count_inconvenience(int idx, vi &street, vector<pii> &people, int axis)
{
    int next_pos = lower_bound(street.begin(), street.end(), people[idx].fi) - street.begin();
    int ans = lower_bound(people.begin(), people.end(), mp(street[next_pos], -1)) - people.begin();

    ans = ans - idx - 1;

    int temp = lower_bound(same[people[idx].se][axis].begin(), same[people[idx].se][axis].end(), street[next_pos]) - lower_bound(same[people[idx].se][axis].begin(), same[people[idx].se][axis].end(), people[idx].fi);

    ans = ans - temp + 1;
    return ans;
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
        int n, m, k;
        cin >> n >> m >> k;
        vi x_ara(n), y_ara(m);
        vector<pii> only_x, only_y;
        for (int i = 0; i < n; i++)
            cin >>
                x_ara[i];
        for (int i = 0; i < m; i++)
            cin >> y_ara[i];
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            int x_idx = lower_bound(x_ara.begin(), x_ara.end(), x) - x_ara.begin();
            int y_idx = lower_bound(y_ara.begin(), y_ara.end(), y) - y_ara.begin();

            if (x_ara[x_idx] == x && y_ara[y_idx] == y)
                continue;
            else if (x_ara[x_idx] == x)
            {
                only_x.pb(mp(y, x));
                same[x][0].pb(y);
            }
            else
            {
                only_y.pb(mp(x, y));
                same[y][1].pb(x);
            }
        }

        ll ans = 0;
        sort(only_x.begin(), only_x.end());
        sort(only_y.begin(), only_y.end());
        for (auto it : only_x)
            sort(same[it.se][0].begin(), same[it.se][0].end());
        for (auto it : only_y)
            sort(same[it.se][1].begin(), same[it.se][1].end());

        for (int i = 0; i < only_x.size(); i++)
            ans += count_inconvenience(i, y_ara, only_x, 0);
        for (int i = 0; i < only_y.size(); i++)
            ans += count_inconvenience(i, x_ara, only_y, 1);
        cout << ans << '\n';

        for (auto it : only_x)
            same[it.se][0].clear();
        for (auto it : only_y)
            same[it.se][1].clear();
    }

    return 0;
}
