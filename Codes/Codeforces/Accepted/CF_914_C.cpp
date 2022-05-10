/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;
const int mx = 1005;
int dp[mx];
int count(int m)
{
    if (m == 1)
        return 0;
    if (dp[m] != -1)
        return dp[m];
    int n = m, res = 0;
    while (n > 0)
    {
        res += n % 2;
        n /= 2;
    }
    dp[m] = 1 + count(res);
    return dp[m];
}
int n, k;
char str[mx];
ll DP[mx][mx][2];
ll solve(int pos, int n1, bool flag)
{
    if (pos == n)
    { ///cout<<n<<endl;
        if (n1 == 0)
            return 0;
        if (count(n1) == k - 1)
            return 1;
        else
            return 0;
    }
    if (DP[pos][n1][flag] != -1)
        return DP[pos][n1][flag];
    ll ans = 0;
    if (flag)
    { ///cout<<pos<<endl;
        ans += solve(pos + 1, n1 + 1, true);
        ans += solve(pos + 1, n1, true);
    }
    else
    {
        if (str[pos] == '1')
        {
            ans += solve(pos + 1, n1, true);
            ans += solve(pos + 1, n1 + 1, false);
        }
        else
            ans += solve(pos + 1, n1, false);
    } ///cout<<pos<<' '<<n1<<' '<<flag<<' '<<ans<<endl;
    return DP[pos][n1][flag] = ans % MOD;
}
int main()
{
    memset(dp, -1, sizeof(dp));
    memset(DP, -1, sizeof(DP));
    scanf("%s", str);
    scanf("%d", &k);
    n = strlen(str);
    if (k == 0)
        cout << 1 << endl;
    else if (k == 1)
        cout << n - 1 << endl;
    else
    {
        ll ans = solve(0, 0, false);
        cout << ans << endl;
    }

    return 0;
}
