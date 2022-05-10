/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define EPS 1e-19
#define ll long long
#define ld long double
#define PLD pair<ld, ld>
using namespace std;

PLD solve(ld x1, ld y1, ld x2, ld y2)
{
    ld mx = (ld)-1e60;
    ld mn = (ld)1e60;

    mn = min(mn, x1 * x2);
    mn = min(mn, x1 * y2);
    mn = min(mn, y1 * x2);
    mn = min(mn, y1 * y2);
    mx = max(mx, x1 * x2);
    mx = max(mx, x1 * y2);
    mx = max(mx, y1 * x2);
    mx = max(mx, y1 * y2);

    return make_pair(mx, mn);
}

ld mat[3][3];
bool check(ld ans)
{
    PLD A, B;
    A = solve(mat[0][0] + ans, mat[0][0] - ans, mat[1][1] + ans, mat[1][1] - ans);
    B = solve(mat[0][1] + ans, mat[0][1] - ans, mat[1][0] + ans, mat[1][0] - ans);
    return (min(A.first, B.first) >= max(A.second, B.second) - EPS);
}

int main()
{
    int i, j, x;
    ld ans, hi, lo;

    hi = (ld)INT_MIN;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &x);
            mat[i][j] = (ld)x;
            hi = max(hi, fabs(mat[i][j]));
        }

    x = 500;
    lo = 0.0;
    while (x--)
    {
        ans = (lo + hi) / 2.0;
        if (check(ans))
            hi = ans;
        else
            lo = ans;
    }
    printf("%0.12Lf\n", ans);

    return 0;
}
