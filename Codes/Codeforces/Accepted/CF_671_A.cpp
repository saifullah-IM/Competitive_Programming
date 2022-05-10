#include <bits/stdc++.h>
#define PDI pair<double, int>
using namespace std;

bool srtfnc(PDI A, PDI B)
{
    return A.first > B.first;
}

PDI save1[100005], save2[100005];
int main()
{
    int i, n, ax, ay, bx, by, tx, ty, x, y;
    double ans, temp, sv;

    ans = 0;
    scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &tx, &ty);
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        temp = (x - tx) * 1.0 * (x - tx) + (y - ty) * 1.0 * (y - ty);
        ans += 2 * sqrt(temp);

        sv = (x - ax) * 1.0 * (x - ax) + (y - ay) * 1.0 * (y - ay);
        sv = sqrt(temp) - sqrt(sv);
        save1[i] = make_pair(sv, i);

        sv = (x - bx) * 1.0 * (x - bx) + (y - by) * 1.0 * (y - by);
        sv = sqrt(temp) - sqrt(sv);
        save2[i] = make_pair(sv, i);
    }
    sort(save1, save1 + n, srtfnc);
    sort(save2, save2 + n, srtfnc);

    if (n == 1)
        ans -= max(save1[0].first, save2[0].first);
    else
    {
        if (save1[0].second == save2[0].second)
        {
            if (save1[1].first > 0 && save2[1].first > 0)
            {
                ans -= max(save1[0].first + save2[1].first, save1[1].first + save2[0].first);
            }
            else if (save1[1].first > 0 && save2[0].first > 0)
            {
                ans -= max(save2[0].first + save1[1].first, save1[0].first);
            }
            else if (save1[0].first > 0 && save2[1].first > 0)
            {
                ans -= max(save1[0].first + save2[1].first, save2[0].first);
            }
            else
            {
                ans -= max(save1[0].first, save2[0].first);
            }
        }
        else if (save1[0].first <= 0 && save2[0].first <= 0)
            ans -= max(save1[0].first, save2[0].first);
        else
        {
            if (save1[0].first > 0)
                ans -= save1[0].first;
            if (save2[0].first > 0)
                ans -= save2[0].first;
        }
    }

    printf("%0.12f", ans);

    return 0;
}
