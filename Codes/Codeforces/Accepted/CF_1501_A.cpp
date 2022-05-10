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

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int test;
    cin >> test;
    while(test--) {
        int n;
        cin >> n;
        vi a_ara, b_ara, tm_ara;
        a_ara.resize(n + 1);
        b_ara.resize(n + 1);
        tm_ara.resize(n + 1);
        for (int i = 1; i <= n; i++) cin >> a_ara[i] >> b_ara[i]; 
        for (int i = 1; i <= n; i++) cin >> tm_ara[i];
        b_ara[0] = 0;
        int current_time = 0;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int travel_time = a_ara[i] - b_ara[i - 1] + tm_ara[i];
            int arrival_time = current_time + travel_time;
            ans = arrival_time;
            current_time = arrival_time + max(int(ceil((b_ara[i] - a_ara[i]) / 2.0)), b_ara[i] - arrival_time);
            //cout << current_time << "  " << i << '\n';
        }
        cout << ans << '\n';
    }

    return 0;
}