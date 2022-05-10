/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
using namespace std;

char str[100005];
int main()
{
    int i, n, k, m, ans;

    scanf("%d", &k);
    scanf("%s", str);
    n = strlen(str);
    sort(str, str + n);
    ans = m = 0;
    for (i = 0; i < n; i++)
        m += (str[i] - '0');

    if (m >= k)
        cout << 0;
    else
    {
        for (i = 0; i < n; i++)
        {
            ans++;
            m += ('9' - str[i]);
            if (m >= k)
                break;
        }
        cout << ans;
    }

    return 0;
}
