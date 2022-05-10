/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 100005;
char str1[mx];
char str2[mx];
vector<int> divs;
int main()
{
    int i, j, n, m, k, l, r, p, root, ans = 0;

    scanf("%s", str1);
    scanf("%s", str2);
    n = strlen(str1);
    m = strlen(str2);
    root = round(sqrt(n * 1.0));
    for (i = 1; i <= root; i++)
        if (n % i == 0)
        {
            if (m % i == 0)
                divs.push_back(i);
            j = n / i;
            if (i != j && m % j == 0)
                divs.push_back(j);
        }
    sort(divs.begin(), divs.end());
    k = divs.size();
    j = 0;
    p = -1;
    for (i = 0; i < min(m, n); i++)
    {
        if (str1[i] != str2[i])
            break;
        if (i + 1 == divs[j])
        {
            l = r = -1;
            for (l = i + 1; l < n; l++)
                if (str1[l - divs[j]] != str1[l])
                    break;
            if (l == n)
                for (r = i + 1; r < m; r++)
                    if (str2[r - divs[j]] != str2[r])
                        break;
            if (l == n && r == m)
            {
                p = divs[j];
                break;
            }
            j++;
            if (j == k)
                break;
        }
    }
    if (p != -1)
        for (i = p; i <= min(m, n); i += p)
            if (n % i == 0 && m % i == 0)
                ans++;
    printf("%d\n", ans);

    return 0;
}
