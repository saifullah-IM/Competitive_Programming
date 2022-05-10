/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 500005;
int wealth[mx];

int main()
{
    int i, n, k, F, C, mxi, mni, ans1, ans2;
    ll sum = 0;

    mxi = INT_MIN;
    mni = INT_MAX;
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &wealth[i]);
        sum += wealth[i];
        mxi = max(mxi, wealth[i]);
        mni = min(mni, wealth[i]);
    }
    F = floor((sum * 1.0) / (n * 1.0));
    C = ceil((sum * 1.0) / (n * 1.0));
    sort(wealth, wealth + n);

    int hi, lo, mid;
    hi = F;
    lo = ans1 = mni;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        sum = 0;
        for (i = 0; wealth[i] < mid; i++)
            sum += mid - wealth[i];
        if (sum <= k)
        {
            ans1 = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }

    hi = ans2 = mxi;
    lo = C;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        sum = 0;
        for (i = n - 1; wealth[i] > mid; i--)
            sum += wealth[i] - mid;
        if (sum <= k)
        {
            ans2 = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    printf("%d\n", ans2 - ans1);

    return 0;
}
