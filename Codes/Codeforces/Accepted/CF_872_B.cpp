/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define inf 2000000000
using namespace std;

int ara[100005], min1[100005], min2[100005];
int main()
{
    int i, n, k, mn, mx, temp;

    mn = inf;
    mx = -inf;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ara[i]);
        mn = min(mn, ara[i]);
        min1[i] = mn;
        mx = max(mx, ara[i]);
    }
    if (k == 1)
        cout << mn << endl;
    else if (k >= 3)
        cout << mx << endl;
    else
    {
        mn = inf;
        for (i = n - 1; i >= 0; i--)
        {
            mn = min(mn, ara[i]);
            min2[i] = mn;
        }
        mx = -inf;
        for (i = 0; i < n - 1; i++)
        {
            temp = max(min1[i], min2[i + 1]);
            mx = max(mx, temp);
        }
        cout << mx << endl;
    }

    return 0;
}
