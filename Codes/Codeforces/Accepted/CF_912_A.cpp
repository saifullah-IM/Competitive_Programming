/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll a, b;
    ll x, y, z;
    cin >> a >> b;
    cin >> x >> y >> z;

    ll ans, temp;
    ans = 2 * x + y - a;
    if (ans < 0)
        ans = 0;
    temp = y + 3 * z - b;
    if (temp < 0)
        temp = 0;
    cout << ans + temp << endl;

    return 0;
}
