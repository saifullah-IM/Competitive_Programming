#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k, a, b, x, y, z, ans;

    cin >> k >> a >> b;
    x = a / k;
    y = b / k;
    ans = x + y;

    if (ans == 0)
        cout << -1;
    else
    {
        if (x == 0 && b % k == 0)
            cout << ans;
        else if (y == 0 && a % k == 0)
            cout << ans;
        else if (x != 0 && y != 0)
            cout << ans;
        else
            cout << -1;
    }

    return 0;
}
