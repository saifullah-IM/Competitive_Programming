#include <bits/stdc++.h>
using namespace std;

char str[10000007];
int path[10000007];

int Find(int n)
{
    if (path[n] == 0 || path[n] == n)
        return path[n] = n;
    else
        return path[n] = Find(path[n]);
}

void Union(int a, int b)
{
    int m, n, k;

    m = Find(a);
    n = Find(b);
    k = max(m, n);

    path[n] = path[m] = k;
}

int main()
{
    int i, j, l, z, n, x, k, t, mx;
    string S;

    mx = -1;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        cin >> S;
        x = S.size();
        scanf("%d", &k);
        for (j = 0; j < k; j++)
        {
            scanf("%d", &t);
            t -= 1;
            l = Find(t);
            Union(t, t + x);
            while (1)
            {
                if (l >= t + x)
                    break;
                Union(l, t + x);
                str[l] = S[l - t];
                l = Find(l + 1);
            }
            mx = max(mx, t + x);
        }
    }

    if (str[0] == 0)
        str[0] = 'a';
    i = Find(1);
    while (i < mx)
    {
        str[i] = 'a';
        i = Find(i + 1);
    }
    str[mx] = '\0';
    cout << str;

    return 0;
}