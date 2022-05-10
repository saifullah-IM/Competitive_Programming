/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int sz = 320;
const int mx = 100005;
int cnt[mx], ara[mx], l = 0, r = -1;
int sum, ans[mx];

struct query
{
    int l, r, id;
};
bool cmp(query A, query B)
{
    int l1, l2;
    l1 = A.l / sz;
    l2 = B.l / sz;
    if (l1 == l2)
        return A.r < B.r;
    return l1 < l2;
}
query Q[mx];

void add(int x)
{
    if (ara[x] >= mx)
        return;
    if (cnt[ara[x]] == ara[x])
        sum--;
    cnt[ara[x]]++;
    if (cnt[ara[x]] == ara[x])
        sum++;
}

void remove(int x)
{
    if (ara[x] >= mx)
        return;
    if (cnt[ara[x]] == ara[x])
        sum--;
    cnt[ara[x]]--;
    if (cnt[ara[x]] == ara[x])
        sum++;
}

int main()
{
    int i, n, t;

    scanf("%d %d", &n, &t);
    for (i = 0; i < n; i++)
        scanf("%d", &ara[i]);
    for (i = 0; i < t; i++)
    {
        scanf("%d %d", &Q[i].l, &Q[i].r);
        Q[i].l--;
        Q[i].r--;
        Q[i].id = i;
    }
    sort(Q, Q + t, cmp);

    for (i = 0; i < t; i++)
    {
        while (l > Q[i].l)
            add(--l);
        while (r < Q[i].r)
            add(++r);
        while (l < Q[i].l)
            remove(l++);
        while (r > Q[i].r)
            remove(r--);
        ans[Q[i].id] = sum;
    }

    for (i = 0; i < t; i++)
        printf("%d\n", ans[i]);

    return 0;
}
