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

const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;

int tree[3 * maxn];
void propagate(int pos, int L, int R)
{
    int x = pos * 2, mid = (L + R) / 2;
    tree[x] += tree[pos];
    tree[x + 1] += tree[pos];
    tree[pos] = 0;
    return;
}

void update(int pos, int L, int R, int l, int r)
{
    if (L >= l && R <= r)
    {
        tree[pos] += 1;
        return;
    }
    if (tree[pos])
        propagate(pos, L, R);
    int x = pos * 2, mid = (L + R) / 2;
    if (mid >= l)
        update(x, L, mid, l, r);
    if (mid < r)
        update(x + 1, mid + 1, R, l, r);
    return;
}

int query(int pos, int L, int R, int node)
{
    if (L == R && R == node)
        return tree[pos] % 2;
    if (tree[pos])
        propagate(pos, L, R);
    int x = pos * 2, mid = (L + R) / 2;
    if (mid >= node)
        return query(x, L, mid, node);
    else
        return query(x + 1, mid + 1, R, node);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string str1, str2;
        cin >> str1 >> str2;
        memset(tree, 0, sizeof(tree));

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int s1 = str1[i] - '0';
            int s2 = str2[i] - '0';
            s2 ^= query(1, 1, n, i + 1);
            if (s1 != s2)
            {
                if (i + k > n)
                {
                    ans = -1;
                    break;
                }
                ans++;
                update(1, 1, n, i + 1, i + k);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
