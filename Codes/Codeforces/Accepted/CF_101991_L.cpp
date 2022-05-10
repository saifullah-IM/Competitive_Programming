#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("looking.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, ans = 0;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
        {
            int y;
            cin >> y;
            int mask = 1;
            for (int j = 0; j < 21; j++)
            {
                int x = (mask & y);
                if (x)
                    ans = (ans | mask);
                mask = (mask << 1);
            }
        }
        cout << ans << endl;
    }

    return 0;
}
