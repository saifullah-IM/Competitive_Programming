#include <bits/stdc++.h>
using namespace std;/*
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
#define inf (1<<30)
#define infll (1LL<<62)
#define abs(X) ( (X) > 0 ? (X) : ( -(X) ) )
#define fbo(k) find_by_order(k) ///returns iterator to the kth largest element counting from 0
#define ook(val) order_of_key(val) ///returns the number of items in a set that are strictly smaller than val

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <int> vi;
typedef set <int> si;
typedef multiset <int> msi;
typedef multiset <int>::iterator mit;
typedef map <int, int> mii;
typedef map <int, int>::iterator miit;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 2e7 + 5;
const int MOD = 1e9 + 7;

int prime_divs[mx];
bool not_prime[mx];
int two_pow[10];

void preprocess()
{
    for (int i = 0; i < 10; i++) two_pow[i] = (1<<i);
    for (int i = 2; i < mx; i += 2) prime_divs[i] = 1;
    for (int i = 3; i < mx; i += 2) { 
        if (not_prime[i]) continue;
        for (int j = i; j < mx; j += i) {
            prime_divs[j]++;
            not_prime[j] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    preprocess();

    int test;
    cin >> test;
    while (test--) {
        int ans = 0;
        int c, d, x;
        cin >> c >> d >> x;
        int sq_x = sqrt(x);
        for (int g = 1; g <= sq_x; g++) if (x % g == 0) {
            int x1 = d + g;
            if (x1 % c == 0) {
                int m = x1 / c;
                ans += two_pow[prime_divs[m]];
            }
            if (g == x / g) continue;
            x1 = d + x / g;
            if (x1 % c == 0) {
                int m = x1 / c;
                ans += two_pow[prime_divs[m]];
            }
        }
        cout << ans << endl;
    }

    return 0;
}