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

const int mx = 1e7 + 5;
const int MOD = 1e9 + 7;

vi primes;
bool not_prime[mx];

void sieve()
{
    int k = sqrt(mx);
    primes.pb(2);
    for (int i = 4; i <= k; i += 2) not_prime[i] = true;
    for (int i = 3; i <= k; i += 2) {
        if(not_prime[i]) continue;
        primes.pb(i);
        for (int j = i * i; j < mx; j += i) {
            not_prime[j] = true;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    sieve();

    int test;
    cin >> test;
    while (test--) {
        int n, k;
        cin >> n >> k;
        vi ara(n);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for (int y: primes) {
                int z = y * y;
                while (x % z == 0) x /= z;
            }
            ara[i] = x;
        }
        int ans = 0;
        si myset;
        for (int x : ara) {
            if (myset.find(x) == myset.end()) myset.insert(x);
            else {
                myset.clear();
                myset.insert(x);
                ans += 1;
            }
            //cout << x << ' ' << ans << endl;
        }
        if (!myset.empty()) ans += 1;
        cout << ans << endl;
    }

    return 0;
}