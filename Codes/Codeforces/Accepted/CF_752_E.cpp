/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1000005;
int n, m, k, ara[mx], DP[10 * mx];

void prep(int x)
{
    for (int i = x; i <= ara[n - 1]; i++)
    {
        int half = i / 2;
        if (half < x)
            DP[i] = 1;
        else
            DP[i] = DP[half] + DP[i - half];
    }
}

bool check(int x)
{
    prep(x);
    long long sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (ara[i] < x)
            break;
        sum += DP[ara[i]];
    }
    return sum >= k;
}

int main()
{
    int i, hi, lo, mid, ans;
    long long sum = 0;

    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ara[i]);
        sum += ara[i];
    }
    if (sum < k)
    {
        printf("-1\n");
        return 0;
    }

    lo = 1;
    sort(ara, ara + n);
    hi = ara[n - 1];
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    printf("%d\n", ans);

    return 0;
}
