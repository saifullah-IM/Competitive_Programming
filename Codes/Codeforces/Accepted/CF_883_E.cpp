/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1005;

char words[mx][55], str[55];
int cnt[mx], ltrs[28];
bool flag[mx], chk[mx][28];
vector<int> valid;

int main()
{
    int i, j, l, t, n, m, k, ans;

    scanf("%d", &n);
    scanf("%s", str);
    scanf("%d", &m);
    for (i = 0; i < m; i++)
        scanf("%s", words[i]);
    for (i = k = 0; i < n; i++)
        if (str[i] != '*')
        {
            k++;
            ltrs[str[i] - 'a'] = -1;
            for (j = 0; j < m; j++)
                if (words[j][i] == str[i])
                    cnt[j]++;
        }
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
        {
            char ch = words[i][j];
            chk[i][ch - 'a'] = true;
        }
    for (i = 0; i < m; i++)
        if (cnt[i] == k)
        {
            for (j = 0; j < n; j++)
                if (str[j] != '*')
                {
                    for (l = 0; l < n; l++)
                        if (j != l && str[j] == words[i][l] && str[l] != str[j])
                        {
                            flag[i] = true;
                            break;
                        }
                    if (flag[i])
                        break;
                }
        }
    for (i = 0; i < m; i++)
        if (!flag[i] && cnt[i] == k)
            valid.push_back(i);
    for (i = ans = 0; i < 26; i++)
        if (ltrs[i] != -1)
        {
            for (j = 0; j < valid.size(); j++)
            {
                t = valid[j];
                if (!chk[t][i])
                    break;
            }
            if (j == valid.size())
                ans++;
        }

    printf("%d\n", ans);

    return 0;
}
