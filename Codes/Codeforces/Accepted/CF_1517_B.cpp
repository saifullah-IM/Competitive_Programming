
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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    cin >> test;
    while (test--)
    {
        int n, m;
        cin >> n >> m;
        vector<vi> ans(n, vi(m, -1));
        vector<msi> myset(n);
        vector<pair<int, pii>> numbers;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                int x;
                cin >> x;
                numbers.pb(mp(x, mp(i, j)));
                myset[i].insert(x);
            }
        sort(numbers.begin(), numbers.end());
        for (int i = 0; i < m; i++)
        {
            auto it = numbers[i];
            ans[it.se.fi][i] = it.fi;
            myset[it.se.fi].erase(myset[it.se.fi].find(it.fi));
        }
        for (int i = 0; i < n; i++)
        {
            int idx = 0;
            for (auto it : myset[i])
            {
                while (ans[i][idx] != -1)
                    idx++;
                ans[i][idx] = it;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << ' ';
            cout << '\n';
        }
    }

    return 0;
}