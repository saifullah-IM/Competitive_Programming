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
#define fbo(k) find_by_order(k)    /// returns iterator to the kth largest element counting from 0
#define ook(val) order_of_key(val) /// returns the number of items in a set that are strictly smaller than val

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
/// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_int_set;

/// cout << fixed << setprecision(12) << ans << endl;

const int MX = 1e5 + 5;
const int MOD = 1e9 + 7;
// const int MOD = 998244353;

class JobInfo
{
public:
    int startTime;
    int endTime;
    int profit;

    JobInfo()
    {
        startTime = -1;
        endTime = -1;
        profit = -1;
    }

    bool operator<(const JobInfo &info)
    {
        if (startTime < info.startTime)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int search(vector<JobInfo> &jobs, int endTime)
{
    int lo = 0;
    int hi = jobs.size() - 1;

    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].startTime < endTime)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return lo;
}
int solve(vector<JobInfo> &jobs, vector<int> &dp, int start)
{
    if (start >= jobs.size())
        return 0;
    if (dp[start] != -1)
        return dp[start];

    int ans = solve(jobs, dp, start + 1);
    int next = search(jobs, jobs[start].endTime);
    // cout << start << ' ' << jobs[start].endTime << ' ' << next << '\n';
    ans = max(ans, jobs[start].profit + solve(jobs, dp, next));
    dp[start] = ans;

    return ans;
}
int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    vector<JobInfo> jobs(n);

    for (int i = 0; i < n; i++)
    {
        jobs[i].startTime = startTime[i];
        jobs[i].endTime = endTime[i];
        jobs[i].profit = profit[i];
    }
    sort(jobs.begin(), jobs.end());
    // for (int i = 0; i < n; i++)
    //     cout << jobs[i].startTime << ' ' << jobs[i].endTime << ' ' << jobs[i].profit << '\n';

    vector<int> dp(n, -1);
    return solve(jobs, dp, 0);
    // return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("myfile.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> startT(n);
    vector<int> endT(n);
    vector<int> profit(n);

    for (int i = 0; i < n; i++)
        cin >> startT[i];
    for (int i = 0; i < n; i++)
        cin >> endT[i];
    for (int i = 0; i < n; i++)
        cin >> profit[i];

    cout << jobScheduling(startT, endT, profit) << endl;

    return 0;
}
