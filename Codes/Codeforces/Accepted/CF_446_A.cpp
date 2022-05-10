#include <bits/stdc++.h>
#define inf 2000000000
using namespace std;

int n, ara[100005], len1[100005], len2[100005];

int main()
{
    int i, ans;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &ara[i]);
    ara[0] = -inf, ara[0] = inf;
    len1[0] = len2[n + 1] = 0;
    for (i = 1; i <= n; i++)
    {
        if (ara[i] > ara[i - 1])
            len1[i] = 1 + len1[i - 1];
        else
            len1[i] = 1;
    }
    for (i = n; i > 0; i--)
    {
        if (ara[i + 1] > ara[i])
            len2[i] = 1 + len2[i + 1];
        else
            len2[i] = 1;
    }

    ans = 1 + max(len2[2], len1[n - 1]);
    for (i = 2; i < n; i++)
    {
        ans = max(ans, 1 + len1[i - 1]);
        ans = max(ans, 1 + len2[i + 1]);
        if (ara[i - 1] + 1 < ara[i + 1])
            ans = max(ans, len1[i - 1] + 1 + len2[i + 1]);
    }
    printf("%d\n", ans);

    return 0;
}
