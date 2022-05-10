/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 2e5 + 5;
const int MOD = 1e9 + 7;
int ara[2][mx], num[mx];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    ost tree;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ara[0][i];
        tree.insert(ara[0][i]);
    }
    for (int i = 0; i < n; i++)
    {
        num[i] += tree.ook(ara[0][i]);
        tree.erase(ara[0][i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> ara[1][i];
        tree.insert(ara[1][i]);
    }
    for (int i = 0; i < n; i++)
    {
        num[i] += tree.ook(ara[1][i]);
        tree.erase(ara[1][i]);
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (i)
            num[i - 1] += num[i] / (n - i);
        num[i] %= (n - i);
    }
    for (int i = 0; i < n; i++)
        tree.insert(i);
    for (int i = 0; i < n; i++)
    {
        int x = *tree.fbo(num[i]);
        cout << x << ' ';
        tree.erase(x);
    }
    cout << endl;

    return 0;
}