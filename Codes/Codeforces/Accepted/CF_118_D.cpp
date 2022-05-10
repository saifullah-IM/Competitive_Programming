#include <bits/stdc++.h>
#define MOD 100000000
using namespace std;

int ara1[101][101], ara2[101][101], n1, n2, k1, k2;
int legion(int i, int j, bool flag)
{
    int p, ans = 0;
    if (i > n1 || j > n2)
        return 0;
    else if (i == n1 && j == n2)
        return 1;
    else if (flag && ara1[i][j] != -1)
        return ara1[i][j];
    else if (!flag && ara2[i][j] != -1)
        return ara2[i][j];
    else
    {
        if (flag)
        {
            for (p = 1; p <= k1; p++)
                ans = (ans + legion(p + i, j, !flag)) % MOD;
            return ara1[i][j] = ans;
        }
        else
        {
            for (p = 1; p <= k2; p++)
                ans = (ans + legion(i, p + j, !flag)) % MOD;
            return ara2[i][j] = ans;
        }
    }
}

int main()
{
    int ans;

    scanf("%d %d %d %d", &n1, &n2, &k1, &k2);
    memset(ara1, -1, sizeof(ara1));
    memset(ara2, -1, sizeof(ara2));
    ans = (legion(0, 0, true) + legion(0, 0, false)) % MOD;
    printf("%d\n", ans);

    return 0;
}
