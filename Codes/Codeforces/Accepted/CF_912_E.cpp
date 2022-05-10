/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mx = 1e18;
void Generate(vector<int> &p, int i, ll x, vector<ll> &out)
{
    if (i == p.size())
    {
        out.push_back(x);
        return;
    }
    Generate(p, i + 1, x, out);
    for (; x <= mx / p[i];)
        Generate(p, i + 1, x *= p[i], out);
}
ll calc(ll x, vector<ll> &A, vector<ll> &B)
{
    int j = 0;
    ll ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        while (j < B.size() && B[j] <= x / A[i])
            j++;
        ans += j;
    }
    return ans;
}
int main()
{
    int i, x, n;
    vector<int> P, Q;
    vector<ll> A, B;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        if (i % 2)
            P.push_back(x);
        else
            Q.push_back(x);
    }
    Generate(P, 0, 1, A);
    Generate(Q, 0, 1, B);
    sort(A.begin(), A.end(), greater<ll>());
    sort(B.begin(), B.end());
    ll k, lo, hi, mid, ans;
    cin >> k;
    lo = 1, hi = mx;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        ll ans = calc(mid, A, B); ///cout<<ans<<' '<<mid<<endl;
        if (ans < k)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    cout << lo << endl;

    return 0;
}
