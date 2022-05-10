#include <bits/stdc++.h>
using namespace std;

int main()
{
    int p, x, y, ans = 0, s, i, j;
    bool flag = false;

    scanf("%d %d %d", &p, &x, &y);

    s = x;
    while (s >= y)
    {
        j = (s / 50) % 475;
        for (i = 0; i < 25; i++)
        {
            j = (j * 96 + 42) % 475;
            if (26 + j == p)
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
        s -= 50;
    }
    if (flag)
        printf("0");
    else
    {
        s = x + 50;
        while (1)
        {
            j = (s / 50) % 475;
            for (i = 0; i < 25; i++)
            {
                j = (j * 96 + 42) % 475;
                if (26 + j == p)
                {
                    flag = true;
                    ans = ceil(((s - x) * 1.0) / 100.0);
                }
            }
            if (flag)
                break;
            s += 50;
        }
        printf("%d", ans);
    }

    return 0;
}
