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

const int MX = 2e5 + 5;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void build_table(int n, int log, vi &ara, vector<vi> &sparse_table)
{
    for (int i = 1; i < n; i++)
        sparse_table[i - 1][0] = gcd(ara[i - 1], ara[i]);
    for (int i = 1; i < log; i++)
        for (int j = 0; j + (1 << i) < n; j++)
            sparse_table[j][i] = gcd(sparse_table[j][i - 1], sparse_table[j + (1 << (i - 1))][i - 1]);
}

int binary_lift(int n, int u, int log, vi &ara, vector<vi> &sparse_table)
{
    int v = u;
    for (int i = log; i >= 0; i--)
    {
        if (v + (1 << i) >= n)
            continue;
        if (sparse_table[v][i] % ara[u] == 0)
            v += (1 << i);
    }
    return v;
}

int dsu_find(int u, vi &dsu_ara)
{
    if (dsu_ara[u] == u)
        return u;
    return dsu_ara[u] = dsu_find(dsu_ara[u], dsu_ara);
}

void dsu_union(int u, int v, vi &dsu_ara)
{
    int x = dsu_find(u, dsu_ara);
    int y = dsu_find(v, dsu_ara);
    dsu_ara[x] = dsu_ara[y] = max(x, y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test = 1;
    cin >> test;

    while (test--)
    {
        int n, p;
        cin >> n >> p;
        vi ara(n), reversed_ara(n);
        vector<pii> sorted_ara(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ara[i];
            reversed_ara[i] = ara[i];
            sorted_ara[i] = mp(ara[i], i);
        }
        reverse(reversed_ara.begin(), reversed_ara.end());
        sort(sorted_ara.begin(), sorted_ara.end());

        int log = 1;
        while ((1 << log) < n)
            log++;
        vector<vi> sparse_table(n, vi(log, -1));
        vector<vi> sparse_table_reversed(n, vi(log, -1));
        build_table(n, log, ara, sparse_table);
        build_table(n, log, reversed_ara, sparse_table_reversed);

        ll ans = 0;
        vi dsu_ara(n);
        for (int i = 0; i < n; i++)
            dsu_ara[i] = i;

        for (int i = 0; i < n; i++)
        {
            int u = sorted_ara[i].se;
            if (dsu_find(u, dsu_ara) != u)
                continue;
            if (sorted_ara[i].fi >= p)
                break;
            int v = binary_lift(n, u, log, ara, sparse_table);
            int x = binary_lift(n, n - u - 1, log, reversed_ara, sparse_table_reversed);
            u = n - x - 1;

            for (int j = dsu_find(u, dsu_ara) + 1; j <= v; j++)
            {
                ans += sorted_ara[i].fi;
                dsu_union(j, u, dsu_ara);
                if (dsu_find(j, dsu_ara) != j)
                    break;
            }
        }
        for (int i = 0; i < n; i++)
            if (dsu_ara[i] == i)
                ans += p;
        ans -= p;
        cout << ans << '\n';
    }

    return 0;
}