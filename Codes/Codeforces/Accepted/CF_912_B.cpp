/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, k;
    cin >> n >> k;

    if (k >= 2)
    {
        ll ans = 1;
        while (n > 0)
        {
            n /= 2;
            ans *= 2;
        }
        cout << ans - 1 << endl;
    }
    else
    {
        cout << n << endl;
    }

    return 0;
}
