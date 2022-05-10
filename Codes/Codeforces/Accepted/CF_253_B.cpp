#include <bits/stdc++.h>
#define inf 2000000000
using namespace std;

int n, ara[100005], DP[100005];

int physics_practical(int i)
{
    if (i == n)
        return inf;
    if (DP[i] != -1)
        return DP[i];

    int x, temp, hi, lo, mid;

    x = 2 * ara[i];
    lo = 0;
    hi = n - 1;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (ara[mid] > x)
            hi = mid - 1;
        else
            lo = mid + 1;
    }
    temp = n - lo;

    lo = 0;
    hi = n - 1;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (2 * ara[mid] < x)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    temp += hi - 0 + 1;

    return DP[i] = min(temp, physics_practical(i + 1));
}

int main()
{
    int i, ans;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &ara[i]);
    sort(ara, ara + n);
    memset(DP, -1, sizeof(DP));
    ans = physics_practical(0);
    printf("%d", ans);

    return 0;
}
