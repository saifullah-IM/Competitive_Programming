/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define mp make_pair
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define abs(X) ((X) > 0 ? (X) : (-(X)))
using namespace std;

//cout << fixed << setprecision(12) << p << endl;

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VP;

template <class T>
inline T bigmod(T p, T e, T M)
{
    ll ret = 1;
    for (; e > 0; e >>= 1)
    {
        if (e & 1)
            ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T>
inline T gcd(T a, T b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
template <class T>
inline T modinverse(T a, T M) { return bigmod(a, M - 2, M); }

const int mx = 1e5 + 5;
const int block = 320;
const int MOD = 1e9 + 7;
int k, cnt[(1 << 21) + 5], ara[mx], xorsum[mx];
ll res, ans[mx];
typedef pair<PII, int> query;
query Q[mx];
bool compare(query A, query B)
{
    int a1 = A.first.first / block, b1 = B.first.first / block;
    int a2 = A.first.second / block, b2 = B.first.second / block;
    if (a1 == b1)
        return a2 < b2;
    else
        return a1 < b1;
}
void add(int x)
{
    res += cnt[xorsum[x] ^ k];
    cnt[xorsum[x]]++;
}
void remove(int x)
{
    cnt[xorsum[x]]--;
    res -= cnt[xorsum[x] ^ k];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> ara[i];
        xorsum[i] = (xorsum[i - 1] ^ ara[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        Q[i] = query(PII(l - 1, r), i);
    }
    sort(Q, Q + m, compare);
    int l = 0, r = -1;
    for (int i = 0; i < m; i++)
    {
        while (l > Q[i].first.first)
            add(--l);
        while (r < Q[i].first.second)
            add(++r);
        while (l < Q[i].first.first)
            remove(l++);
        while (r > Q[i].first.second)
            remove(r--);
        ans[Q[i].second] = res;
    }
    for (int i = 0; i < m; i++)
        cout << ans[i] << endl;
    return 0;
}
