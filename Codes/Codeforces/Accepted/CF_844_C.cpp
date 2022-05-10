/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

int parent[100005];
PII ara[100005];

bool cmp(PII A, PII B)
{
    return A.first < B.first;
}

int Find(int n)
{
    if (parent[n] == n || parent[n] == 0)
        return parent[n] = n;
    else
        return parent[n] = Find(parent[n]);
}

void Union(int u, int v)
{
    int m, n;
    m = Find(u);
    n = Find(v);
    parent[m] = n;
}

vector<int> ans[100005];
vector<int> sets;
bool chk[100005];
int main()
{
    int i, j, n, k, m, p;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &ara[i].first);
        ara[i].second = i;
    }
    sort(ara + 1, ara + n + 1, cmp);
    for (i = 1; i <= n; i++)
        Union(i, ara[i].second);
    for (i = 1; i <= n; i++)
    {
        k = Find(i);
        ans[k].push_back(i);
        if (!chk[k])
        {
            chk[k] = true;
            sets.push_back(k);
        }
    }
    k = sets.size();
    printf("%d\n", k);
    for (i = 0; i < k; i++)
    {
        m = sets[i];
        p = ans[m].size();
        printf("%d", p);
        for (j = 0; j < p; j++)
            printf(" %d", ans[m][j]);
        printf("\n");
    }

    return 0;
}
