#include <bits/stdc++.h>
using namespace std;

int ara[100001];
long long sum[263000];

void init(int pos, int L, int R)
{
    if (L == R)
    {
        sum[pos] = ara[L];
        return;
    }

    int mid = (L + R) / 2, x = pos * 2;
    init(x, L, mid);
    init(x + 1, mid + 1, R);
    sum[pos] = sum[x] + sum[x + 1];
}

long long query(int pos, int L, int R, int l, int r)
{
    if (l > R || r < L)
        return 0;
    if (l <= L && r >= R)
        return sum[pos];

    int mid = (L + R) / 2;
    long long x = query(pos * 2, L, mid, l, r);
    long long y = query(pos * 2 + 1, mid + 1, R, l, r);

    return x + y;
}

struct cmp
{
    bool operator()(long long a, long long b)
    {
        return a > b;
    }
};

int main()
{
    int i, n, u, v, d;
    long long ans, temp;
    set<int> myset;
    set<int>::iterator it;
    set<int>::iterator IT;
    multiset<long long, cmp> myans;
    multiset<long long>::iterator iT;

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%d", &ara[i]);
    init(1, 1, n);
    myans.insert(sum[1]);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &d);
        myset.insert(d);
        it = myset.find(d);
        if (it == myset.begin())
            u = 1;
        else
        {
            IT = it;
            IT--;
            u = *IT + 1;
        }
        IT = it;
        IT++;
        if (IT == myset.end())
            v = n;
        else
            v = *IT - 1;

        temp = query(1, 1, n, u, v);
        iT = myans.find(temp);
        myans.erase(iT);
        temp = query(1, 1, n, u, d - 1);
        myans.insert(temp);
        temp = query(1, 1, n, d + 1, v);
        myans.insert(temp);

        ans = *(myans.begin());
        printf("%lld\n", ans);
    }

    return 0;
}
