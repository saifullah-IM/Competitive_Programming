#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

int tree[2100000], ara[1000006], ara2[1000006], ara3[1000006];
PII num[1000006];

bool sortfnc(PII A, PII B)
{
    if (A.first == B.first)
        return A.second < B.second;
    else
        return A.first < B.first;
}

void build(int pos, int L, int R)
{
    if (L == R)
    {
        tree[pos] = ara[L];
        return;
    }

    int mid = (L + R) / 2, x = pos * 2;
    build(x, L, mid);
    build(x + 1, mid + 1, R);
    tree[pos] = tree[x] + tree[x + 1];
}

void update(int pos, int L, int R, int node)
{
    if (L > node || node > R)
        return;
    if (L == node && R == node)
    {
        tree[pos]--;
        return;
    }

    int mid = (L + R) / 2, x = pos * 2;
    update(x, L, mid, node);
    update(x + 1, mid + 1, R, node);
    tree[pos] = tree[x] + tree[x + 1];
}

int query(int pos, int L, int R, int l, int r)
{
    if (L > r || l > R)
        return 0;
    if (L >= l && R <= r)
        return tree[pos];

    int mid = (L + R) / 2, x = pos * 2;
    int y = query(x, L, mid, l, r);
    int z = query(x + 1, mid + 1, R, l, r);

    return y + z;
}

int main()
{
    int i, j, n, x, crnt, k, mx;
    long long ans;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        num[i].first = x;
        num[i].second = i;
    }
    sort(num + 1, num + n + 1, sortfnc);

    k = 0;
    mx = -1;
    crnt = num[1].first;
    for (i = 1; i <= n; i++)
    {
        if (num[i].first == crnt)
            k++;
        else
        {
            k = 1;
            crnt = num[i].first;
        }
        j = num[i].second;
        ara2[j] = k; //cout<<j<<' '<<k<<endl;
        ara[k]++;    //cout<<k<<endl;
        mx = max(mx, k);
    }
    build(1, 1, mx);
    //cout<<mx<<' '<<tree[1]<<endl;
    k = 0;
    crnt = num[n].first;
    for (i = n; i > 0; i--)
    {
        if (num[i].first == crnt)
            k++;
        else
        {
            k = 1;
            crnt = num[i].first;
        }
        j = num[i].second;
        ara3[j] = k; //cout<<j<<' '<<ara2[j]<<endl;
    }

    ans = 0;
    for (i = n; i > 0; i--)
    {
        update(1, 1, mx, ara2[i]);               //cout<<j<<' '<<k<<endl;
                                                 // cout<<k<<' '<<mx<<endl;
        ans += query(1, 1, mx, ara3[i] + 1, mx); //cout<<j<<' '<<ans<<endl;
    }

    printf("%lld\n", ans);

    return 0;
}
