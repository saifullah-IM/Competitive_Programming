/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define PCI pair<char, int>
using namespace std;

int setbit(int m, int i)
{
    int mask = 1 << i;
    return mask | m;
}

int resetbit(int m, int i)
{
    int mask = 1 << i;
    mask = (~mask);
    return mask & m;
}
int ara[15];
PCI ans[4];

int main()
{
    int i, j, n, k;
    char ch;

    memset(ara, -1, sizeof(ara));
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf(" %c %d", &ch, &k);
        if (ch == '|')
        {
            for (j = 0; j < 10; j++)
            {
                if (k % 2 == 1)
                    ara[j] = 1;
                k /= 2;
            }
        }
        else if (ch == '&')
        {
            for (j = 0; j < 10; j++)
            {
                if (k % 2 == 0)
                    ara[j] = 0;
                k /= 2;
            }
        }
        else
        {
            for (j = 0; j < 10; j++)
            {
                if (k % 2 == 1)
                {
                    if (ara[j] == -1)
                        ara[j] = 2;
                    else if (ara[j] == 2)
                        ara[j] = -1;
                    else
                        ara[j] ^= 1;
                }
                k /= 2;
            }
        }
    }

    int m = 0;
    j = 0;
    for (i = 0; i < 10; i++)
        if (ara[i] == 2)
        {
            m = setbit(m, i);
        }
    if (m != 0)
        ans[j++] = make_pair('^', m);
    m = 0;
    for (i = 0; i < 10; i++)
        if (ara[i] == 1)
        {
            m = setbit(m, i);
        }
    if (m != 0)
        ans[j++] = make_pair('|', m);
    m = 1023;
    for (i = 0; i < 10; i++)
        if (ara[i] == 0)
        {
            m = resetbit(m, i);
        }
    if (m != 1023)
        ans[j++] = make_pair('&', m);

    printf("%d\n", j);
    for (i = 0; i < j; i++)
        printf("%c %d\n", ans[i].first, ans[i].second);

    return 0;
}
