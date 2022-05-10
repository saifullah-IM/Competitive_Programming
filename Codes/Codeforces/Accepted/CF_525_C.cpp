/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 1e5 + 5;
int n, ara[mx];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ara[i];
    sort(ara, ara + n);
    ll ans = 0, len = 0;
    int i = n - 1;
    while (i >= 0)
    {
        if (ara[i] == ara[i - 1] || ara[i] - 1 == ara[i - 1])
        {
            if (len == 0)
                len = ara[i - 1];
            else
            {
                ans += len * ara[i - 1];
                len = 0;
            }
            i -= 2;
            continue;
        }
        i--;
    }
    cout << ans << endl;

    return 0;
}