/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
using namespace std;

int ara[26];
int main()
{
    int i, n, k;
    char str[150];
    bool chk = true;

    scanf("%d %d", &n, &k);
    scanf("%s", str);
    for (i = 0; i < n; i++)
    {
        ara[str[i] - 'a']++;
        if (ara[str[i] - 'a'] > k)
        {
            chk = false;
            break;
        }
    }
    if (chk)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
