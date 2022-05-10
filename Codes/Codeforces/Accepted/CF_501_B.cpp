#include <bits/stdc++.h>
using namespace std;

int ara[2005], ans[2005], ANS;

int Find(int u)
{
    if (ara[u] == u)
        return u;
    else
        return ara[u] = Find(ara[u]);
}

void Union(int u, int v)
{
    int m, n;

    m = Find(u);
    n = Find(v);
    ara[n] = m;

    if (ans[m] == -1)
        ANS++;
    ans[m] = v;
}

int main()
{
    int i, j, n, q, u, v;
    string S1, S2;
    map<string, int> map1;
    map<int, string> map2;

    j = 0;
    scanf("%d", &q);
    memset(ans, -1, sizeof(ans));
    for (i = 0; i <= 2 * q; i++)
        ara[i] = i;
    for (i = 0; i < q; i++)
    {
        cin >> S1 >> S2;
        if (map1.count(S1) == 0)
            map1[S1] = j++;
        if (map1.count(S2) == 0)
            map1[S2] = j++;
        u = map1[S1];
        v = map1[S2];
        map2[u] = S1;
        map2[v] = S2;
        Union(u, v);
    }

    printf("%d\n", ANS);
    for (i = 0; i < j; i++)
        if (ans[i] != -1)
        {
            cout << map2[i] << ' ' << map2[ans[i]] << endl;
        }

    return 0;
}
