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

const int maxn = 2e5 + 5;
const int MOD = 1e9 + 7;
si points[maxn];
mii mymap, rev;
int temp[maxn], tree[maxn * 3];
pair<int, pii> op[maxn];
void update(int pos, int L, int R, int mx, int my, bool type)
{
    if (L == R)
    {
        if (type)
        {
            points[mx].insert(my);
            auto it = points[mx].end();
            it--;
            tree[pos] = *it;
        }
        else
        {
            points[mx].erase(my);
            if (points[mx].empty())
                tree[pos] = -1;
            else
            {
                auto it = points[mx].end();
                it--;
                tree[pos] = *it;
            }
        }
        return;
    }
    int x = pos * 2, mid = (L + R) / 2;
    if (mid >= mx)
        update(x, L, mid, mx, my, type);
    else
        update(x + 1, mid + 1, R, mx, my, type);
    tree[pos] = max(tree[x], tree[x + 1]);
}
int query(int pos, int L, int R, int mx, int my)
{
    if (tree[pos] <= my)
        return -1;
    if (L == R)
    {
        if (L > mx)
            return L;
        else
            return -1;
    }
    int x = pos * 2, mid = (L + R) / 2;
    if (mid <= mx)
        return query(x + 1, mid + 1, R, mx, my);
    else if (tree[x] <= my)
        return query(x + 1, mid + 1, R, mx, my);
    else
    {
        int ret = query(x, L, mid, mx, my);
        if (ret == -1)
            ret = query(x + 1, mid + 1, R, mx, my);
        return ret;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int q, x, y;
    string cmd;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> cmd >> x >> y;
        if (cmd == "add")
            op[i] = mp(1, mp(x, y));
        else if (cmd == "remove")
            op[i] = mp(2, mp(x, y));
        else
            op[i] = mp(3, mp(x, y));
        temp[i] = x;
    }
    sort(temp, temp + q);
    int k = 0, last = -1;
    for (int i = 0; i < q; i++)
    {
        if (temp[i] == last)
            continue;
        mymap[temp[i]] = ++k;
        rev[k] = temp[i];
        last = temp[i];
    }
    memset(tree, -1, sizeof(tree));
    for (int i = 0; i < q; i++)
    {
        auto it = op[i];
        if (it.first == 1)
            update(1, 1, k, mymap[it.second.first], it.second.second, true);
        else if (it.first == 2)
            update(1, 1, k, mymap[it.second.first], it.second.second, false);
        else
        {
            int mx = query(1, 1, k, mymap[it.second.first], it.second.second);
            if (mx != -1)
            {
                int my = *points[mx].upper_bound(it.second.second);
                cout << rev[mx] << ' ' << my << endl;
            }
            else
                cout << -1 << endl;
        }
    }

    return 0;
}
