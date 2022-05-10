#include <bits/stdc++.h>

int main()
{
    long long int m, n, a, rslt;

    scanf("%lld %lld %lld", &m, &n, &a);
    rslt = (ceil((double)m / a)) * (ceil((double)n / a));
    printf("%lld", rslt);

    return 0;
}
