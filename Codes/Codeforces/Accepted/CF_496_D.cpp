/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

const int mx = 100005;
PII ara[mx];
vector<PII> ans;

int main()
{
    int i, j, k, n, m, x, cnt1, cnt2, win, W;
    PII A;

    A.first = A.second = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (x == 1)
            A.first++;
        else
            A.second++;
        ara[i] = A;
    }

    m = max(A.first, A.second);
    for (i = 1; i <= m; i++)
    {
        int hi, lo, mid;
        lo = cnt1 = cnt2 = 0;
        A.first = A.second = 0;
        while (lo < n)
        {
            hi = n - 1;
            win = -1;
            while (lo <= hi)
            {
                mid = (lo + hi) / 2;
                if (ara[mid].first - A.first >= i || ara[mid].second - A.second >= i)
                {
                    hi = mid - 1;
                    if (ara[mid].first - A.first > ara[mid].second - A.second)
                        win = 1;
                    else
                        win = 2;
                }
                else
                    lo = mid + 1;
            }
            A = ara[hi + 1];
            lo = hi + 2;
            if (win == 1)
                cnt1++;
            else if (win == 2)
                cnt2++;
        }
        if (win == -1)
            continue;
        if (cnt1 > cnt2)
            W = 1;
        else
            W = 2;
        if (cnt1 != cnt2 && W == x)
            ans.push_back(make_pair(max(cnt1, cnt2), i));
    }

    m = ans.size();
    sort(ans.begin(), ans.end());
    printf("%d\n", m);
    for (i = 0; i < m; i++)
        printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}
