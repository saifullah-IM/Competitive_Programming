/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define infll (1LL << 62)
#define abs(X) ((X) > 0 ? (X) : (-(X)))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 1e6 + 5;
const int MOD = 1e9 + 7;
bitset<mx> flag;
vi divs[mx];
void sieve()
{
    for (int i = 2; i < mx; i += 2)
        divs[i].pb(2);
    for (int i = 3; i < mx; i += 2)
        if (!flag[i])
        {
            for (int j = i; j < mx; j += i)
            {
                flag[j] = true;
                divs[j].pb(i);
            }
        }
}
ll solve(int p, ll x)
{
    ll ans = 0;
    int mask = (1 << divs[p].size()) - 1; ///cout<<"init  "<<p<<' '<<mask<<endl;
    for (int i = 0; i <= mask; i++)
    {
        int m = i, cnt = 0, num = 1, j = 0;
        while (m > 0)
        {
            cnt += (m & 1);
            if (m & 1)
                num *= divs[p][j];
            m >>= 1;
            j++;
        } ///cout<<i<<' '<<cnt<<' '<<num<<"   haaaaa"<<endl;
        int sign = 1;
        if (cnt % 2)
            sign = -1;
        ans += sign * (x / num);
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();
    int T;
    cin >> T;
    while (T--)
    {
        int x, p, k;
        cin >> x >> p >> k;
        ll z = solve(p, x);
        ll lo = 1, hi = infll, mid, ans = 0;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            ll temp = solve(p, mid);
            if (temp - z >= k)
            {
                if (temp - z == k)
                    ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        cout << ans << endl;
    }

    return 0;
}
