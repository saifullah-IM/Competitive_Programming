#include <stdio.h>
#include <math.h>
int main()
{
    int m, n, r;
    char S[3], T[3], p, q, R[3];
    scanf("%s", S);
    scanf("%s", T);
    m = S[0] - T[0];
    n = S[1] - T[1];

    if (m > 0)
        p = 'L';
    else if (m < 0)
        p = 'R';
    if (n > 0)
        q = 'D';
    else if (n < 0)
        q = 'U';

    m = fabs(m);
    n = fabs(n);
    R[0] = p;
    R[1] = q;
    R[2] = '\0';

    if (m || n)
    {
        r = fabs(m - n);
        if (m == n)
        {
            printf("%d\n", m);
            while (n--)
                printf("%s\n", R);
        }
        else if (m > n)
        {
            printf("%d\n", m);
            while (n--)
                printf("%s\n", R);
            while (r--)
                printf("%c\n", R[0]);
        }
        else
        {
            printf("%d\n", n);
            while (m--)
                printf("%s\n", R);
            while (r--)
                printf("%c\n", R[1]);
        }
    }

    else
    {
        if (m == 0)
            R[0] = q;
        else
            R[0] = p;
        printf("%d\n", m = m + n);
        while (m--)
            printf("%c\n", R[0]);
    }

    return 0;
}
