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

void winCheck(int &star, int &rnk)
{
    if (rnk >= 21)
    {
        if (star > 2)
        {
            rnk--;
            star -= 2;
        }
    }
    else if (rnk >= 16)
    {
        if (star > 3)
        {
            rnk--;
            star -= 3;
        }
    }
    else if (rnk >= 11)
    {
        if (star > 4)
        {
            rnk--;
            star -= 4;
        }
    }
    else if (rnk >= 1)
    {
        if (star > 5)
        {
            rnk--;
            star -= 5;
        }
    }
}

void loseCheck(int &star, int &rnk)
{
    if (star >= 0)
        return;
    if (rnk == 0)
        return;
    if (rnk == 20)
    {
        star = 0;
        return;
    }
    rnk++;
    if (rnk >= 16 && rnk <= 20)
        star = 2;
    else if (rnk >= 11 && rnk <= 15)
        star = 3;
    else if (rnk >= 1 && rnk <= 10)
        star = 4;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str;
    cin >> str;

    int star, rnk, win;
    int n = str.size();

    star = win = 0;
    rnk = 25;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == 'W')
        {
            win++;
            star++;
            if (rnk >= 6 && win >= 3)
                star++;
            winCheck(star, rnk);
        }
        else
        {
            win = 0;
            if (rnk <= 20 && rnk >= 1)
                star--;
            loseCheck(star, rnk);
        }
    }
    if (rnk == 0)
        cout << "Legend" << endl;
    else
        cout << rnk << endl;

    return 0;
}