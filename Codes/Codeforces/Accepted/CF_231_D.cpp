/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, x, y, z, x1, y1, z1, a1, a2, a3, a4, a5, a6, ans = 0;

    scanf("%d %d %d", &x, &y, &z);
    scanf("%d %d %d", &x1, &y1, &z1);
    scanf("%d %d %d %d %d %d", &a1, &a2, &a3, &a4, &a5, &a6);
    if (y < 0)
        ans += a1;
    else if (y > y1)
        ans += a2;
    if (z < 0)
        ans += a3;
    else if (z > z1)
        ans += a4;
    if (x < 0)
        ans += a5;
    else if (x > x1)
        ans += a6;

    printf("%d\n", ans);

    return 0;
}
