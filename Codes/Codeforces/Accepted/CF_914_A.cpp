/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
int ara[1005];
int main()
{
    int i, n;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> ara[i];
    int ans = INT_MIN;
    for (i = 0; i < n; i++)
    {
        if (ara[i] < 0)
            ans = max(ans, ara[i]);
        else
        {
            int m = sqrt(ara[i]);
            if (m * m != ara[i])
                ans = max(ans, ara[i]);
        }
    }
    cout << ans << endl;

    return 0;
}
