/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

bool mysort(PII A, PII B)
{
    return A.first < B.first;
}
bool mysort2(PII A, PII B)
{
    return A.first > B.first;
}

PII ara1[200005];
PII ara2[200005];
int ans[200005];
int main()
{
    int i, n;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ara1[i].first);
        ara1[i].second = i;
    }
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ara2[i].first);
        ara2[i].second = i;
    }
    sort(ara1, ara1 + n, mysort2);
    sort(ara2, ara2 + n, mysort);
    for (i = 0; i < n; i++)
        ans[ara2[i].second] = ara1[i].first;
    for (i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}
