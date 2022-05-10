#include <bits/stdc++.h>
using namespace std;

int main()
{
    int first, second, n, i, x1, x2, ara1[200005], ara2[200005];
    map<int, int> mymap;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &x1, &x2);
        mymap[x1] = x2;
        ara1[i] = x1;
        ara2[i] = x2;
    }

    sort(ara2, ara2 + n);
    for (i = 0; i < n; i++)
    {
        if (!binary_search(ara2, ara2 + n, ara1[i]))
        {
            first = ara1[i];
            break;
        }
    }

    second = mymap[0];
    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d ", first);
            first = mymap[first];
        }
        else
        {
            printf("%d ", second);
            second = mymap[second];
        }
    }

    return 0;
}
