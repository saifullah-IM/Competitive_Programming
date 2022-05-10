/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;
bitset<mx> xx[27], ans, one;
char str[mx], ss[mx];
int main()
{
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0; i < n; i++)
        one[i] = 1;
    for (int i = 0; i < n; i++)
        xx[str[i] - 'a'][i] = 1;
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int k, l, r;
        scanf("%d", &k);
        if (k == 1)
        {
            char ch;
            scanf("%d %ch", &l, &ch);
            l--;
            xx[str[l] - 'a'][l] = 0;
            xx[ch - 'a'][l] = 1;
            str[l] = ch;
        }
        else
        {
            scanf("%d %d %s", &l, &r, ss);
            int m = strlen(ss);
            if (m > r - l + 1)
            {
                printf("0\n");
                continue;
            }
            ans = one;
            for (int i = 0; i < m; i++)
                ans &= (xx[ss[i] - 'a'] >> i);
            int res = (ans >> (l - 1)).count() - (ans >> (r - m + 1)).count();
            printf("%d\n", res);
        }
    }

    return 0;
}
