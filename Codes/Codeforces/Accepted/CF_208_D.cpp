/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll ans[5], money, m;

int main()
{
    int i, j, n, ara[55], price[5];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &ara[i]);
    for (i = 0; i < 5; i++)
        scanf("%d", &price[i]);
    for (i = 0; i < n; i++)
    {
        money += ara[i];
        for (j = 4; j >= 0; j--)
            if (money >= price[j])
            {
                m = money % price[j];
                ans[j] += (money - m) / price[j];
                money = m;
            }
    }
    for (i = 0; i < 5; i++)
        printf("%lld ", ans[i]);
    printf("\n%lld\n", money);

    return 0;
}
