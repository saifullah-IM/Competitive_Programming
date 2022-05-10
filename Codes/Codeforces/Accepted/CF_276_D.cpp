#include <bits/stdc++.h>
#define ULL unsigned long long
using namespace std;

ULL setbit(ULL m, int i)
{
    ULL mask = 1;
    mask = mask << i;
    return mask | m;
}

ULL resetbit(ULL m, int i)
{
    ULL mask = 1;
    mask = mask << i;
    mask = (~mask);
    return mask & m;
}

int main()
{
    int i, k, l, ara1[65], ara2[65];
    ULL m, n, u, v, w, ans;

    scanf("%llu %llu", &v, &u);
    m = u;
    n = v;

    ans = i = 0;
    while (m >= 1 || n >= 1)
    {
        ara1[i] = m % 2;
        ara2[i] = n % 2;
        m /= 2;
        n /= 2;
        i++;
    }

    i--;
    while (i >= 0)
    {
        ans = (ans << 1);
        if (ara1[i] ^ ara2[i] == 1)
            ans = (ans | 1);
        else if (ara1[i] == 1)
        {
            w = resetbit(u, i);
            if (w >= v)
                ans = (ans | 1);
        }
        else
        {
            w = setbit(v, i);
            if (w <= u)
                ans = (ans | 1);
        }
        i--;
    }
    printf("%llu", ans);

    return 0;
}
