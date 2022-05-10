#include <bits/stdc++.h>
using namespace std;

bool chk[5000050];
int ara[5000050], sum[5000050];

void sieve()
{
    int i, j, k, x, y, z;

    for (i = 2; i <= 5000000; i++)
        if (!chk[i])
        {
            for (j = i; j <= 5000000; j += i)
            {
                x = 0;
                k = j;
                while (k % i == 0)
                {
                    x++;
                    k /= i;
                }
                chk[j] = true;
                ara[j] += x;
            }
        }

    sum[2] = ara[2];
    for (i = 3; i <= 5000000; i++)
        sum[i] = sum[i - 1] + ara[i];
}

int main()
{
    sieve();
    int i, t, n, m, k, ans;

    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        scanf("%d %d", &m, &n);
        ans = sum[m] - sum[n];
        printf("%d\n", ans);
    }

    return 0;
}
