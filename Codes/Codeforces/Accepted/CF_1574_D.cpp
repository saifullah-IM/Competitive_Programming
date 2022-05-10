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
    //cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        vector<vi> slot(n);
        for (int i = 0; i < n; i++)
        {
            int ci;
            cin >> ci;
            slot[i].resize(ci);
            for (int j = 0; j < ci; j++)
                cin >> slot[i][j];
        }

        int m;
        cin >> m;
        vector<vi> banned(m, vi(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                cin >> banned[i][j];
                banned[i][j] -= 1;
            }

        sort(banned.begin(), banned.end());

        vi best(n);
        vi ans(n, -1);
        for (int i = 0; i < n; i++)
            best[i] = slot[i].size() - 1;
        if (!binary_search(banned.begin(), banned.end(), best))
            ans = best;
        else
        {
            int mx = 0;
            for (int i = 0; i < m; i++)
            {
                vi temp = banned[i];
                int sum = 0;
                for (int j = 0; j < n; j++)
                    sum += slot[j][temp[j]];
                for (int j = 0; j < n; j++)
                    if (temp[j] != 0)
                    {
                        temp[j] -= 1;
                        if (!binary_search(banned.begin(), banned.end(), temp) && sum - slot[j][temp[j] + 1] + slot[j][temp[j]] > mx)
                        {
                            mx = sum - slot[j][temp[j] + 1] + slot[j][temp[j]];
                            ans = temp;
                        }
                        temp[j] += 1;
                    }
            }
        }

        for (int u : ans)
            cout << u + 1 << ' ';
        cout << '\n';
    }

    return 0;
}