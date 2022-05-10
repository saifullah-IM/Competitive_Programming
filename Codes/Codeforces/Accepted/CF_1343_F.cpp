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

const int mx = 205;
const int MOD = 1e9 + 7;

int dist[mx][mx];
int cumsum[mx];
bool isStart[mx];

vi get_start_candidates(int n)
{
    vi ans;
    for (int num = 1; num <= n; num++)
    { //cout << "first in " << num << ' ' << n << endl;
        if (!isStart[num])
            continue;
        //cout << "got in " << num << endl;
        bool flag = true;
        for (int i = 1; i <= n; i++)
            cumsum[i] = 0;
        for (int i = 1; i <= n; i++)
            if (dist[num][i] < n)
                cumsum[dist[num][i]] += 1;
        cumsum[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cumsum[i] += cumsum[i - 1];
            if (cumsum[i] > i)
            {
                flag = false;
                // cout << "debug " << endl;
                // cout << num << ' ' << i << ' ' << cumsum[i] << endl;
                break;
            }
        }
        if (flag)
            ans.pb(num);
    }

    return ans;
}

int latest[mx];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int test;
    cin >> test;
    while (test--)
    {
        memset(dist, 63, sizeof(dist));
        memset(isStart, 0, sizeof(isStart));
        int n;
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int m;
            cin >> m;
            vi segment;
            for (int j = 1; j <= m; j++)
            {
                int u;
                cin >> u;
                segment.pb(u);
            }
            // cout << "ok  ";
            // for (int v : segment) cout << v << ' ';
            // cout << endl;
            for (int u : segment)
            {
                for (int v : segment)
                {
                    dist[u][v] = min(dist[u][v], m - 1);
                    dist[v][u] = min(dist[v][u], m - 1);
                }
            }
            if (m == 2)
                for (int v : segment)
                {
                    //cout << "segment size2 " << v << endl;
                    isStart[v] = true;
                }
        }
        for (int i = 1; i <= n; i++)
            dist[i][i] = 0;

        vi startCandidates = get_start_candidates(n);
        assert(startCandidates.size() != 0);

        vi ans;
        for (int start : startCandidates)
        { //cout << "start " << start << endl;
            ans.clear();
            memset(latest, 63, sizeof(latest));
            latest[start] = 1;
            for (int index = 1; index <= n; index++)
            {
                bool twice = false;
                int take = -1;
                for (int i = 1; i <= n; i++)
                {
                    if (latest[i] == index)
                    {
                        if (take == -1)
                            take = i;
                        else
                        {
                            twice = true;
                            break;
                        }
                    }
                }
                //cout << "index  " << index << "  take  " << take << endl;
                if (twice || take == -1)
                    break;
                ans.pb(take);
                for (int i = 1; i <= n; i++)
                {
                    latest[i] = min(latest[i], index + dist[take][i]);
                    //cout << latest[i] << ' ';
                }
                //cout << endl;
            }
            if (ans.size() == n)
                break;
        }

        assert(ans.size() != 0);
        for (int num : ans)
            cout << num << ' ';
        cout << endl;
    }

    return 0;
}
