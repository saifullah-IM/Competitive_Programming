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
const ld eps = 1e-12;

class point
{
public:
    ld x, y;
    point(ld x = 0, ld y = 0) { this->x = x, this->y = y; }
    ld dist(const point &a)
    {
        ld d;
        d = (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y);
        d = sqrt(d);
        return d;
    }
    bool operator<(const point &a) const
    {
        if (abs(x - a.x) <= eps)
            return y < a.y;
        return x < a.x;
    }
    bool operator==(const point &a) const
    {
        return (abs(x - a.x) <= eps && abs(y - a.y) <= eps);
    }
};
typedef vector<point> vp;

class circle
{
public:
    point o;
    ld r;
    circle() { o = point(0, 0), r = 0; }
    void setCircle(point o, ld r)
    {
        this->o = o;
        this->r = r;
    }
    vp intersection(const circle &cc)
    {
        ld d = o.dist(cc.o);
        if (d > r + cc.r || (d < abs(r - cc.r)))
            return vp();

        ld alpha = atan2(cc.o.y - o.y, cc.o.x - o.x);
        ld delta = (r * r + d * d - cc.r * cc.r) / (2 * r * d);
        delta = acos(max((ld)-1.0, (min((ld)1.0, delta))));
        point p1(o.x + r * cos(alpha + delta), o.y + r * sin(alpha + delta));
        point p2(o.x + r * cos(alpha - delta), o.y + r * sin(alpha - delta));
        vp res;
        res.pb(p1);
        res.pb(p2);
        return res;
    }
} cyc[60];

int parent[60];
int Find(int u)
{
    if (parent[u] == u)
        return u;
    else
        return parent[u] = Find(parent[u]);
}
void unite(int u, int v)
{
    int n = Find(u);
    int m = Find(v);
    parent[m] = n;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("circles.in", "r", stdin);
    // freopen("circles.out", "w", stdout);

    int n, x, y, r;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> r;
        cyc[i].setCircle(point(x, y), r);
    }
    for (int i = 0; i < n; i++)
        parent[i] = i;
    int e = 0, v = 0, c = 0;
    vp node;
    for (int i = 0; i < n; i++)
    {
        vp vec;
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            vp res = cyc[i].intersection(cyc[j]);
            if (!res.empty())
                unite(i, j);
            for (auto it : res)
            {
                vec.pb(it);
                node.pb(it);
            }
        }
        sort(vec.begin(), vec.end());
        e += unique(vec.begin(), vec.end()) - vec.begin();
    }
    sort(node.begin(), node.end());
    v = unique(node.begin(), node.end()) - node.begin();
    for (int i = 0; i < n; i++)
        if (i == Find(i))
            c++;
    cout << e - v + c + 1 << endl;

    return 0;
}
