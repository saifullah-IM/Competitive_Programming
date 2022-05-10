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
typedef vector<ll> vl;
typedef set<int> si;
typedef multiset<int> msi;
typedef map<int, int> mii;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int maxn = 1e6 + 5;
const int MOD = 1e9 + 7;

int X0[maxn];
bool flag[maxn];
vi primes[maxn], num;
void sieve(int n)
{
    for (int i = 2; i <= n; i++)
    {
        num.pb(i);
        if (!flag[i])
        {
            for (int j = i + i; j <= n; j += i)
            {
                primes[j].pb(i);
                flag[j] = true;
            }
        }
        else
        {
            for (int j = primes[i].size() - 1; j >= 0; j--)
            {
                int p = primes[i][j];
                int x1 = i - p;
                auto it = upper_bound(num.begin(), num.end(), x1);
                if (it != num.end())
                {
                    X0[i] = *it;
                    break;
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    sieve(n);
    int ans = n + n;
    for (int p : primes[n])
    {
        int x1 = n - p + 1;
        for (int i = x1; i <= n; i++)
        {
            if (!flag[i])
                continue;
            ans = min(ans, X0[i]);
        }
    }
    assert(ans > 1);
    cout << ans << endl;

    return 0;
}
