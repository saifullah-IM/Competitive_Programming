/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define inf 1000
using namespace std;

int cnt[305], ara[20005], len1[105], len2[105], aux[20005];

int LIS(int n, int T)
{
    int i, m, hi, lo, mid, lislen = 0;

    if (T <= 2 * n)
        m = T * n;
    else
        m = n * n;

    aux[0] = -inf;
    for (i = 1; i <= m; i++)
        aux[i] = inf;
    for (i = 0; i < m; i++)
    {
        lo = 0;
        hi = lislen;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (ara[i] >= aux[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        aux[lo] = ara[i];
        lislen = max(lislen, lo);
        if ((i / n) == n - 1)
            len1[i % n] = lo;
    }
    if (m == T * n)
        return lislen;

    aux[0] = inf;
    for (i = 1; i <= m; i++)
        aux[i] = -inf;
    for (i = m - 1; i >= 0; i--)
    {
        lo = 0;
        hi = lislen;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (ara[i] <= aux[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        aux[lo] = ara[i];
        lislen = max(lislen, lo);
        if ((i / n) == 0)
            len2[i % n] = lo;
    }

    int j, temp, ans = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            if (ara[j] == ara[i])
                break;
        temp = len1[i] + (T - 2 * n) * cnt[ara[i]] + len2[j];
        ans = max(ans, temp);
    }
    return ans;
}

int main()
{
    int i, j, k, n, T;

    scanf("%d %d", &n, &T);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ara[i]);
        cnt[ara[i]]++;
    }
    k = n;
    for (i = 1; (i < 2 * n) && i < T; i++)
    {
        for (j = 0; j < n; j++)
            ara[k++] = ara[j];
    }
    printf("%d\n", LIS(n, T));

    return 0;
}
