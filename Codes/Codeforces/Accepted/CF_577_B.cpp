#include <bits/stdc++.h>
using namespace std;

int m, n, ara[1000006];
bool chk[1005], DP[1005][1005];

void mod_sum(int i, int j)
{
    if (i >= n || j > m)
        return;
    if (DP[i][j])
        return;
    DP[i][j] = true;

    mod_sum(i + 1, j);
    j = (j + ara[i]) % m;
    chk[j] = true;
    mod_sum(i + 1, j);
}

int main()
{
    int i, j, x;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        ara[i] = x % m;
    }
    if (n > m)
        chk[0] = true;
    else
        mod_sum(0, 0);

    if (chk[0])
        printf("YES");
    else
        printf("NO");

    return 0;
}
