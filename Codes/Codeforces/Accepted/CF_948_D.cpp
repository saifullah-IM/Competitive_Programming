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

const int maxn = 3e5 + 5;
const int MOD = 1e9 + 7;

class Trie
{
    int node[maxn * 30][2], cnt[maxn * 30], nnode, mx;

public:
    Trie()
    {
        mx = 30;
        nnode = 0;
        node[0][0] = node[0][1] = -1;
    }
    void insert(int n)
    {
        int ara[mx];
        for (int i = 0; i < mx; i++)
        {
            ara[mx - i - 1] = n % 2;
            n /= 2;
        }

        int now = 0;
        for (int i = 0; i < mx; i++)
        {
            if (node[now][ara[i]] == -1)
            {
                node[now][ara[i]] = ++nnode;
                node[nnode][0] = node[nnode][1] = -1;
            }
            now = node[now][ara[i]];
            cnt[now]++;
        }
    }
    void remove(int n)
    {
        int ara[mx];
        for (int i = 0; i < mx; i++)
        {
            ara[mx - i - 1] = n % 2;
            n /= 2;
        }

        int now = 0;
        for (int i = 0; i < mx; i++)
        {
            int temp = now;
            now = node[now][ara[i]];
            cnt[now]--;
            if (cnt[now] < 1)
                node[temp][ara[i]] = -1;
        }
    }
    int query(int n)
    {
        int ara[mx];
        for (int i = 0; i < mx; i++)
        {
            ara[mx - i - 1] = n % 2;
            n /= 2;
        }

        int now = 0, ans = 0;
        for (int i = 0; i < mx; i++)
        {
            ans <<= 1;
            if (node[now][ara[i]] == -1)
            {
                ans |= 1;
                now = node[now][ara[i] ^ 1];
            }
            else
                now = node[now][ara[i]];
        }

        return ans;
    }
} T;

int ara[maxn], ans[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ara[i];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        T.insert(x);
    }
    for (int i = 0; i < n; i++)
    {
        ans[i] = T.query(ara[i]);
        T.remove(ara[i] ^ ans[i]);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';

    return 0;
}
