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
char grid[mx][12];
bool vis[mx][12];
PII dest[mx][12];
PII dfs(int i, int j, int k, int n, int m)
{
    if (i < k || j < 1 || i > n || j > m)
        return mp(i, j);
    if (vis[i][j])
        return dest[i][j];
    vis[i][j] = true;
    PII A;
    if (grid[i][j] == '^')
        A = dfs(i - 1, j, k, n, m);
    else if (grid[i][j] == '<')
        A = dfs(i, j - 1, k, n, m);
    else
        A = dfs(i, j + 1, k, n, m);
    if (A.first == i && A.second == j)
        A = PII(-1, -1);
    return dest[i][j] = A;
}
void build(int n, int m)
{
    for (int i = 1; i <= n; i++)
    {
        int k = (i - 1) / block;
        for (int j = 1; j <= m; j++)
            if (!vis[i][j])
                dfs(i, j, k * block + 1, min(k * block + block, n), m);
    }
}
void update(int x, int y, char ch, int n, int m)
{
    grid[x][y] = ch;
    int k = (x - 1) / block;
    int p = k * block + 1, q = min(k * block + block, n);
    for (int i = p; i <= q; i++)
        for (int j = 1; j <= m; j++)
        {
            vis[i][j] = false;
            dest[i][j] = PII(-1, -1);
        }
    for (int i = p; i <= q; i++)
    {
        for (int j = 1; j <= m; j++)
            if (!vis[i][j])
                dfs(i, j, p, q, m);
    }
}
PII query(int x, int y, int n, int m)
{
    set<PII> myset;
    PII A = mp(x, y);
    while (true)
    {
        if (A.first < 1 || A.second < 1 || A.first > n || A.second > m)
            break;
        if (myset.find(A) != myset.end())
        {
            A = mp(-1, -1);
            break;
        }
        myset.insert(A);
        A = dest[A.first][A.second];
        if (A.first == x && A.second == y)
        {
            A = mp(-1, -1);
            break;
        }
    }
    return A;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> grid[i][j];
    }
    memset(dest, -1, sizeof(dest));
    build(n, m);
    while (q--)
    {
        char ch, c;
        int x, y;
        cin >> ch >> x >> y;
        if (ch == 'C')
        {
            cin >> c;
            update(x, y, c, n, m);
        }
        else
        {
            PII A = query(x, y, n, m);
            cout << A.first << ' ' << A.second << endl;
        }
    }

    return 0;
}
