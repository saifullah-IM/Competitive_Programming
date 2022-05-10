/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 6;
char str[mx], rev[mx];
int pi[mx], ri[mx];

void prefix_function(char ss[], int p[])
{
    int now, len;
    p[0] = now = -1;
    len = strlen(ss);

    for (int i = 1; i < len; i++)
    {
        while (now != -1 && ss[now + 1] != ss[i])
            now = p[now];
        if (ss[now + 1] == ss[i])
            p[i] = ++now;
        else
            p[i] = now = -1;
    }
}

int main()
{
    int i, n;

    scanf("%s", str);
    n = strlen(str);
    for (i = n - 1; i >= 0; i--)
        rev[n - 1 - i] = str[i];
    rev[n] = '\0';
    prefix_function(str, pi);
    prefix_function(rev, ri);

    int t, ans = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int k = n - 1 - i + pi[i]; ///cout<<k<<endl;
        if (pi[i] == ri[k] && ans < pi[i])
        {
            ans = pi[i];
            t = i;
        }
    }
    if (ans == -1)
        printf("Just a legend\n");
    else
        for (i = t - ans; i <= t; i++)
            printf("%c", str[i]);

    return 0;
}
