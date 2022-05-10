#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, x, y, z;
    double p, q;

    scanf("%d %d", &a, &b);
    p = sqrt(a * 1.0);
    q = (-1.0 + sqrt(1 + 4.0 * b)) / 2.0;
    x = floor(p);
    y = floor(q);
    if (y >= x)
        printf("Vladik");
    else
        printf("Valera");

    return 0;
}
