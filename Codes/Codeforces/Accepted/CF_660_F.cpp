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
vector<ll> m, b;
bool baad(int f1, int f2, int f3)
{
    return 1.0 * (b[f1] - b[f3]) * (m[f2] - m[f1]) > 1.0 * (b[f1] - b[f2]) * (m[f3] - m[f1]);
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
    }
}
ll P[maxn], S[maxn];
ll f(int i, ll x)
{
    return m[i] * x + b[i];
}
ll query(int i)
{
    ll ans = 0;
    int lo = 0, hi = m.size() - 1;
    while (lo <= hi)
    {
        int mid1 = (lo + lo + hi) / 3;
        int mid2 = (lo + hi + hi) / 3;
        ll y1 = f(mid1, P[i + 1]), y2 = f(mid2, P[i + 1]);
        ans = max(ans, max(y1, y2));
        if (y1 > y2)
            hi = mid2 - 1;
        else
            lo = mid1 + 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        P[i] = P[i - 1] + x;
        S[i] = S[i - 1] + x * i;
        ans = max(ans, query(i - 1) + S[i]);
        add(-i, i * P[i] - S[i]);
    }
    cout << ans << endl;

    return 0;
}
