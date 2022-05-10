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
vector<int> sets[mx], inHeavy[mx], heavy;
int intersection[mx][block + 5];
ll ara[mx], sum[mx], lazy[mx];
int isHeavy[mx];
void build(int m)
{
    for (int i = 1; i <= m; i++)
    {
        for (int u : sets[i])
        {
            for (int j : inHeavy[u])
                if (i != j)
                    intersection[i][isHeavy[j]]++;
        }
    }
}
void update(int x, int y)
{
    if (!isHeavy[x])
    {
        for (int u : sets[x])
            ara[u] += y;
        for (int u : heavy)
        {
            sum[u] += (ll)y * intersection[x][isHeavy[u]];
        }
    }
    else
    {
        lazy[x] += y;
        sum[x] += (ll)y * sets[x].size();
        for (int u : heavy)
        {
            if (x == u)
                continue;
            sum[u] += (ll)y * intersection[x][isHeavy[u]];
        }
    }
}
ll query(int x)
{
    ll ans = 0;
    if (!isHeavy[x])
    {
        for (int i : sets[x])
            ans += ara[i];
        for (int u : heavy)
        {
            ans += lazy[u] * intersection[x][isHeavy[u]];
        }
    }
    else
        ans = sum[x];
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        cin >> ara[i];
    for (int i = 1; i <= m; i++)
    {
        int x, k;
        cin >> k;
        if (k >= block)
        {
            heavy.push_back(i);
            isHeavy[i] = heavy.size();
        }
        for (int j = 0; j < k; j++)
        {
            cin >> x;
            sets[i].push_back(x);
            if (k >= block)
            {
                inHeavy[x].push_back(i);
                sum[i] += ara[x];
            }
        }
    }
    build(m);
    while (q--)
    {
        int x, y;
        char ch;
        cin >> ch >> x;
        if (ch == '+')
        {
            cin >> y;
            update(x, y);
        }
        else
            cout << query(x) << endl;
    }

    return 0;
}
