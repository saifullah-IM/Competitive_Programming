#include <bits/stdc++.h>
using namespace std;

char str[2005];
short int is_p[2005][2005];
long long pals[2005];

int check_pal(int i, int j)
{
    if (i >= j)
        return is_p[i][j] = 1;
    if (str[i] != str[j])
        return is_p[i][j] = 0;
    if (is_p[i][j] != -1)
        return is_p[i][j];

    return is_p[i][j] = check_pal(i + 1, j - 1);
}

int main()
{
    int i, j, n;
    long long ans;

    scanf("%s", str);
    n = strlen(str);
    memset(is_p, -1, sizeof(is_p));
    for (i = n - 1; i >= 0; i--)
    {
        for (j = i; j < n; j++)
            pals[i] += check_pal(i, j);
        pals[i] += pals[i + 1];
    }

    ans = 0;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
        {
            if (is_p[i][j] == 1)
            {
                ans += pals[j + 1];
            }
        }

    printf("%lld", ans);

    return 0;
}
