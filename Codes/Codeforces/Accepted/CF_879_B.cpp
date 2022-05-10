/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ara[505];
int main()
{
    ll i, n, k, ans, cnt, p;

    scanf("%lld %lld", &n, &k);
    for (i = 0; i < n; i++)
        scanf("%lld", &ara[i]);

    if (k >= n - 1)
        printf("%lld\n", n);
    else
    {
        queue<ll> myQ;
        ans = max(ara[0], ara[1]);
        for (i = 2; i < n; i++)
            myQ.push(ara[i]);
        myQ.push(min(ara[0], ara[1]));
        cnt = 1;
        while (cnt != k)
        {
            p = myQ.front();
            myQ.pop();
            if (p > ans)
            {
                myQ.push(ans);
                ans = p;
                cnt = 1;
            }
            else
            {
                cnt++;
                myQ.push(p);
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}
