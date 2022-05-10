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

const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;

vector<ll> m, b;
int idx;
bool baad(int f1, int f2, int f3)
{
    return 1.0 * (b[f1] - b[f3]) * (m[f2] - m[f1]) < 1.0 * (b[f1] - b[f2]) * (m[f3] - m[f1]);
}
void add(ll _m, ll _b)
{
    m.pb(_m);
    b.pb(_b);
    int sz = m.size();
    while (sz >= 3 && baad(sz - 3, sz - 2, sz - 1))
    {
        m.erase(m.end() - 2);
        b.erase(b.end() - 2);
        sz--;
        idx = min(idx, sz - 1);
    }
}
ll f(int i, ll x)
{
    return m[i] * x + b[i];
}
ll query(ll x)
{
    int sz = m.size() - 1;
    while (idx < sz && f(idx, x) > f(idx + 1, x))
        idx++;
    return f(idx, x);
}
ll dp[maxn], ara[maxn], bra[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ara[i];
    for (int i = 0; i < n; i++)
        cin >> bra[i];
    add(bra[0], 0);
    for (int i = 1; i < n; i++)
    {
        dp[i] = query(ara[i]);
        add(bra[i], dp[i]);
    }
    cout << dp[n - 1] << endl;

    return 0;
}
