#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

struct info
{
    int c, p, i;
};

bool srtfnc(info A, info B)
{
    if (A.p == B.p)
        return A.c < B.c;
    else
        return A.p > B.p;
}

bool cmpfnc(PII A, PII B)
{
    return A.first < B.first;
}

bool chk[1005];
int main()
{
    int i, j, n, k, m, ans;
    info A, grps[1005];
    PII tbls[1005];
    vector<PII> myans;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &grps[i].c, &grps[i].p);
        grps[i].i = i + 1;
    }
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d", &tbls[i].first);
        tbls[i].second = i + 1;
    }

    sort(grps, grps + n, srtfnc);
    sort(tbls, tbls + k, cmpfnc);

    ans = 0;
    for (i = 0; i < n; i++)
    {
        int hi, lo, mid;
        hi = k - 1;
        lo = 0;
        while (lo <= hi)
        {
            mid = (hi + lo) / 2;
            if (tbls[mid].first < grps[i].c)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        for (j = hi + 1; j < k; j++)
            if (!chk[j])
            {
                chk[j] = true;
                ans += grps[i].p;
                myans.push_back(make_pair(grps[i].i, tbls[j].second));
                break;
            }
    }

    m = myans.size();
    printf("%d %d\n", m, ans);
    for (i = 0; i < m; i++)
        printf("%d %d\n", myans[i].first, myans[i].second);

    return 0;
}