/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std; /*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
using namespace __gnu_cxx;*/

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define infll (1LL << 62)
#define abs(X) ((X) > 0 ? (X) : (-(X)))
#define fbo(k) find_by_order(k)    ///returns iterator to the kth largest element counting from 0
#define ook(val) order_of_key(val) ///returns the number of items in a set that are strictly smaller than val

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 4e5 + 5;
const int MOD = 1e9 + 7;
ll cnt[mx], sum[mx];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string str;
    int n, m;
    cin >> n >> str;
    m = str.size();
    for (int i = 1; i <= m; i++)
        sum[i] += sum[i - 1] + (str[i - 1] - '0');
    for (int i = 1; i <= m; i++)
    {
        for (int j = i; j <= m; j++)
        {
            int x = sum[j] - sum[i - 1];
            cnt[x]++;
        }
    }
    ll ans = 0;
    if (n == 0)
    {
        for (int i = 0; i < mx; i++)
            ans += 2 * cnt[0] * cnt[i];
        ans -= cnt[0] * cnt[0];
    }
    else
    {
        for (int i = 1; i * i <= n; i++)
        {
            if (n % i)
                continue;
            int x = n / i;
            if (x < mx)
            {
                ll y = cnt[i] * cnt[x];
                ans += y * 2;
                if (i * i == n)
                    ans -= y;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
