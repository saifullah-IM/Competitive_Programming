/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

typedef pair<ll, ll> PII;
const ll inf = 1e15;
vector<PII> ara;
ll solve(int pos, ll need)
{
    if (pos == -1)
        return inf;
    ll ans, temp;
    ll u, v;
    u = need / ara[pos].second;
    v = u * ara[pos].first;
    if (u * ara[pos].second == need)
        return v;
    else
        return v + min(ara[pos].first, solve(pos - 1, need - u * ara[pos].second));
}
int main()
{
    int n, L;
    cin >> n >> L;

    ll x;
    cin >> x;
    ara.push_back(PII(x, 1));
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        bool chk = true;
        for (auto k : ara)
        {
            ll v = (1 << i) / k.second;
            ll y = v * k.first;
            if (y <= x)
                chk = false;
        }
        if (chk)
            ara.push_back(PII(x, (1 << i)));
    }
    cout << solve(ara.size() - 1, L) << endl;

    return 0;
}
