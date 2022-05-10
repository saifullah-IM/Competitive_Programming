/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
using namespace std;

class info
{
public:
    int len, a, b;

    info operator+(info B)
    {
        info A;
        int t;

        t = min(this->a, B.b);
        A.len = this->len + B.len + t;
        A.a = this->a + B.a - t;
        A.b = this->b + B.b - t;

        return A;
    }
};

char bracket[1000006];
info tree[2100000];

void build(int pos, int L, int R)
{
    if (L == R)
    {
        if (bracket[L - 1] == '(')
        {
            tree[pos].len = tree[pos].b = 0;
            tree[pos].a = 1;
        }
        else
        {
            tree[pos].len = tree[pos].a = 0;
            tree[pos].b = 1;
        }
        return;
    }

    int x = pos * 2, mid = (L + R) / 2;
    build(x, L, mid);
    build(x + 1, mid + 1, R);
    tree[pos] = tree[x] + tree[x + 1];
}

info query(int pos, int L, int R, int l, int r)
{
    info A, B;

    if (L > r || R < l)
    {
        A.a = A.b = A.len = 0;
        return A;
    }
    if (L >= l && R <= r)
        return tree[pos];

    int x = pos * 2, mid = (L + R) / 2;
    A = query(x, L, mid, l, r);
    B = query(x + 1, mid + 1, R, l, r);
    return A + B;
}

int main()
{
    int i, n, m, l, r;
    info A;

    scanf("%s", bracket);
    n = strlen(bracket);
    build(1, 1, n);

    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &l, &r);
        A = query(1, 1, n, l, r);
        printf("%d\n", A.len * 2);
    }

    return 0;
}
