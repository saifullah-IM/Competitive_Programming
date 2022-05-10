#include <bits/stdc++.h>
using namespace std;

int n;
int nex[300005];
int ans[300005];
int getnext(int l)
{
    if (nex[l] == l)
        return l;
    else
        return nex[l] = getnext(nex[l]);
}

int update(int l, int r, int x)
{
    int cur = getnext(l);
    while (cur <= r)
    {
        if (cur == x)
            cur++;
        else
        {
            ans[cur] = x;
            nex[cur] = cur + 1;
        }
        cur = getnext(cur);
        if (cur == 0)
            break;
    }
}

int main()
{
    int i, m, l, r, x;

    scanf("%d %d", &n, &m);
    for (i = 1; i <= n; i++)
        nex[i] = i;
    while (m--)
    {
        scanf("%d %d %d", &l, &r, &x);
        update(l, r, x);
    }
    for (i = 1; i <= n; i++)
        printf("%d ", ans[i]);

    return 0;
}
