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

const int mx = 3e5 + 5;
const int MOD = 1e9 + 7;
int divs[mx];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m, n, sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + i; j <= n; j += i)
        {
            divs[j]++, sum++;
        }
    }
    if (sum < m)
    {
        cout << "No" << endl;
        return 0;
    }
    else if (m == 0)
    {
        cout << "Yes" << endl
             << 1 << endl
             << 1 << endl;
        return 0;
    }
    while (sum - divs[n] >= m)
    {
        sum -= divs[n];
        n--;
    }
    map<int, vi, greater<int>> mymap;
    set<int> ans;
    for (int i = 1; i <= n; i++)
    {
        if (divs[i] == 1)
            mymap[n / i].pb(i);
        ans.insert(i);
    }
    sum -= m;
    while (sum)
    {
        auto it = mymap.lower_bound(sum);
        int x = it->first;
        sum -= x;
        ans.erase(mymap[x].back());
        mymap[x].pop_back();
        if (mymap[x].empty())
            mymap.erase(x);
    }
    cout << "Yes" << endl;
    cout << ans.size() << endl;
    for (auto u : ans)
        cout << u << ' ';
    cout << endl;

    return 0;
}
