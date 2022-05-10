#include <stdio.h>

int main()
{
    int a, b, c, p, q, n;
    scanf("%d", &n);

    a = n / 1234567;
    while (a >= 0)
    {
        p = n - (1234567 * a);
        if (p % 2 == 0)
        {
            q = p / 2;
            b = -22 * q;
            b = ((b % 617) + 617) % 617;
            c = (q - b * 61728) / 617;
            if (c >= 0)
            {
                printf("YES");
                break;
            }
        }
        if (a == 0)
            printf("NO");
        a--;
    }

    return 0;
}
