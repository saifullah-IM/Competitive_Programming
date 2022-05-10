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

#define next NXT

const int mx = 4e5 + 5;
const int MOD = 1e9 + 7;

int parent[mx][20], next[mx][20];
ll weight[mx], maxi[mx][20], sum[mx][20];
int cnt = 1;

int findNext(int r)
{
    ll w = weight[r];
    for (int i = 19; i >= 0; i--)
    {
        if (parent[r][i] == -1)
            continue;
        if (maxi[r][i] < w)
            r = parent[r][i];
    }
    return parent[r][0];
}
void update(int r, ll x)
{
    ++cnt;
    weight[cnt] = x;
    parent[cnt][0] = r;
    maxi[cnt][0] = weight[r];
    for (int i = 1; (1 << i) < cnt; i++)
    {
        if (parent[cnt][i - 1] == -1)
            break;
        parent[cnt][i] = parent[parent[cnt][i - 1]][i - 1];
        maxi[cnt][i] = max(maxi[cnt][i - 1], maxi[parent[cnt][i - 1]][i - 1]);
    }
    next[cnt][0] = findNext(cnt);
    sum[cnt][0] = weight[next[cnt][0]];
    for (int i = 1; (1 << i) < cnt; i++)
    {
        if (next[cnt][i - 1] == -1)
            break;
        next[cnt][i] = next[next[cnt][i - 1]][i - 1];
        sum[cnt][i] = sum[cnt][i - 1] + sum[next[cnt][i - 1]][i - 1];
    }
}
int query(int r, ll x)
{
    if (weight[r] > x)
        return 0;
    int ans = 1;
    x -= weight[r];
    for (int i = 19; i >= 0; i--)
    {
        if (next[r][i] == -1)
            continue;
        if (x >= sum[r][i])
        {
            x -= sum[r][i];
            r = next[r][i];
            ans += (1 << i);
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll ans = 0, q, t, r, x;
    memset(parent, -1, sizeof(parent));
    memset(next, -1, sizeof(next));
    weight[1] = 0;
    cin >> q;
    while (q--)
    {
        cin >> t >> r >> x;
        r ^= ans;
        x ^= ans;
        if (t == 1)
            update(r, x);
        else
        {
            ans = query(r, x);
            cout << ans << endl;
        }
    }

    return 0;
}