#include <bits/stdc++.h>
#define inf 2000000000
using namespace std;

int v1, v2, d, t, DP[1110][110];

int covered_path(int v, int T)
{
    if (v < 0)
        return -inf;
    if (T == t)
    {
        if (v == v2)
            return v;
        else
            return -inf;
    }
    if (DP[v][T] != -1)
        return DP[v][T];

    int i, k, ans;
    ans = -inf;
    for (i = 0; i <= d; i++)
    {
        k = v + i;
        ans = max(ans, covered_path(k, T + 1));
        k = v - i;
        ans = max(ans, covered_path(k, T + 1));
    }

    ans += v;
    return DP[v][T] = ans;
}

int main()
{
    int ans;

    scanf("%d %d", &v1, &v2);
    scanf("%d %d", &t, &d);
    memset(DP, -1, sizeof(DP));
    ans = covered_path(v1, 1);
    printf("%d\n", ans);

    return 0;
}
