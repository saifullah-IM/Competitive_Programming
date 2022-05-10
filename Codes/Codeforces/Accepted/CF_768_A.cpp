#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n, ara[100000], ans = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &ara[i]);

    sort(ara, ara + n);
    for (i = 0; i < n; i++)
    {
        if (ara[i] == ara[0])
            ans++;
        else
            break;
    }
    for (j = n - 1; j >= i; j--)
    {
        if (ara[j] == ara[n - 1])
            ans++;
        else
            break;
    }

    ans = n - ans;
    cout << ans;

    return 0;
}
