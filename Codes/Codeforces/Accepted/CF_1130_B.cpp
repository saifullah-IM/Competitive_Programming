#include <bits/stdc++.h>
using namespace std;

#define abs(x) ((x) > 0 ? (x) : -(x))

const int mx = 1e5 + 5;
vector<int> ara[mx];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 2 * n; i++)
    {
        int x;
        cin >> x;
        ara[x].push_back(i);
    }
    long long ans = 0;
    ara[0].push_back(0);
    ara[0].push_back(0);
    for (int i = 1; i <= n; i++)
    {
        int val1 = abs(ara[i - 1][0] - ara[i][0]) + abs(ara[i - 1][1] - ara[i][1]);
        int val2 = abs(ara[i - 1][1] - ara[i][0]) + abs(ara[i - 1][0] - ara[i][1]);
        ///cout<<val1<<' '<<val2<<endl;
        ans += min(val1, val2);
    }
    cout << ans << endl;

    return 0;
}
