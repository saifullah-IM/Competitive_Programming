/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
#define inf 20000000000000000
using namespace std;

long long n, k, p, keys[2005], ppl[1005], DP[1005][2005], chk[2005];

long long office_keys(int i, int j)
{
    if (i == n)
        return 0;
    if (j == k)
        return inf;
    if (DP[i][j] != -1)
        return DP[i][j];

    long long ans, temp;
    temp = fabs(keys[j] - ppl[i]) + fabs(p - keys[j]);
    ans = max(temp, office_keys(i + 1, j + 1));
    ans = min(ans, office_keys(i, j + 1));

    return DP[i][j] = ans;
}

int main()
{
    long long i, ans;

    scanf("%lld %lld %lld", &n, &k, &p);
    for (i = 0; i < n; i++)
        scanf("%lld", &ppl[i]);
    for (i = 0; i < k; i++)
        scanf("%lld", &keys[i]);

    sort(ppl, ppl + n);
    sort(keys, keys + k);
    memset(DP, -1, sizeof(DP));
    ans = office_keys(0, 0);
    cout << ans;

    return 0;
}
