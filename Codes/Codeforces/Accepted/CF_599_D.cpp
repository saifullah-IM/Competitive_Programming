/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
#define PII pair<ll, ll>
using namespace std;

const int mx = 2e6 + 6;
vector<PII> ans;

int main()
{
    ll x;

    scanf("%lld", &x);
    for (ll n = 1; n < mx; n++)
    { //cout<<"n"<<n<<endl;
        if ((6 * x) % n)
            continue;
        ll y = (6 * x) / n - (n - 1) * (2 * n - 1);
        if (y % 3)
            continue;
        ll z = y / 3 + n * n - n;
        if (z % (n + 1))
            continue;
        ll m = z / (n + 1);
        if (m < n)
            break;
        ans.push_back(make_pair(m, n));
        if (m != n)
            ans.push_back(make_pair(n, m));
    }

    sort(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (auto it = ans.begin(); it != ans.end(); it++)
    {
        printf("%lld %lld\n", it->first, it->second);
    }

    return 0;
}
