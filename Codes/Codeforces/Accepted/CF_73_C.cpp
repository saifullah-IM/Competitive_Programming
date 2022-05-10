/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 102;
char str[mx];
int DP[mx][mx][27], mat[27][27], k;

int solve(int pos, int change, int last)
{
    if (str[pos] == '\0')
        return 0;
    if (change == k)
    {
        int t = last, p = pos;
        DP[pos][change][last] = 0;
        while (str[p] != '\0')
        {
            int ch = str[p] - 'a';
            DP[pos][change][last] += mat[t][ch];
            t = ch;
            p++;
        }
        return DP[pos][change][last];
    }
    if (DP[pos][change][last] != -1)
        return DP[pos][change][last];

    int temp, ch, i;
    ch = str[pos] - 'a';

    DP[pos][change][last] = mat[last][ch] + solve(pos + 1, change, ch);
    for (i = 0; i < 26; i++)
        if (i != ch)
        {
            temp = mat[last][i] + solve(pos + 1, change + 1, i);
            DP[pos][change][last] = max(temp, DP[pos][change][last]);
        }
    return DP[pos][change][last];
}

int main()
{
    int i, m, C, ans;
    char c1, c2;

    scanf("%s %d", str, &k);
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        scanf(" %c %c %d", &c1, &c2, &C);
        mat[c1 - 'a'][c2 - 'a'] = C;
    }
    memset(DP, -1, sizeof(DP));
    ans = solve(0, 0, 26);
    printf("%d\n", ans);

    return 0;
}
