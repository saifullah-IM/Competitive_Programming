/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

int ara[1005], day[1005];
int main()
{
    int i, n, k, temp, ans = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d %d", &ara[i], &day[i]);
    for (i = 0; i < n; i++)
    {
        if (ans < ara[i])
            ans = ara[i];
        else
        {
            k = ans - ara[i];
            k = ceil((k * 1.0) / (day[i] * 1.0));
            temp = ara[i] + k * day[i];
            if (temp > ans)
                ans = temp;
            else
                ans = temp + day[i];
        }
    }
    printf("%d\n", ans);

    return 0;
}
