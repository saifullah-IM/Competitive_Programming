/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 10e6 + 5;

int cnt[mx];
ll ans[mx];
bool is_cmp[mx];

void solve()
{
    int i, j;

    for (i = 2; i < mx; i += 2)
    {
        ans[2] += cnt[i];
        is_cmp[i] = true;
    }
    for (i = 3; i < mx; i++)
        if (!is_cmp[i])
        {
            for (j = i; j < mx; j += i)
            {
                ans[i] += cnt[j];
                is_cmp[j] = true;
            }
        }
}

int main()
{
    int i, x, n, m, l, r, maxi;
    ll res;

    scanf("%d", &n);
    maxi = -1;

    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        cnt[x]++;
        maxi = max(maxi, x);
    }
    solve();
    for (i = 1; i < mx; i++)
        ans[i] += ans[i - 1];
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &l, &r);
        if (l > maxi)
            res = 0;
        else
        {
            r = min(maxi, r);
            res = ans[r] - ans[l - 1];
        }
        printf("%lld\n", res);
    }
    return 0;
}
