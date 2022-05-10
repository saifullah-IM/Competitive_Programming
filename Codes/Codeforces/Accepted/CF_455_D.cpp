/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define mp make_pair
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define abs(X) ((X) > 0 ? (X) : (-(X)))
#define loop(i, a, b) for (int i = a; i < b; i++)
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
const int MOD = 1e9 + 7;
const int k = 320;
deque<int> block[k];
int cnt[k][mx];
void update(int l, int r)
{
    int b1 = l / k;
    int b2 = r / k;
    int p1 = l - b1 * k;
    int p2 = r - b2 * k;
    int x = block[b2][p2];
    block[b1].emplace(block[b1].begin() + p1, x);
    if (b1 == b2)
    {
        block[b2].erase(block[b2].begin() + p2 + 1);
        return;
    }
    block[b2].erase(block[b2].begin() + p2);
    cnt[b1][x]++;
    cnt[b2][x]--;
    loop(i, b1, b2)
    {
        int x = block[i].back();
        block[i].pop_back();
        block[i + 1].push_front(x);
        cnt[i][x]--;
        cnt[i + 1][x]++;
    }
}
int solve(int l, int r, int x)
{
    int b1 = l / k;
    int b2 = r / k;
    int p1 = l - b1 * k;
    int p2 = r - b2 * k;
    int p3 = r - b1 * k;
    int ans = 0;
    loop(i, p1, min(p3 + 1, k))
    {
        if (block[b1][i] == x)
            ans++;
    }
    if (b1 == b2)
        return ans;
    loop(i, 0, p2 + 1)
    {
        if (block[b2][i] == x)
            ans++;
    }
    loop(i, b1 + 1, b2) ans += cnt[i][x];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n, z;
    cin >> n;
    loop(i, 0, n)
    {
        cin >> z;
        int pos = i / k;
        cnt[pos][z]++;
        block[pos].push_back(z);
    }
    cin >> m;
    int ans = 0;
    loop(i, 0, m)
    {
        int l, r, x, y;
        cin >> y;
        if (y == 1)
        {
            cin >> l >> r;
            l = (l + ans - 1) % n;
            r = (r + ans - 1) % n;
            if (l > r)
                swap(l, r);
            update(l, r);
        }
        else
        {
            cin >> l >> r >> x;
            l = (l + ans - 1) % n;
            r = (r + ans - 1) % n;
            x = (x + ans - 1) % n + 1;
            if (l > r)
                swap(l, r);
            ans = solve(l, r, x);
            cout << ans << endl;
        }
    }

    return 0;
}
