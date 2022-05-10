/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

int ara[27];
int main()
{
    int i, n, k, m;
    char str[1005];

    scanf("%s", &str);
    scanf("%d", &k);
    n = strlen(str);

    if (k > n)
        cout << "impossible";
    else
    {
        for (i = 0; i < n; i++)
            ara[str[i] - 'a'] = 1;
        m = 0;
        for (i = 0; i < 26; i++)
            m += ara[i];
        cout << max(k - m, 0);
    }

    return 0;
}
