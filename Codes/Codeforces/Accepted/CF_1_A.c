#include <stdio.h>
#include <math.h>
int main()
{
    long long int n, m, a;
    double x, y;
    scanf("%I64d %I64d %I64d", &n, &m, &a);
    x = (n * 1.0) / a;
    y = (m * 1.0) / a;
    n = ceil(x);
    m = ceil(y);
    a = n * m;
    printf("%I64d", a);
    return 0;
}