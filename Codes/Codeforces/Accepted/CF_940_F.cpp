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
const int block = 2200;
int ara[mx], last[mx], cnt[2 * mx], cnt_cnt[700], ans[mx];
vi vec;
struct query
{
    int l, r, t, id;
} Q[mx];
struct update
{
    int x, pre, now;
} U[mx];
bool cmp(query A, query B)
{
    int al = A.l / block, ar = A.r / block;
    int bl = B.l / block, br = B.r / block;
    if (al != bl)
        return al < bl;
    if (ar != br)
        return ar < br;
    return A.t < B.t;
}
void add(int u)
{
    int x = cnt[ara[u]];
    cnt[ara[u]]++;
    if (x < 700)
        cnt_cnt[x]--;
    if (cnt[ara[u]] < 700)
        cnt_cnt[cnt[ara[u]]]++;
}
void remove(int u)
{
    int x = cnt[ara[u]];
    cnt[ara[u]]--;
    if (x < 700)
        cnt_cnt[x]--;
    if (cnt[ara[u]] < 700)
        cnt_cnt[cnt[ara[u]]]++;
}
void apply(int x, int val, int l, int r)
{
    if (x >= l && x <= r)
    {
        remove(x);
        ara[x] = val;
        add(x);
    }
    else
        ara[x] = val;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> ara[i];
        last[i] = ara[i];
        vec.pb(ara[i]);
    }
    int u = 0, p = 0;
    for (int i = 0; i < q; i++)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            l--, r--;
            Q[p] = {l, r, u, p};
            p++;
        }
        else
        {
            u++, l--;
            U[u] = {l, last[l], r};
            last[l] = r;
            vec.pb(r);
        }
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < n; i++)
        ara[i] = lower_bound(vec.begin(), vec.end(), ara[i]) - vec.begin();
    for (int i = 1; i <= u; i++)
    {
        U[i].pre = lower_bound(vec.begin(), vec.end(), U[i].pre) - vec.begin();
        U[i].now = lower_bound(vec.begin(), vec.end(), U[i].now) - vec.begin();
    }
    sort(Q, Q + p, cmp);
    int l = 0, r = -1, t = 0;
    for (int i = 0; i < p; i++)
    {
        while (Q[i].t > t)
            t++, apply(U[t].x, U[t].now, l, r);
        while (Q[i].t < t)
            apply(U[t].x, U[t].pre, l, r), t--;
        while (l > Q[i].l)
            add(--l);
        while (r < Q[i].r)
            add(++r);
        while (l < Q[i].l)
            remove(l++);
        while (r > Q[i].r)
            remove(r--);
        for (int j = 1; j < 700; j++)
        {
            if (cnt_cnt[j] == 0)
            {
                if (ans[Q[i].id] == 0)
                    ans[Q[i].id] = j;
                break;
            }
        }
    }
    for (int i = 0; i < p; i++)
        cout << ans[i] << endl;

    return 0;
}
