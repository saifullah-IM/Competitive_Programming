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

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;

int ara[mx];
vi primeDivisors[2 * mx];
bool isPrime[2 * mx];

void sieve()
{
    memset(isPrime, 1, sizeof(isPrime));
    for (int i = 2; i < 2 * mx; i += 2)
        primeDivisors[i].pb(2);
    for (int i = 3; i < 2 * mx; i += 2)
    {
        if (!isPrime[i])
            continue;
        for (int j = i; j < 2 * mx; j += i)
        {
            isPrime[j] = false;
            primeDivisors[j].pb(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ara[i];

    if (n == 1)
    {
        cout << ara[0] << endl;
        return 0;
    }

    si primes;
    for (auto it : primeDivisors[ara[0]])
        primes.insert(it);
    for (auto it : primeDivisors[ara[1]])
        primes.insert(it);

    ll ans = 1;
    for (auto it : primes)
    {
        int prime = it;
        int firstMin = inf;
        int secondMin = inf;

        for (int i = 0; i < n; i++)
        {
            int exp = 0;
            while (ara[i] % prime == 0)
            {
                exp++;
                ara[i] /= prime;
            }
            if (exp < firstMin)
            {
                secondMin = firstMin;
                firstMin = exp;
            }
            else if (exp < secondMin)
                secondMin = exp;
            if (secondMin == 0)
                break;
        }

        while (secondMin--)
            ans *= prime;
    }

    cout << ans << endl;

    return 0;
}