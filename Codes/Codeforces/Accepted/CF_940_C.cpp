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

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;
string str;
int n, k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string ans;
    cin >> n >> k;
    cin >> str;
    char ch;
    if (n < k)
    {
        ch = 'z';
        for (int i = 0; i < n; i++)
        {
            ch = min(ch, str[i]);
        }
        cout << str;
        for (int i = n; i < k; i++)
            cout << ch;
        cout << endl;
        return 0;
    }
    else
    {
        int idx = -1;
        ch = 'a';
        char ch1, ch2;
        ch1 = 'a';
        ch2 = 'z';
        int ara[30];
        memset(ara, 0, sizeof(ara));
        for (int i = 0; i < n; i++)
        {
            ch = max(ch, str[i]);
            ch2 = min(ch2, str[i]);
            ara[str[i] - 'a'] = 1;
        }
        for (int i = 0; i < k - 1; i++)
        {
            if (str[i + 1] < ch)
                idx = max(idx, i);
        }
        for (int i = 0; i <= idx; i++)
        {
            cout << str[i];
        }
        for (int i = 0; i < 26; i++)
        {
            if (ara[i] != 0 && i > str[idx + 1] - 'a')
            {
                ch1 = 'a' + i;
                break;
            }
        }
        cout << ch1;
        for (int i = idx + 2; i < k; i++)
            cout << ch2;
        cout << endl;
    }

    return 0;
}
