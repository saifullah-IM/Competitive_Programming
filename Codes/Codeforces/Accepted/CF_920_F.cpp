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

const int N = 3e5 + 5;
const int mx = 1e6 + 6;
const int MOD = 1e9 + 7;

int cnt[mx];
void sieve()
{
    for (int i = 1; i < mx; i++)
    {
        for (int j = i; j < mx; j += i)
            cnt[j]++;
    }
}
int ara[N];
ll sum[(1 << 20) + 5];
bool chk[(1 << 20) + 5];
void build(int pos, int L, int R)
{
    if (L == R)
    {
        sum[pos] = ara[L];
        if (ara[L] <= 2)
            chk[pos] = true;
        return;
    }
    int x = pos * 2, mid = (L + R) / 2;
    build(x, L, mid);
    build(x + 1, mid + 1, R);
    chk[pos] = (chk[x] & chk[x + 1]);
    sum[pos] = sum[x] + sum[x + 1];
}
void update(int pos, int L, int R, int l, int r)
{
    if (L == R)
    {
        ara[L] = cnt[ara[L]];
        sum[pos] = ara[L];
        if (ara[L] <= 2)
            chk[pos] = true;
        return;
    }
    int x = pos * 2, mid = (L + R) / 2;
    if (!chk[x] && mid >= l)
        update(x, L, mid, l, r);
    if (!chk[x + 1] && mid < r)
        update(x + 1, mid + 1, R, l, r);
    chk[pos] = (chk[x] & chk[x + 1]);
    sum[pos] = sum[x] + sum[x + 1];
}
ll query(int pos, int L, int R, int l, int r)
{
    if (L > r || l > R)
        return 0;
    if (L >= l && R <= r)
        return sum[pos];
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
    cout.tie(0);

    sieve();
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> ara[i];
    build(1, 1, n);
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
            update(1, 1, n, l, r);
        else
            cout << query(1, 1, n, l, r) << endl;
    }

    return 0;
}
