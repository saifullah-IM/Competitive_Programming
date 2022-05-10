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
typedef vector<ll> vl;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int maxn = 2e5 + 5;
const int MOD = 1e9 + 7;

vector<int> ans[maxn];
si idx[2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '1')
            idx[1].insert(i);
        else
            idx[0].insert(i);
    }

    int cnt = 0;
    while (!idx[1].empty())
    {
        auto it = idx[0].begin();
        int st = *it;
        int ch = 0;
        while (true)
        {
            if (ch == 0)
            {
                auto it = idx[0].lower_bound(st);
                if (it == idx[0].end())
                {
                    cout << -1 << endl;
                    return 0;
                }
                ans[cnt].pb(*it);
                st = *it;
                idx[0].erase(it);
            }
            else
            {
                auto it = idx[1].lower_bound(st);
                if (it == idx[1].end())
                {
                    break;
                }
                ans[cnt].pb(*it);
                st = *it;
                idx[1].erase(it);
            }
            ch ^= 1;
        }
        cnt++;
    }
    for (auto it : idx[0])
    {
        ans[cnt++].pb(it);
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++)
    {
        cout << ans[i].size();
        for (int u : ans[i])
            cout << ' ' << u + 1;
        cout << endl;
    }

    return 0;
}