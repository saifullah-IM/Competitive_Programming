/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
using namespace std;

int c, tree[15][260][260];

void update_y(int k, int px, int X1, int X2, int x, int py, int Y1, int Y2, int y, int s)
{
    if (Y1 > y || Y2 < y)
        return;
    if (Y1 == Y2)
    {
        if (X1 == X2)
            tree[k][px][py] += (s + k) % c;
        else
            tree[k][px][py] = tree[k][px * 2][py] + tree[k][px * 2 + 1][py];
        return;
    }

    int Py, midY;
    Py = py * 2;
    midY = (Y1 + Y2) / 2;
    update_y(k, px, X1, X2, x, Py, Y1, midY, y, s);
    update_y(k, px, X1, X2, x, Py + 1, midY + 1, Y2, y, s);
    tree[k][px][py] = tree[k][px][Py] + tree[k][px][Py + 1];
}

void update_x(int k, int px, int X1, int X2, int x, int y, int s)
{
    if (X1 > x || X2 < x)
        return;
    if (X1 != X2)
    {
        int Px, midX;
        Px = px * 2;
        midX = (X1 + X2) / 2;
        update_x(k, Px, X1, midX, x, y, s);
        update_x(k, Px + 1, midX + 1, X2, x, y, s);
    }

    update_y(k, px, X1, X2, x, 1, 1, 100, y, s);
}

int query_y(int k, int px, int py, int Y1, int Y2, int y1, int y2)
{
    if (Y1 > y2 || Y2 < y1)
        return 0;
    if (Y1 >= y1 && Y2 <= y2)
        return tree[k][px][py];

    int Py, midY, ans;
    Py = py * 2;
    midY = (Y1 + Y2) / 2;
    ans = 0;

    ans += query_y(k, px, Py, Y1, midY, y1, y2);
    ans += query_y(k, px, Py + 1, midY + 1, Y2, y1, y2);
    return ans;
}

int query_x(int k, int px, int X1, int X2, int x1, int y1, int x2, int y2)
{
    if (X1 > x2 || X2 < x1)
        return 0;
    if (X1 >= x1 && X2 <= x2)
        return query_y(k, px, 1, 1, 100, y1, y2);

    int Px, midX, ans;
    Px = px * 2;
    midX = (X1 + X2) / 2;
    ans = 0;
    ans += query_x(k, Px, X1, midX, x1, y1, x2, y2);
    ans += query_x(k, Px + 1, midX + 1, X2, x1, y1, x2, y2);
    return ans;
}

int main()
{
    int i, j, ans, n, q, x, y, s, t, x1, y1;

    scanf("%d %d %d", &n, &q, &c);
    c++;

    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &x, &y, &s);
        for (j = 0; j < c; j++)
            update_x(j, 1, 1, 100, x, y, s);
    }
    for (i = 0; i < q; i++)
    {
        scanf("%d %d %d %d %d", &t, &x, &y, &x1, &y1);
        t %= c;
        ans = query_x(t, 1, 1, 100, x, y, x1, y1);
        printf("%d\n", ans);
    }

    return 0;
}
