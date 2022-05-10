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

const int mx = 3e5 + 5;
const int MOD = 1e9 + 7;
int GCD(int a, int b)
{
    while (b > 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int gcdTable[mx][20], ara[mx];
void prep(int n)
{
    for (int i = 0; i < n - 1; i++)
        gcdTable[i][0] = GCD(ara[i], ara[i + 1]);
    for (int j = 1; (1 << j) < n; j++)
    {
        for (int i = 0; i + (1 << (j - 1)) < n; i++)
        {
            gcdTable[i][j] = GCD(gcdTable[i][j - 1], gcdTable[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int findGcd(int l, int r)
{
    if (l > r)
        swap(l, r);
    int ans = ara[l];
    for (int i = 19; i >= 0; i--)
    {
        if (r - (1 << i) >= l)
        {
            ans = GCD(ans, gcdTable[l][i]);
            l += (1 << i);
        }
    }
    return ans;
}
int lft[mx], rgt[mx];
vi ans;
bool mark[mx];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ara[i];
    prep(n);
    for (int i = 0; i < n; i++)
    {
        int lo, hi, mid;
        lo = 0;
        hi = i;
        int res = 0;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            int gcd = findGcd(i - mid, i);
            if (gcd % ara[i] == 0)
            {
                if (gcd == ara[i])
                    res = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        lft[i] = res;

        lo = 0;
        hi = n - 1 - i;
        res = 0;
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            int gcd = findGcd(i + mid, i);
            if (gcd % ara[i] == 0)
            {
                if (gcd == ara[i])
                    res = mid;
                lo = mid + 1;
            }
            else
                hi = mid - 1;
        }
        rgt[i] = res;
    }

    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int temp = lft[i] + rgt[i];
        if (temp == maxi)
        {
            int x = i - lft[i] + 1;
            if (!mark[x])
            {
                ans.pb(x);
                mark[x] = true;
            }
        }
        else if (temp > maxi)
        {
            maxi = temp;
            ans.clear();
            int x = i - lft[i] + 1;
            ans.pb(x);
            mark[x] = true;
        }
    }
    cout << ans.size() << ' ' << maxi << endl;
    for (int u : ans)
        cout << u << ' ';

    return 0;
}
