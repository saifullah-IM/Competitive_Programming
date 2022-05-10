/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int mx = 1e5 + 5;
ll n, m, k, p, h[mx], h2[mx], a[mx];
bool check(ll x)
{ ///cout<<x<<endl;
    priority_queue<PII, vector<PII>, greater<PII>> myPQ;
    for (int i = 0; i < n; i++)
    {
        h2[i] = x;
        if (h2[i] - m * a[i] >= 0)
            continue;
        myPQ.push(PII(h2[i] / a[i] - 1, i));
    }
    ll cnt = 0;
    while (cnt < m * k && !myPQ.empty())
    {
        PII A = myPQ.top();
        myPQ.pop();
        if (A.first < cnt / k)
            return false;
        int i = A.second;
        h2[i] += p;
        cnt++;
        if (h2[i] - m * a[i] >= 0)
            continue;
        else
            myPQ.push(PII(h2[i] / a[i] - 1, i));
    } ///cout<<cnt<<endl;
    if (cnt > m * k)
        return false;
    for (int i = 0; i < n; i++)
    {
        if (h2[i] - m * a[i] >= h[i])
            continue;
        cnt += ceil(((double)h[i] - (h2[i] - m * a[i])) / p);
        if (cnt > m * k)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> p;
    for (int i = 0; i < n; i++)
        cin >> h[i] >> a[i];
    ll lo = 0, hi = (ll)1 << 56;
    ll ans = 0;
    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << endl;

    return 0;
}
