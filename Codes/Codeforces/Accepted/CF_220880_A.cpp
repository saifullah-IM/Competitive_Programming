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

const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;

int cnt[30];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        sum += str.size();
        for (int j = 0; j < str.size(); j++)
        {
            assert(str[j] >= 'A' && str[j] <= 'Z');
            cnt[str[j] - 'A']++;
        }
    }

    string src;
    cin >> src;
    int m = src.size();
    if (m < sum)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < m; i++)
    {
        assert(src[i] >= 'A' && src[i] <= 'Z');
        cnt[src[i] - 'A']--;
    }

    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans += max(0, cnt[i]);
    cout << ans << endl;

    return 0;
}
