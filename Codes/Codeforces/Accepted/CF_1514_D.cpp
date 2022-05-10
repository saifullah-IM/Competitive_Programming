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

//const int MOD = 998244353;
const int MOD = 1e9 + 7;
const int MX = 3e5 + 5;
int seg_tree[MX * 4];
int ara[MX];
vi index_ara[MX];

void build(int node, int l, int r)
{
    if (l == r)
    {
        seg_tree[node] = ara[l];
        return;
    }

    int mid = (l + r) / 2;
    int l_node = node * 2;
    int r_node = l_node + 1;
    build(l_node, l, mid);
    build(r_node, mid + 1, r);

    int l_count = upper_bound(index_ara[seg_tree[l_node]].begin(), index_ara[seg_tree[l_node]].end(), r) -
                  lower_bound(index_ara[seg_tree[l_node]].begin(), index_ara[seg_tree[l_node]].end(), l);
    int r_count = upper_bound(index_ara[seg_tree[r_node]].begin(), index_ara[seg_tree[r_node]].end(), r) -
                  lower_bound(index_ara[seg_tree[r_node]].begin(), index_ara[seg_tree[r_node]].end(), l);
    seg_tree[node] = l_count > r_count ? seg_tree[l_node] : seg_tree[r_node];
    return;
}

int query(int node, int l, int r, int L, int R)
{
    if (l > R || r < L)
        return 0;
    if (l >= L && r <= R)
        return seg_tree[node];

    int mid = (l + r) / 2;
    int l_node = node * 2;
    int r_node = l_node + 1;
    int l_query = query(l_node, l, mid, L, R);
    int r_query = query(r_node, mid + 1, r, L, R);

    int l_count = upper_bound(index_ara[l_query].begin(), index_ara[l_query].end(), R) -
                  lower_bound(index_ara[l_query].begin(), index_ara[l_query].end(), L);
    int r_count = upper_bound(index_ara[r_query].begin(), index_ara[r_query].end(), R) -
                  lower_bound(index_ara[r_query].begin(), index_ara[r_query].end(), L);
    return l_count > r_count ? l_query : r_query;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    //cin >> test;
    while (test--)
    {
        int n, q;
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> ara[i];
            index_ara[ara[i]].pb(i);
        }
        index_ara[0].pb(MX);
        build(1, 1, n);
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            int frequent = query(1, 1, n, l, r);
            int m = r - l + 1;
            int limit = (m + 1) / 2;
            int count = upper_bound(index_ara[frequent].begin(), index_ara[frequent].end(), r) -
                        lower_bound(index_ara[frequent].begin(), index_ara[frequent].end(), l);
            if (count <= limit)
                cout << "1\n";
            else
                cout << 2 * count - m << "\n";
        }
    }

    return 0;
}