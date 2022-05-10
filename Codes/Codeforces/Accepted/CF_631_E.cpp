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
ll S[maxn], T[maxn], U[maxn], dp[maxn], ara[maxn];
vector<ll> m, b;

bool baad(int f1, int f2, int f3, int type)
{
    if (type == 1)
    {
        return 1.0 * (b[f3] - b[f1]) * (m[f1] - m[f2]) < 1.0 * (b[f2] - b[f1]) * (m[f1] - m[f3]);
    }
    else
    {
        return 1.0 * (b[f3] - b[f1]) * (m[f1] - m[f2]) > 1.0 * (b[f2] - b[f1]) * (m[f1] - m[f3]);
    }
}
void add(ll _m, ll _b, int type)
{
    m.pb(_m);
    b.pb(_b);
    int sz = m.size();
    while (sz >= 3 && baad(sz - 3, sz - 2, sz - 1, type))
    {
        sz--;
        m.erase(m.end() - 2);
        b.erase(b.end() - 2);
    }
}
ll f(int i, ll x)
{
    return m[i] * x + b[i];
}
ll query(ll x)
{
    int lo = 0, hi = m.size() - 1;
    ll ans = -infll;
    while (lo <= hi)
    {
        int mid1 = (lo + lo + hi) / 3;
        int mid2 = (lo + hi + hi) / 3;
        ll y1 = f(mid1, x);
        ll y2 = f(mid2, x);
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
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        ara[i] = x;
        S[i] = S[i - 1] + (i - 1) * x;
        T[i] = T[i - 1] + i * x;
        U[i] = U[i - 1] + (i + 1) * x;
    }

    ll ans = T[n];
    for (int i = n; i > 0; i--)
    {
        dp[i] = query(ara[i]) + T[i - 1] - S[i];
        ans = max(ans, dp[i]);
        add(i, T[n] - T[i] + S[i], 2);
    }
    m.clear();
    b.clear();
    for (int i = 1; i <= n; i++)
    {
        dp[i] = query(ara[i]) + T[n] - T[i] + U[i - 1];
        ans = max(ans, dp[i]);
        add(i, T[i - 1] - U[i - 1], 1);
    }
    cout << ans << endl;

    return 0;
}