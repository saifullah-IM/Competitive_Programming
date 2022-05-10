/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
#define PII pair<int, int>
using namespace std;

const int mx = 1e5 + 5;
PII tree[3 * mx];
int DP[mx], path[mx], rev[mx];
ll ara[mx], num[mx];
pair<ll, int> temp[mx];

void update(int pos, int L, int R, int node, int val)
{
    if (L > node || R < node)
        return;
    if (L == R && L == node)
    {
        tree[pos].first = val;
        tree[pos].second = L;
        return;
    }
    int mid = (L + R) / 2;
    int x = pos * 2;
    update(x, L, mid, node, val);
    update(x + 1, mid + 1, R, node, val);
    if (tree[x].first > tree[x + 1].first)
        tree[pos] = tree[x];
    else
        tree[pos] = tree[x + 1];
}

PII query(int pos, int L, int R, int l, int r)
{ //if (l==2) cout<<pos<<endl;
    if (L > r || l > R)
        return make_pair(0, 0);
    if (l <= L && R <= r)
        return tree[pos];
    int mid = (L + R) / 2, x = pos * 2;
    PII y = query(x, L, mid, l, r);
    PII z = query(x + 1, mid + 1, R, l, r);
    return max(y, z);
}

int main()
{
    int i, n, d;
    PII ans = make_pair(-1, -1);

    scanf("%d %d", &n, &d);
    for (i = 0; i < n; i++)
    {
        scanf("%lld", &ara[i]);
        temp[i].first = ara[i];
        temp[i].second = i;
    }
    sort(temp, temp + n);
    for (i = 0; i < n; i++)
    {
        rev[temp[i].second] = i;
        num[i] = temp[i].first;
    }
    for (i = n; i > 0; i--)
    { ///cout<<i<<endl;
        ll h1 = ara[i - 1] + d, h2 = ara[i - 1] - d;
        int x = lower_bound(num, num + n, h1) - num;
        int y = upper_bound(num, num + n, h2) - num; ///cout<<x<<' '<<y<<endl;
        PII A = query(1, 1, n, x + 1, n);            ///cout<<x<<' '<<y<<endl;
        PII B = query(1, 1, n, 1, y);
        A = max(A, B);
        DP[i] = 1 + A.first;
        if (A.second > 0)
            path[i] = temp[A.second - 1].second + 1;
        else
            path[i] = -1; ///cout<<i<<' '<<path[i]<<' '<<A.second<<endl;
        update(1, 1, n, rev[i - 1] + 1, DP[i]);
        ans = max(ans, make_pair(DP[i], i)); ///cout<<DP[i]<<'d'<<endl;
    }
    printf("%d\n", ans.first);
    int u = ans.second;
    while (u != -1)
    {
        printf("%d ", u);
        u = path[u];
    }

    return 0;
}
