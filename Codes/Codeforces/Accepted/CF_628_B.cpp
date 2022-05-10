#include <bits/stdc++.h>
using namespace std;

char str[300010];
int main()
{
    int i, n, x;
    long long ans;

    scanf("%s", str);
    n = strlen(str);
    ans = 0;
    for (i = n - 1; i > 0; i--)
    {
        x = str[i] - '0';
        if (x % 4 == 0)
            ans++;
        x += (str[i - 1] - '0') * 10;
        if (x % 4 == 0)
            ans += i;
    }
    x = str[0] - '0';
    if (x % 4 == 0)
        ans++;
    printf("%lld", ans);

    return 0;
}
