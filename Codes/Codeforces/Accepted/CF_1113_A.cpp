#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, v;
    cin >> n >> v;
    int fuel = 0;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (fuel < v && fuel < n - i)
        {
            ans += min(n - i, v - fuel) * i;
            fuel += min(n - i, v - fuel);
        }
        fuel--;
    }
    cout << ans << endl;

    return 0;
}