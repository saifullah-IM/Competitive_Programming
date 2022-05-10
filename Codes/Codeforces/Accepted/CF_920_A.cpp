/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define mp make_pair
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define abs(X) ((X) > 0 ? (X) : (-(X)))
using namespace std;

///cout << fixed << setprecision(12) << p << endl;

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VP;

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;
int ara[mx];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n, t;

    cin >> t;
    while (t--)
    {
        cin >> m >> n;
        bool chk[500];
        vector<int> tap;
        tap.clear();
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            tap.push_back(x);
        }
        int ans;
        for (ans = 0; ans < m; ans++)
        {
            memset(chk, 0, sizeof(chk));
            for (int u : tap)
            {
                for (int i = 0; i <= ans; i++)
                {
                    if (u - i > 0)
                        chk[u - i] = true;
                    if (u + i <= m)
                        chk[u + i] = true;
                }
            }
            int cnt = 0;
            for (int i = 1; i <= m; i++)
                if (chk[i])
                    cnt++;
            if (cnt == m)
            {
                cout << ans + 1 << endl;
                break;
            }
        }
    }

    return 0;
}
