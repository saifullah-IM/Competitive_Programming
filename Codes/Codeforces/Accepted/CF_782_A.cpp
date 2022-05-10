#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, m, n, k, maxx = 0, current = 0;
    bool ara[100001];
    memset(ara, 0, sizeof(ara));

    scanf("%d", &n);
    m = 2 * n;
    for (i = 0; i < m; i++)
    {
        scanf("%d", &k);
        if (!ara[k])
        {
            ara[k] = true;
            current++;
        }
        else
        {
            ara[k] = false;
            current--;
        }

        if (maxx < current)
            maxx = current;
    }
    printf("%d\n", maxx);

    return 0;
}
