/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

const int mx = 100005;
int ara[mx];
deque<PII> maxi, mini;
vector<PII> ans;

int main()
{
    int i, n, k, lo, hi, d, books;
    bool L, H;

    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++)
        scanf("%d", &ara[i]);
    lo = hi = books = 0;
    H = true;
    L = false;
    while (hi < n)
    {
        if (H)
        {
            while (!maxi.empty() && maxi.back().first <= ara[hi])
                maxi.pop_back();
            while (!mini.empty() && mini.back().first >= ara[hi])
                mini.pop_back();
            maxi.push_back(make_pair(ara[hi], hi));
            mini.push_back(make_pair(ara[hi], hi));
        }
        if (L)
        {
            while (maxi.front().second < lo)
                maxi.pop_front();
            while (mini.front().second < lo)
                mini.pop_front();
        }
        d = maxi.front().first - mini.front().first;
        if (d <= k)
        {
            if (books == hi - lo + 1)
                ans.push_back(make_pair(lo + 1, hi + 1));
            else if (books < hi - lo + 1)
            {
                books = hi - lo + 1;
                ans.clear();
                ans.push_back(make_pair(lo + 1, hi + 1));
            }
            hi++;
            L = false;
            H = true;
        }
        else
        {
            lo++;
            L = true;
            H = false;
        }
    }

    printf("%d %d\n", books, ans.size());
    for (i = 0; i < ans.size(); i++)
        printf("%d %d\n", ans[i].first, ans[i].second);

    return 0;
}
