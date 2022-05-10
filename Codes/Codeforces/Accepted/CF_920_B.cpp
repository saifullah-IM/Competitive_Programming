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
int ans[1005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int m, n, t;
    cin >> t;
    while (t--)
    {
        memset(ans, 0, sizeof(ans));
        cin >> n;
        ///cout<<n<<endl;
        int l, r;
        int sum = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> l >> r;
            int temp = max(sum, l);
            if (temp > r)
                continue;
            ans[i] = temp;
            sum = temp + 1;
        }
        ///cout<<n<<endl;
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
        cout << endl;
    }

    return 0;
}
