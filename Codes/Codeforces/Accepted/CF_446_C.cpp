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

const int mx = 3e5 + 5;
const int MOD = 1e9 + 9;
const int K = 2;
struct matrix
{
    ll ara[K][K];
};
inline void matmult(matrix &A, matrix &B, matrix &C)
{
    int i, j, k;
    for (i = 0; i < K; i++)
        for (j = 0; j < K; j++)
        {
            C.ara[i][j] = 0;
            for (k = 0; k < K; k++)
                C.ara[i][j] = (C.ara[i][j] + A.ara[i][k] * B.ara[k][j]) % MOD;
        }
}
matrix matAra[mx];
typedef pair<ll, ll> Pll;
Pll lazy[mx * 4];
ll sum[mx * 4], fib[mx];
int ara[mx];
inline void prep()
{
    matrix M;
    M.ara[0][0] = M.ara[0][1] = M.ara[1][0] = 1;
    M.ara[1][1] = 0;
    matAra[1] = M;
    for (int i = 2; i < mx; i++)
        matmult(matAra[i - 1], M, matAra[i]);
    fib[1] = fib[2] = 1;
    for (int i = 3; i < mx; i++)
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
}
inline ll getFib(int n, ll f1, ll f2)
{
    if (n == 1)
        return f1;
    if (n == 2)
        return f2;
    ll res = matAra[n - 2].ara[0][0] * f2 + matAra[n - 2].ara[0][1] * f1;
    return res % MOD;
}
void build(int pos, int L, int R)
{
    if (L == R)
    {
        sum[pos] = ara[L];
        return;
    }
    int x = pos * 2, mid = (L + R) / 2;
    build(x, L, mid);
    build(x + 1, mid + 1, R);
    sum[pos] = (sum[x] + sum[x + 1]) % MOD;
}
void propagate(int pos, int L, int R)
{
    int x = pos * 2, mid = (L + R) / 2;
    lazy[pos].first %= MOD;
    lazy[pos].second %= MOD;
    lazy[x].first += lazy[pos].first;
    lazy[x].second += lazy[pos].second;
    ll f1 = getFib(mid - L + 2, lazy[pos].first, lazy[pos].second);
    ll f2 = getFib(mid - L + 3, lazy[pos].first, lazy[pos].second);
    lazy[x + 1].first += f1;
    lazy[x + 1].second += f2;
    sum[x] = (sum[x] + f2 - lazy[pos].second) % MOD;
    sum[x + 1] = (sum[x + 1] + getFib(R - mid + 2, f1, f2) - f2) % MOD;
    lazy[pos].first = lazy[pos].second = 0;
}
void update(int pos, int L, int R, int l, int r)
{
    if (L > r || l > R)
        return;
    if (L >= l && R <= r)
    {
        lazy[pos].first += fib[L - l + 1];
        lazy[pos].second += fib[L - l + 2];
        sum[pos] = (sum[pos] + getFib(R - L + 3, fib[L - l + 1], fib[L - l + 2]) - fib[L - l + 2]) % MOD;
        return;
    }
    if (lazy[pos].first != 0)
        propagate(pos, L, R);
    int x = pos * 2, mid = (L + R) / 2;
    if (mid >= l)
        update(x, L, mid, l, r);
    if (mid < r)
        update(x + 1, mid + 1, R, l, r);
    sum[pos] = (sum[x] + sum[x + 1]) % MOD;
}
ll query(int pos, int L, int R, int l, int r)
{
    if (L > r || l > R)
        return 0;
    if (L >= l && R <= r)
        return sum[pos];
    if (lazy[pos].first != 0)
        propagate(pos, L, R);
    int x = pos * 2, mid = (L + R) / 2;
    ll ans = 0;
    if (mid >= l)
        ans += query(x, L, mid, l, r);
    if (mid < r)
        ans += query(x + 1, mid + 1, R, l, r);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    prep();

    int m, n;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> ara[i];
    build(1, 1, n);
    while (m--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
            update(1, 1, n, l, r);
        else
        {
            ll ans = query(1, 1, n, l, r);
            ans = (ans % MOD + MOD) % MOD;
            cout << ans << endl;
        }
    }

    return 0;
}
