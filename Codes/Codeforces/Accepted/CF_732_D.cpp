/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 100005;
int ara[mx], exam[mx], days[mx];

bool check(int n, int m)
{
    bool done[mx];
    memset(done, 0, sizeof(done));

    int i, k = 0, pday = 0;
    for (i = ara[n]; i > 0; i--)
    {
        if (!exam[i])
            pday--;
        else if (!done[exam[i]])
        {
            done[exam[i]] = true;
            pday += days[exam[i]];
            k++;
        }
        else
            pday--;
        if (pday < 0)
            pday = 0;
    }

    if (k == m && pday == 0)
        return true;
    else
        return false;
}

int main()
{
    int i, k, n, m;

    k = 0;
    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &exam[i]);
        if (exam[i])
            ara[k++] = i;
    }
    for (i = 1; i <= m; i++)
        scanf("%d", &days[i]);

    int hi, lo, mid, ans;

    lo = 0;
    hi = k - 1;
    ans = -1;
    while (lo <= hi)
    {
        mid = (hi + lo) / 2;
        if (check(mid, m))
        {
            ans = ara[mid];
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    printf("%d\n", ans);

    return 0;
}
