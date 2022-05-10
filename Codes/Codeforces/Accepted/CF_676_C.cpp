#include <bits/stdc++.h>
using namespace std;

char str[100005];
int n, k, araA[100005], araB[100005], DP[100005];

int vasys_string(int i)
{
    if (DP[i] != 0)
        return DP[i];

    int x, y, z, ans, hi, lo, mid;
    if (str[i] == 'a')
    {
        x = araB[i] + k;
        lo = 1, hi = n;
        while (lo <= hi)
        {
            mid = (hi + lo) / 2;
            if (araB[mid] > x)
                hi = mid - 1;
            else
                lo = mid + 1;
        } //cout<<lo<<' '<<i<<endl;
        ans = lo - i;

        x = araA[i] + k - 1;
        lo = 1, hi = n;
        while (lo <= hi)
        {
            mid = (hi + lo) / 2;
            if (araA[mid] > x)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        ans = max(ans, lo - i);

        if (ans != n - i + 1)
            ans = max(ans, vasys_string(i + 1));
    }
    else
    {
        x = araA[i] + k;
        lo = 1, hi = n;
        while (lo <= hi)
        {
            mid = (hi + lo) / 2;
            if (araA[mid] > x)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        ans = lo - i;

        x = araB[i] + k - 1;
        lo = 1, hi = n;
        while (lo <= hi)
        {
            mid = (hi + lo) / 2;
            if (araB[mid] > x)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        ans = max(ans, lo - i);

        if (ans != n - i + 1)
            ans = max(ans, vasys_string(i + 1));
    }

    return DP[i] = ans;
}

int main()
{
    int i, m, ans, A, B;

    scanf("%d %d", &n, &k);
    scanf("%*c");
    araA[0] = araB[0] = 0;
    araA[n + 1] = araB[n + 1] = 1000000;
    for (i = 1; i <= n; i++)
    {
        scanf("%c", &str[i]);
        if (str[i] == 'a')
        {
            araA[i] = 1 + araA[i - 1];
            araB[i] = araB[i - 1];
        }
        else
        {
            araA[i] = araA[i - 1];
            araB[i] = 1 + araB[i - 1];
        }
    } //cout<<str[1]<<'x';

    ans = vasys_string(1);
    printf("%d\n", ans);

    return 0;
}
