#include <bits/stdc++.h>
using namespace std; /*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;*/

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define PI (acos(-1.0))
#define inf (1 << 30)
#define infll (1LL << 62)
#define abs(X) ((X) > 0 ? (X) : (-(X)))
#define fbo(k) find_by_order(k)    ///returns iterator to the kth largest element counting from 0
#define ook(val) order_of_key(val) ///returns the number of items in a set that are strictly smaller than val

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef multiset<int>::iterator mit;
typedef map<int, int> mii;
typedef map<int, int>::iterator miit;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vi> digit_matrix(10, vi(10, -1));

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            digit_matrix[i][j] = (i * j) % 10;

    int n, d;
    cin >> n >> d;

    vector<vector<double>> dp(n, vector<double>(10, 0.0));
    vector<vector<pii>> path(n, vector<pii>(10, mp(-1, -1)));
    vi ara(n);

    for (int i = 0; i < n; i++)
        cin >> ara[i];

    dp[0][ara[0] % 10] = log(ara[0]);
    path[0][ara[0] % 10] = mp(0, -1);

    //cout << "ok\n";

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int next_digit = (j * ara[i]) % 10;
            double temp = dp[i - 1][j] + log(ara[i]);
            if ((path[i - 1][j].fi != -1 || j == 1) && temp > max(dp[i][next_digit], dp[i - 1][next_digit]))
            {
                dp[i][next_digit] = temp;
                path[i][next_digit] = mp(i, j);
                //cout << j << ' ' << next_digit << ' ' << path[i][next_digit].fi << '\n';
            }
        }
        for (int j = 0; j < 10; j++)
        {
            if (path[i][j].fi == -1)
            {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = path[i - 1][j];
            }
            //cout << i << ' ' << j << ' ' << path[i][j].fi << '\n';
        }

        //cout << "\n\n";
    }

    //cout << "dp\n";

    vi ans;
    int u = n - 1;
    while (u != -1)
    {
        int v = path[u][d].fi;
        //cout << u << ' ' << v << ' ' << d << "\n";
        if (u == v)
        {
            ans.pb(ara[v]);
            d = path[u][d].se;
            u -= 1;
            //cout << d << '\n';
            // if (d == -1)
            //     return 0;
        }
        else
            u = v;
    }

    if (ans.empty())
        cout << "-1\n";
    else
    {
        cout << ans.size() << endl;
        for (auto it : ans)
            cout << it << ' ';
        cout << endl;
    }

    return 0;
}