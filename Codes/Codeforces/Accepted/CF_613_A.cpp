/* Bismillahir Rahmanir Rahim */

#include <bits/stdc++.h>
#define EPS 0.0000000001
#define PI 2.0 * acos(0.0)
#define inf 1000000000.0
using namespace std;

struct point
{
    double x, y;
};

struct vec
{
    double x, y;
};

double norm_sq(vec a)
{
    return a.x * a.x + a.y * a.y;
}

double dot(vec a, vec b)
{
    return a.x * b.x + a.y * b.y;
}

point translate(vec a, point p)
{
    point P;
    P.x = a.x + p.x * 1.0, P.y = a.y + p.y * 1.0;
    return P;
}

vec tovec(point a, point b)
{
    vec V;
    V.x = (b.x - a.x) * 1.0, V.y = (b.y - a.y) * 1.0;
    return V;
}

vec scalar(vec a, double u)
{
    vec V;
    V.x = u * a.x, V.y = u * a.y;
    return V;
}

double distToline(point a, point b, point p)
{
    double u, t, d;
    vec ap = tovec(a, p);
    vec ab = tovec(a, b);

    u = dot(ap, ab);
    u /= norm_sq(ab);
    point c = translate(scalar(ab, u), a);
    t = (c.x - p.x) * 1.0;
    d = t * t;
    t = (c.y - p.y) * 1.0;
    d += t * t;
    d = sqrt(d);
    return d;
}

double distToseg(point a, point b, point p)
{
    double u, t, d;
    vec ap = tovec(a, p);
    vec ab = tovec(a, b);
    point c;

    u = dot(ap, ab);
    u /= norm_sq(ab);
    if (u > 1.0)
    {
        c = b;
        t = (c.x - p.x) * 1.0;
        d = t * t;
        t = (c.y - p.y) * 1.0;
        d += t * t;
        d = sqrt(d);
        return d;
    }
    else if (u < 0.0)
    {
        c = a;
        t = (c.x - p.x) * 1.0;
        d = t * t;
        t = (c.y - p.y) * 1.0;
        d += t * t;
        d = sqrt(d);
        return d;
    }
    else
        return distToline(a, b, p);
}

int main()
{
    long long n, x, y, x1, y1;
    double maxi, mini, area, d, t;
    point p1, p2, p, q;

    scanf("%lld %lld %lld", &n, &x, &y);
    scanf("%lld %lld", &x1, &y1);
    t = (x - x1) * 1.0;
    d = t * t;
    t = (y - y1) * 1.0;
    d += t * t;
    d = sqrt(d);
    maxi = d;
    p.x = x * 1.0, p.y = y * 1.0;
    p1.x = x1 * 1.0, p1.y = y1 * 1.0;
    q = p1;
    mini = inf;

    for (int i = 1; i < n; i++)
    {
        scanf("%lld %lld", &x1, &y1);
        t = (x - x1) * 1.0;
        d = t * t;
        t = (y - y1) * 1.0;
        d += t * t;
        d = sqrt(d);
        maxi = max(maxi, d);

        p2.x = x1 * 1.0, p2.y = y1 * 1.0;
        t = distToseg(p1, p2, p);
        mini = min(mini, t);
        p1 = p2;
    }

    t = distToseg(q, p2, p);
    mini = min(mini, t);
    area = PI * (maxi + mini) * (maxi - mini);
    printf("%0.10lf", area);

    return 0;
}
