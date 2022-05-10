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

const int maxn = 1e5 + 5;
const int MOD = 1e9 + 7;
int ara[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, ans;
    cin >> n;
    int mini, maxi;
    mini = inf;
    maxi = -inf;
    for (int i = 0; i < n; i++)
    {
        cin >> ara[i];
        mini = min(mini, ara[i]);
        maxi = max(maxi, ara[i]);
    }
    ans = n;
    if (maxi - mini == 2)
    {
        int cnt0, cnt1, cnt2;
        cnt0 = cnt1 = cnt2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (ara[i] == mini)
                cnt0++;
            else if (ara[i] == mini + 1)
                cnt1++;
            else
                cnt2++;
        }

        int cnt = min(cnt0, cnt2);
        cnt1 /= 2;
        if (cnt > cnt1)
        {
            cnt0 = cnt2 = cnt;
            for (int i = 0; i < n; i++)
            {
                if (cnt0 > 0 && ara[i] == mini)
                {
                    ara[i]++;
                    cnt0--;
                    ans--;
                }
                else if (cnt2 > 0 && ara[i] == mini + 2)
                {
                    ara[i]--;
                    cnt2--;
                    ans--;
                }
            }
        }
        else
        {
            int cntm = cnt1;
            for (int i = 0; i < n; i++)
            {
                if (cnt1 > 0 && ara[i] == mini + 1)
                {
                    ara[i]++;
                    cnt1--;
                    ans--;
                }
                else if (cntm > 0 && ara[i] == mini + 1)
                {
                    ara[i]--;
                    cntm--;
                    ans--;
                }
            }
        }
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++)
        cout << ara[i] << ' ';
    cout << endl;

    return 0;
}