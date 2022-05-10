#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, k, x = 0, ln, ans = 0;
    char num[11];

    scanf("%[0-9]", num);
    scanf("%d", &k);
    ln = strlen(num);

    for (i = ln - 1; i >= 0; i--)
    {
        if (num[i] == '0')
            x++;
        else
            ans++;

        if (x == k)
            break;
    }

    if (x == k)
        printf("%d", ans);
    else
        printf("%d", ln - 1);

    return 0;
}
