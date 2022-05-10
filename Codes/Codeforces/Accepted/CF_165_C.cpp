#include <bits/stdc++.h>
using namespace std;

int ara1[1000006], ara2[1000006];
char str[1000006];
int main()
{
    int i, n, k, u;
    long long ans;
    char ch;

    scanf("%d", &k);
    scanf(" %[01]", str);

    n = strlen(str);
    ara1[0] = str[0] - '0';
    ara2[ara1[0]]++;
    for (i = 1; i < n; i++)
    {
        if (str[i] == '1')
            ara1[i] = 1 + ara1[i - 1];
        else
            ara1[i] = ara1[i - 1];
        ara2[ara1[i]]++;
    }

    ans = u = 0;
    for (i = 0; i < n; i++)
    {
        if (k != 0)
        {
            if (str[i] == '1' && ara1[i] + k - 1 <= n)
                ans += ara2[ara1[i] + k - 1];
            else if (str[i] == '0' && ara1[i] + k <= n)
                ans += ara2[ara1[i] + k];
        }
        else
        {
            if (str[i] == '0')
                u++;
            else
                u = 0;
            ans += u;
        }
    }

    printf("%lld", ans);

    return 0;
}
