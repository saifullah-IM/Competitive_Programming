#include <bits/stdc++.h>
using namespace std;

struct info
{
    int w, h, idx;
};

bool srtfnc(info A, info B)
{
    if (A.w == B.w)
        return A.h < B.h;
    else
        return A.w < B.w;
}

info ara[5005];
int n, DP[5005], path[5005];

int mysterious_present(int i)
{
    if (DP[i] != -1)
        return DP[i];

    int j, ans;
    ans = 1;
    for (j = i + 1; j < n; j++)
    {
        if (ara[i].w < ara[j].w && ara[i].h < ara[j].h)
        {
            if (ans < 1 + mysterious_present(j))
            {
                ans = 1 + mysterious_present(j);
                path[i] = j;
            }
        }
    }

    return DP[i] = ans;
}

int main()
{
    int i, w, h, W, H, ans, idx;

    scanf("%d %d %d", &n, &W, &H);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &w, &h);
        ara[i].w = w;
        ara[i].h = h;
        ara[i].idx = i;
    }

    memset(DP, -1, sizeof(DP));
    sort(ara, ara + n, srtfnc);
    ans = 0;
    for (i = 0; i < n; i++)
    {
        if (ara[i].w > W && ara[i].h > H)
        {
            if (ans < mysterious_present(i))
            {
                ans = mysterious_present(i);
                idx = i;
            }
        }
    }

    printf("%d\n", ans);
    if (ans != 0)
    {
        printf("%d ", ara[idx].idx + 1);
        while (DP[idx] != 1)
        {
            idx = path[idx];
            printf("%d ", ara[idx].idx + 1);
        }
    }

    return 0;
}
