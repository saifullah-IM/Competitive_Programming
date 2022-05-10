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

const int mx = 2e5 + 5;
const int MOD = 1e9 + 7;
ll sz, ara[mx], aux[mx];
int mini[mx * 3], lazy[mx * 3];
void build(int pos, int L, int R)
{
    if (L == R)
    {
        mini[pos] = sz - L;
        ///cout<<"build"<<L<<' '<<mini[pos]<<endl;
        return;
    }
    int x = pos * 2, mid = (L + R) / 2;
    build(x, L, mid);
    build(x + 1, mid + 1, R);
    mini[pos] = min(mini[x], mini[x + 1]);
    ///cout<<"build"<<L<<' '<<R<<' '<<mini[pos]<<endl;
}
void propagate(int pos, int L, int R)
{
    int x = pos * 2, mid = (L + R) / 2;
    mini[x] += lazy[pos];
    mini[x + 1] += lazy[pos];
    lazy[x] += lazy[pos];
    lazy[x + 1] += lazy[pos];
    lazy[pos] = 0;
}
void update(int pos, int L, int R, int l, int r, int val)
{
    if (L > r || l > R)
        return;
    if (L >= l && R <= r)
    {
        mini[pos] += val;
        lazy[pos] += val;
        return;
    }
    if (lazy[pos] != 0)
        propagate(pos, L, R);
    int x = pos * 2, mid = (L + R) / 2;
    if (mid >= l)
        update(x, L, mid, l, r, val);
    if (mid < r)
        update(x + 1, mid + 1, R, l, r, val);
    mini[pos] = min(mini[x], mini[x + 1]);
    ///cout<<"update   "<<L<<' '<<R<<' '<<mini[pos]<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
        cin >> aux[i];
    for (int i = 1; i <= n; i++)
        cin >> ara[i];
    sort(aux, aux + m);
    sz = m + 1;
    build(1, 1, sz);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll need = k - ara[i];
        int x = lower_bound(aux, aux + m, need) - aux + 1;
        ///cout<<ara[i]<<' '<<x<<' '<<aux[x-1]<<endl;
        update(1, 1, sz, 1, x, -1);
        if (i >= m)
        {
            if (mini[1] >= 0)
                ans++;
            ///cout<<"min   "<<mini[1]<<endl;
            ll auxneed = k - ara[i - m + 1];
            int z = lower_bound(aux, aux + m, auxneed) - aux + 1;
            update(1, 1, sz, 1, z, 1);
        }
    }
    cout << ans << endl;

    return 0;
}
