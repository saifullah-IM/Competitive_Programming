/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define mp make_pair
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define abs(X) ((X) > 0 ? (X) : (-(X)))
using namespace std;

///cout<<fixed<<setprecision(12)<<ans<< endl;

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VP;

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;
int color[3 * mx];
ll sum[3 * mx], lazy[3 * mx];
void build(int pos, int L, int R)
{
    if (L == R)
    {
        color[pos] = L;
        return;
    }
    int x = pos * 2, mid = (L + R) / 2;
    build(x, L, mid);
    build(x + 1, mid + 1, R);
    color[pos] = -1;
}
void propagate(int pos, int L, int R)
{
    int x = pos * 2, mid = (L + R) / 2;
    sum[x] += lazy[pos] * (mid - L + 1);
    sum[x + 1] += lazy[pos] * (R - mid);
    lazy[x] += lazy[pos];
    lazy[x + 1] += lazy[pos];
    lazy[pos] = 0;
    if (color[pos] != -1)
        color[x] = color[x + 1] = color[pos];
}
void update(int pos, int L, int R, int l, int r, ll val)
{
    if (L > r || l > R)
        return;
    if (L >= l && R <= r && color[pos] != -1)
    {
        ll temp = abs(val - color[pos]);
        lazy[pos] += temp;
        sum[pos] += temp * (R - L + 1);
        color[pos] = val;
        return;
    }
    if (lazy[pos] != 0)
        propagate(pos, L, R);
    int x = pos * 2, mid = (L + R) / 2;
    if (mid >= l)
        update(x, L, mid, l, r, val);
    if (mid < r)
        update(x + 1, mid + 1, R, l, r, val);
    sum[pos] = sum[x] + sum[x + 1];
    color[pos] = (color[x] == color[x + 1] ? color[x] : -1);
}
ll query(int pos, int L, int R, int l, int r)
{
    if (L > r || l > R)
        return 0;
    if (L >= l && r >= R)
        return sum[pos];
    if (lazy[pos] != 0)
        propagate(pos, L, R);
    int x = pos * 2, mid = (L + R) / 2;
    ll y = 0, z = 0;
    if (mid >= l)
        y = query(x, L, mid, l, r);
    if (mid < r)
        z = query(x + 1, mid + 1, R, l, r);
    return y + z;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    build(1, 1, n);
    int t, l, r, x;
    while (q--)
    {
        cin >> t >> l >> r;
        if (t == 1)
        {
            cin >> x;
            update(1, 1, n, l, r, x);
        }
        else
            cout << query(1, 1, n, l, r) << endl;
    }

    return 0;
}
