/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define infll (1LL << 62)
#define abs(X) ((X) > 0 ? (X) : (-(X)))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;
int ara[mx], temp[mx], tree[2][mx];
mii mymap;
void update(int id, int idx, int val, int n)
{
    if (!id)
        idx = n - idx + 1;
    while (idx <= n)
    {
        tree[id][idx] += val;
        idx += (idx & -idx);
    }
}
int query(int id, int idx, int n)
{
    int ans = 0;
    if (!id)
        idx = n - idx + 1;
    while (idx > 0)
    {
        ans += tree[id][idx];
        idx -= (idx & -idx);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> ara[i];
        temp[i] = ara[i];
    }
    sort(temp, temp + n);
    for (int i = 0; i < n; i++)
    {
        mymap[temp[i]] = i + 1;
    }
    ll inv = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        inv += query(1, mymap[ara[i]] - 1, n);
        update(1, mymap[ara[i]], 1, n);
    }
    int lo = 0, hi = 0;
    ll ans = 0, cnt = 0;
    for (lo = 0; lo < n; lo++)
    {
        inv += query(0, mymap[ara[lo]] + 1, n) + query(1, mymap[ara[lo]] - 1, n);
        update(0, mymap[ara[lo]], 1, n);
        while (hi < n && (inv > k || hi <= lo))
        {
            inv -= query(0, mymap[ara[hi]] + 1, n) + query(1, mymap[ara[hi]] - 1, n);
            update(1, mymap[ara[hi]], -1, n);
            hi++;
        } ///cout<<lo<<' '<<hi<<' '<<ans<<endl;
        ans += n - hi;
    }
    cout << ans << endl;

    return 0;
}
