/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, ara[105], chk, crnt, prev, mode;

    chk = 1;
    prev = 0;
    mode = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &crnt);
        if (mode == 0 && crnt > prev)
        {
            prev = crnt;
            continue;
        }
        else if (mode == 0 && crnt == prev)
        {
            mode = 2;
            prev = crnt;
            continue;
        }
        else if (mode == 2 && crnt == prev)
            continue;
        else if (mode == 2 && crnt > prev)
        {
            chk = 0;
            prev = crnt;
            continue;
        }
        else if ((mode == 2 || mode == 0) && crnt < prev)
        {
            mode = 1;
            prev = crnt;
            continue;
        }
        else if (mode == 1 && crnt >= prev)
        {
            prev = crnt;
            chk = 0;
        }
        prev = crnt;
    }

    if (chk)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
