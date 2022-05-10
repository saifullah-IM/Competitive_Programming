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

const int mx = 5e3 + 5;
const int MOD = 1e9 + 7;

vi graph[mx];
vi node_list[mx][2];
short int mark[mx];

pii bfs(int node, int iter)
{
    queue<int> myQ;
    myQ.push(node);
    mark[node] = 0;
    vi ones, zeros;

    while (!myQ.empty())
    {
        int u = myQ.front();
        myQ.pop();
        if (mark[u])
            ones.pb(u);
        else
            zeros.pb(u);
        for (int v : graph[u])
        {
            int newMark = mark[u] ^ 1;
            if (mark[v] == newMark)
                continue;
            else if (mark[v] == -1)
            {
                mark[v] = newMark;
                myQ.push(v);
            }
            else
                return mp(-1, -1);
        }
    }

    if (zeros.size() > ones.size())
    {
        node_list[iter][0] = ones;
        node_list[iter][1] = zeros;
    }
    else
    {
        node_list[iter][0] = zeros;
        node_list[iter][1] = ones;
    }

    return mp(node_list[iter][0].size(), node_list[iter][1].size());
}

short int extras[mx];
short int dp[mx][mx];

int solve(int summation, int num_of_extras)
{ // cout << summation << ' ' << num_of_extras << endl;
    if (dp[summation][num_of_extras] != -1)
        return dp[summation][num_of_extras];
    if (summation == extras[num_of_extras])
        return dp[summation][num_of_extras] = num_of_extras;
    if (num_of_extras == 1)
        return dp[summation][1] = 0;

    int not_take = solve(summation, num_of_extras - 1);
    if (not_take != 0)
        return dp[summation][num_of_extras] = not_take;

    if (summation > extras[num_of_extras])
    {
        int take = solve(summation - extras[num_of_extras], num_of_extras - 1);
        if (take != 0)
            return dp[summation][num_of_extras] = num_of_extras;
    }

    return dp[summation][num_of_extras] = 0;
}

bool take_big[mx];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(mark, -1, sizeof(mark));
    memset(dp, -1, sizeof(dp));

    int n, m;
    cin >> n >> m;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    int summation = n2;
    int iter = 1;
    for (int node = 1; node <= n; node++)
    { //cout << iter << endl;
        if (mark[node] == -1)
        {
            pii newPair = bfs(node, iter);
            summation -= newPair.fi;
            extras[iter] = newPair.se - newPair.fi;
            // assert(extras[iter] == 1);
            if (newPair.fi == -1 || summation < 0)
            {
                cout << "NO" << endl;
                return 0;
            }
            iter++;

            // cout << "iter " << iter << " pair ";
            // cout << newPair.fi << ' ' << newPair.se << endl;
            // cout << "small group nodes ";
            // for (int v : node_list[iter-1][0]) cout << v << ' ';
            // cout << endl;
            // cout << "large group nodes ";
            // for (int v : node_list[iter-1][1]) cout << v << ' ';
            // cout << endl;
        }
    }
    // cout << "debug" << endl;
    // for (int node = 1; node <= n; node++) cout << mark[node];
    // cout << endl;

    // cout << summation << endl;

    if (summation != 0)
    {
        int next_idx = solve(summation, iter - 1);
        if (next_idx == 0)
        {
            cout << "NO" << endl;
            return 0;
        }
        // cout << next_idx << endl;

        while (summation > 0)
        {
            if (dp[summation][next_idx] == next_idx)
            {
                summation -= extras[next_idx];
                take_big[next_idx] = true;
                next_idx -= 1;
            }
            else
                next_idx = dp[summation][next_idx];
        }
    }

    memset(mark, -1, sizeof(mark));
    for (int i = 1; i <= iter; i++)
    {
        if (take_big[i])
        { //cout << "big taken at iter " << i << endl;
            for (int node : node_list[i][1])
                mark[node] = 2;
        }
        else
        { //cout << "small taken at iter " << i << endl;
            for (int node : node_list[i][0])
                mark[node] = 2;
        }
    }

    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] == 2)
            cout << 2;
        else if (n1 > 0)
        {
            cout << 1;
            n1--;
        }
        else
            cout << 3;
    }
    cout << endl;

    return 0;
}
