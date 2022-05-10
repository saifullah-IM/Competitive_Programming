#include <bits/stdc++.h>
using namespace std;

int mx, treasure[30005], DP[30005][1050];

int treasure_hunt(int n, int d)
{
    if (n > mx)
        return 0;
    if (d < 1050 && DP[n][d] != -1)
        return DP[n][d];

    int ans;
    ans = 0;
    ans = max(ans, treasure_hunt(n + d, d));
    ans = max(ans, treasure_hunt(n + d, d + 1));
    if (d > 1)
        ans = max(ans, treasure_hunt(n + d, d - 1));
    ans += treasure[n];
    if (d < 1050)
        DP[n][d] = ans;

    return ans;
}

int main()
{
    int i, n, d, ans;

    scanf("%d %d", &n, &d);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &mx);
        treasure[mx]++;
    }
    memset(DP, -1, sizeof(DP));
    ans = treasure_hunt(0, d);
    printf("%d", ans);

    return 0;
}
