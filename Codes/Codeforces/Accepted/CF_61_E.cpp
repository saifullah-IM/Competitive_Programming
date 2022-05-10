/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define mp make_pair
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define abs(X) ((X) > 0 ? (X) : (-(X)))
using namespace std;

///cout << fixed << setprecision(12) << p << endl;

typedef long long ll;
typedef pair<int, int> PII;

const int mx = 1e6 + 5;
const int MOD = 1e9 + 7;
int cnt[2][mx];
PII ara[mx], temp[mx];
void inversion_count(int lo, int hi)
{
    if (lo == hi)
        return;
    int mid = (lo + hi) / 2;
    inversion_count(lo, mid);
    inversion_count(mid + 1, hi);

    int i, j, k, num[mid - lo + 3], inv = 0;
    memset(num, 0, sizeof(num));
    for (i = lo, j = mid + 1, k = lo; k <= hi; k++)
    {
        if (i == mid + 1)
            temp[k] = ara[j++];
        else if (j == hi + 1)
            temp[k] = ara[i++];
        else if (ara[i].first <= ara[j].first)
            temp[k] = ara[i++];
        else
        {
            inv++;
            num[i - lo]++;
            cnt[0][ara[j].second] += mid - i + 1;
            temp[k] = ara[j++];
        }
    }
    for (int i = mid; i >= lo; i--)
    {
        cnt[1][ara[i].second] += inv;
        inv -= num[i - lo];
    }
    for (int i = lo; i <= hi; i++)
        ara[i] = temp[i];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ara[i].first;
        ara[i].second = i;
    }
    inversion_count(0, n - 1);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += (ll)cnt[0][i] * cnt[1][i];
    cout << ans << endl;

    return 0;
}
