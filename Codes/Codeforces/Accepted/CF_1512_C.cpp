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
#define inf (1 << 30)
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
typedef multiset<int>::iterator mit;
typedef map<int, int> mii;
typedef map<int, int>::iterator miit;
///typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

///cout << fixed << setprecision(12) << ans << endl;

const int mx = 1e5 + 5;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    cin >> test;
    while (test--)
    {
        int a, b;
        string str;
        cin >> a >> b;
        cin >> str;
        int n = a + b;
        bool ok = true;
        for (int i = 0; i < n; i++)
        {
            if (i >= n - i - 1)
                break;
            if (str[i] == str[n - i - 1])
                continue;
            else if (str[i] == '?')
                str[i] = str[n - i - 1];
            else if (str[n - i - 1] == '?')
                str[n - i - 1] = str[i];
            else
            {
                ok = false;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '0')
                a--;
            else if (str[i] == '1')
                b--;
        }
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '?')
            {
                if (i == n - i - 1)
                {
                    if (a % 2 == 1)
                    {
                        str[i] = '0';
                        a--;
                    }
                    else if (b % 2 == 1)
                    {
                        str[i] = '1';
                        b--;
                    }
                    else
                    {
                        ok = false;
                        break;
                    }
                }
                else
                {
                    if (a >= 2)
                    {
                        str[i] = str[n - i - 1] = '0';
                        a -= 2;
                    }
                    else if (b >= 2)
                    {
                        str[i] = str[n - i - 1] = '1';
                        b -= 2;
                    }
                    else
                    {
                        ok = false;
                        break;
                    }
                }
            }
        }

        if (!ok || a != 0 || b != 0)
            cout << "-1\n";
        else
            cout << str << '\n';
    }

    return 0;
}