/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

const int mx = 100005;
int detail[mx][6], ans[6];
deque<PII> window[6];

int main()
{
    int i, j, n, m, k, hi, lo, temp, sum;
    bool L, H;

    scanf("%d %d %d", &n, &m, &k);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &detail[i][j]);

    H = true;
    lo = hi = temp = 0;
    while (hi < n)
    {
        if (H)
            for (i = 0; i < m; i++)
            {
                while (!window[i].empty() && window[i].back().first <= detail[hi][i])
                    window[i].pop_back();
                window[i].push_back(make_pair(detail[hi][i], hi));
            }
        if (L)
            for (i = 0; i < m; i++)
            {
                while (window[i].front().second < lo)
                    window[i].pop_front();
            }
        for (i = sum = 0; i < m; i++)
            sum += window[i].front().first;
        if (sum <= k)
        {
            if (temp < hi - lo + 1)
            {
                for (i = 0; i < m; i++)
                    ans[i] = window[i].front().first;
                temp = hi - lo + 1;
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
        if (lo > hi)
        {
            hi = lo;
            H = true;
        }
    }
    for (i = 0; i < m; i++)
        printf("%d ", ans[i]);

    return 0;
}
