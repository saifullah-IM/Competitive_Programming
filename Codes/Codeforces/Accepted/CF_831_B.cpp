/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, x, y, z, ara1[26], ara2[26];
    string a, b, c, ans;
    char ch;

    cin >> a >> b >> c;
    for (i = 0; i < 26; i++)
        ara1[a[i] - 'a'] = i;
    x = c.size();
    ans.clear();
    for (i = 0; i < x; i++)
    {
        ch = c[i];
        if (ch <= 'Z' && ch >= 'A')
        {
            ch = ch - 'A' + 'a';
            y = ara1[ch - 'a'];
            ch = b[y] - 'a' + 'A';
            ans += ch;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            y = ara1[ch - 'a'];
            ans += b[y];
        }
        else
            ans += ch;
    }
    cout << ans;

    return 0;
}
