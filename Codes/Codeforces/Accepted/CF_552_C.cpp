#include <bits/stdc++.h>
using namespace std;

int w;
bool chk[101];

bool is_possible(long long m)
{
    int i;
    long long u;
    bool ans;

    u = 1;
    i = 0;
    while (u < m)
    {
        i++;
        u *= w;
    }
    if (u == m)
    {
        if (!chk[i])
            return true;
        else
            return false;
    }
    else
    {
        ans = false;
        if (!chk[i])
        {
            chk[i] = true;
            ans = ans | is_possible(u - m);
            chk[i] = false;
            if (ans)
                return true;
        }

        if (!chk[i - 1])
        {
            chk[i - 1] = true;
            u /= w;
            ans = ans | is_possible(m + u);
            if (ans)
                return true;
            ans = ans | is_possible(m - u);
            if (ans)
                return true;
            chk[i - 1] = false;
        }
    }

    return false;
}

int main()
{
    int i, m;
    bool ans;

    scanf("%d %d", &w, &m);
    ans = is_possible(m);
    if (ans)
        printf("YES");
    else
        printf("NO");

    return 0;
}
