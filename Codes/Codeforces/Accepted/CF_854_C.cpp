/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
#define PII pair<ll, ll>
using namespace std;

PII ara[300005];
bool chk[600005];
ll TM[300005];

bool srtfnc(PII A, PII B)
{
    if (A.first == B.first)
        return A.second < B.second;
    return A.first > B.first;
}

int main()
{
    ll i, j, n, k, ans;

    scanf("%lld %lld", &n, &k);
    for (i = 1; i <= n; i++)
    {
        scanf("%lld", &ara[i].first);
        ara[i].second = i;
    }
    sort(ara + 1, ara + n + 1, srtfnc);
    ans = 0;

    for (i = j = k + 1; i <= k + n; i++, j++)
    {
        while (chk[j])
        {
            j++;
        }
        if (ara[i - k].second > j)
        {
            chk[ara[i - k].second] = true;
            TM[ara[i - k].second] = ara[i - k].second;
            j--;
        }
        else
        {
            TM[ara[i - k].second] = j;
            ans += ara[i - k].first * (j - ara[i - k].second);
        }
    }

    cout << ans << endl;
    for (i = 1; i <= n; i++)
        printf("%lld ", TM[i]);

    return 0;
}
