#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j = 1, len;
    string str;
    char ch;
    cin >> str;
    len = str.size();

    if (str[0] == 'a')
    {
        for (i = 1; i < len; i++)
        {
            ch = 'a' + j;
            if (str[i] <= ch)
            {
                if (str[i] == ch)
                    j++;
                continue;
            }
            else
                break;
        }
        if (i == len)
            cout << "YES";
        else
            cout << "NO";
    }
    else
        cout << "NO";

    return 0;
}
