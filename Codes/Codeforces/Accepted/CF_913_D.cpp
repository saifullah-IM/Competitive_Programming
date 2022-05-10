/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 5;
typedef pair<int, int> PII;
vector<PII> ara[mx];
vector<PII> myset;
vector<int> ans;
int n, T;

bool check(int a)
{
    myset.clear();
    for (int i = a; i <= n; i++)
        if (!ara[i].empty())
        {
            for (auto x : ara[i])
                myset.push_back(x);
        }
    if (myset.size() < a)
        return false;
    int sum = 0;
    sort(myset.begin(), myset.end());
    for (int i = 0; i < a; i++)
    {
        sum += myset[i].first;
    }
    if (sum <= T)
    {
        ans.clear();
        for (int i = 0; i < a; i++)
            ans.push_back(myset[i].second);
        return true;
    }
    else
        return false;
}

int main()
{
    scanf("%d %d", &n, &T);
    for (int i = 0; i < n; i++)
    {
        int a, t;
        scanf("%d %d", &a, &t);
        ara[a].push_back(PII(t, i + 1));
    }
    int lo, hi, mid;
    lo = 1;
    hi = n;
    int res = 0;
    while (lo <= hi)
    {
        mid = (lo + hi) / 2;
        if (check(mid))
        {
            res = mid;
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    printf("%d\n%d\n", res, res);
    for (int x : ans)
        printf("%d ", x);

    return 0;
}
