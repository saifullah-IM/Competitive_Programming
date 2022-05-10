#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, m, ans, k;
    char str[300005], ch;

    scanf("%d %d", &n, &m);
    scanf("%s", str);
    ans = k = 0;
    for (i = 0; i <= n; i++)
    {
        if (str[i] == '.')
            k++;
        else
        {
            if (k != 0)
                ans += k - 1;
            k = 0;
        }
    }

    if (n == 1)
    {
        for (i = 0; i < m; i++)
            printf("0\n");
    }
    else
    {
        for (i = 0; i < m; i++)
        {
            scanf("%d %c", &k, &ch);
            if (ch == '.' && str[k - 1] != '.')
            {
                str[k - 1] = '.';
                if ((k == 1 && str[1] == '.') || (k == n && str[n - 2] == '.'))
                    ans += 1;
                else if (k == 1 || k == n)
                    ;
                else if (str[k] == '.' && str[k - 2] == '.')
                    ans += 2;
                else if (str[k] == '.' || str[k - 2] == '.')
                    ans += 1;
            }
            else if (ch != '.' && str[k - 1] == '.')
            {
                str[k - 1] = ch;
                if ((k == 1 && str[1] == '.') || (k == n && str[n - 2] == '.'))
                    ans -= 1;
                else if (k == 1 || k == n)
                    ;
                else if (str[k] == '.' && str[k - 2] == '.')
                    ans -= 2;
                else if (str[k] == '.' || str[k - 2] == '.')
                    ans -= 1;
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}
