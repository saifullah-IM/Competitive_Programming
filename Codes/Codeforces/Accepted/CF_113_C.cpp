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

const int mx = 3e8 + 5;
const int MOD = 1e9 + 7;
bitset<mx> flag;
void sieve()
{
    int root = sqrt(mx);
    flag[1] = true;
    for (int i = 3; i <= root; i += 2)
        if (!flag[i])
        {
            for (int j = i * i; j < mx; j += i)
                flag[j] = true;
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();
    int l, r;
    cin >> l >> r;
    int ans = 0;
    if (l <= 2 && r >= 2)
        ans++;
    int k = (l / 4) * 4 + 1;
    if (k < l)
        k += 4;
    for (int i = k; i <= r; i += 4)
        if (!flag[i])
            ans++;
    cout << ans << endl;

    return 0;
}
