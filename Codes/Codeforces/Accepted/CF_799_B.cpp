#include <bits/stdc++.h>
using namespace std;

struct info
{
    int p, i;
};

struct compare
{
    bool operator()(info A, info B)
    {
        return A.p > B.p;
    }
};

int main()
{
    bool isSold[200005];
    priority_queue<info, vector<info>, compare> shirt[4];
    int n, p, a, i, m, prices[200005];
    info A;

    memset(isSold, 0, sizeof(isSold));
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &prices[i]);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        A.i = i;
        A.p = prices[i];
        shirt[a].push(A);
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a);
        A.i = i;
        A.p = prices[i];
        shirt[a].push(A);
    }

    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &a);
        while (1)
        {
            if (shirt[a].empty())
            {
                printf("-1 ");
                break;
            }
            A = shirt[a].top();
            if (!isSold[A.i])
            {
                printf("%d ", A.p);
                isSold[A.i] = true;
                break;
            }
            else
                shirt[a].pop();
        }
    }

    return 0;
}
