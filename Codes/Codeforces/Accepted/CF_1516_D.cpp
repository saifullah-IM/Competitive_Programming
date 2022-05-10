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

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;

vi divisor_list[MX];
bool is_comp[MX];
void sieve()
{
    for (int i = 2; i < MX; i += 2)
    {
        is_comp[i] = true;
        divisor_list[i].pb(2);
    }
    for (int i = 3; i < MX; i += 2)
    {
        if (is_comp[i])
            continue;
        for (int j = i; j < MX; j += i)
        {
            is_comp[j] = true;
            divisor_list[j].pb(i);
        }
    }
}

vi prime_idx[MX];
int go_next[MX];
void preprocess(vi &ara)
{
    int n = ara.size();
    for (int i = 0; i < n; i++)
        for (int u : divisor_list[ara[i]])
            prime_idx[u].pb(i);

    for (int i = 1; i < n; i++)
        prime_idx[i].pb(n);

    for (int i = 0; i < n; i++)
    {
        go_next[i] = n;
        for (int u : divisor_list[ara[i]])
        {
            int v = *(upper_bound(prime_idx[u].begin(), prime_idx[u].end(), i));
            go_next[i] = min(go_next[i], v);
        }
    }

    for (int i = n - 2; i >= 0; i--)
        go_next[i] = min(go_next[i], go_next[i + 1]);
    go_next[n] = n;

    // for (int i = 0; i < n; i++)
    //     cout << go_next[i] << "   ---------------- \n";
}

const int lg = 18;
int sparse_table[MX][lg];
void build_table(int n)
{
    for (int i = 0; i < n; i++)
        sparse_table[i][0] = go_next[i];

    for (int i = 0; i < lg; i++)
        sparse_table[n][i] = n;

    for (int j = 1; j < lg; j++)
        for (int i = 0; i < n; i++)
            sparse_table[i][j] = sparse_table[sparse_table[i][j - 1]][j - 1];
}

int query(int l, int r)
{
    int ans = 0;
    int crnt = l;
    for (int i = lg - 1; i >= 0; i--)
    {
        if (sparse_table[crnt][i] <= r)
        {
            ans += (1 << i);
            crnt = sparse_table[crnt][i];
        }
    }
    ans += 1;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();

    int test = 1;
    //cin >> test;
    while (test--)
    {
        int n, q;
        cin >> n >> q;
        vi ara(n);
        for (int i = 0; i < n; i++)
            cin >> ara[i];
        preprocess(ara);
        build_table(n);
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            cout << query(l - 1, r - 1) << '\n';
        }
    }

    return 0;
}