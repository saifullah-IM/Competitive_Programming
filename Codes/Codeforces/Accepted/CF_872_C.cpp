/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, q, ans;

    scanf("%d", &q);
    while (q--)
    {
        scanf("%d", &n);
        if (n < 4)
            ans = -1;
        else if (n % 4 == 0)
            ans = n / 4;
        else if (n % 4 == 2)
            ans = n / 4;
        else if (n % 4 == 1)
        {
            if (n > 5)
                ans = (n / 4) - 1;
            else
                ans = -1;
        }
        else
        {
            if (n > 11)
                ans = (n / 4) - 1;
            else
                ans = -1;
        }
        printf("%d\n", ans);
    }

    return 0;
}
