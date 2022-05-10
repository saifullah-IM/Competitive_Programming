#include <stdio.h>
#include <math.h>
int main()
{
    int n, i, x = 0, y = 0, z = 0, taxi = 0;
    scanf("%d", &n);
    int S[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &S[i]);
        if (S[i] == 3 || S[i] == 4)
            taxi++;
        if (S[i] == 1)
            x++;
        if (S[i] == 2)
            y++;
        else if (S[i] == 3)
            z++;
    }
    if (z >= x && z != 0)
    {
        taxi += ceil(y / 2.0);
        printf("%d", taxi);
    }
    else
    {
        taxi += (x - z) / 4 + (y / 2);
        y = (y % 2) * 2;
        x = (x - z) % 4;
        taxi += ceil((x + y) / 4.0);
        printf("%d", taxi);
    }
    return 0;
}
