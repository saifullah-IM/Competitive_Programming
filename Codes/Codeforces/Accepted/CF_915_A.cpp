/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
int main()
{
    int i, n, k, ans, x;
    cin >> n >> k;
    ans = k;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (k % x == 0)
        {
            ans = min(ans, k / x);
        }
    }
    cout << ans << endl;
    return 0;
}