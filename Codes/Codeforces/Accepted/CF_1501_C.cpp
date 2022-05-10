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

const int mx = 2e5 + 5;
const int MOD = 1e9 + 7;

int ara[mx];
vector <pii> sum[mx * 30];

void solve(int x)
{
    si myset;
    for (auto it: sum[x]) {
        myset.insert(it.fi);
        myset.insert(it.se);
    }
    sum[x].clear();
    vi myvec(myset.begin(), myset.end());


    int n = myvec.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int res = ara[myvec[i]] + ara[myvec[j]];
            sum[res].pb(mp(myvec[i], myvec[j]));
            for (auto it : sum[res]) {
                if (it.fi != myvec[i] && it.fi != myvec[j] && it.se != myvec[i] && it.se != myvec[j]) {
                    cout << "YES\n";
                    cout << myvec[i] + 1 << ' ' << myvec[j] + 1 << ' ' << it.fi + 1 << ' ' << it.se + 1 << '\n';
                    return;
                }
            }
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &ara[i]);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int res = ara[i] + ara[j];
            sum[res].pb(mp(i, j));
            for (auto it : sum[res]) {
                if (it.fi != i && it.fi != j && it.se != i && it.se !=j) {
                    cout << "YES\n";
                    cout << i + 1 << ' ' << j + 1 << ' ' << it.fi + 1 << ' ' << it.se + 1 << '\n';
                    return 0;
                }
            }
            if (sum[res].size() == 4) {
                solve(res);
                return 0;
            }
        }
    }
    cout << "NO\n";

    return 0;
}