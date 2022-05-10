/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
using namespace std;

int ara[1000006];
int main()
{
    int i, n;
    long long sum;
    bool chk = false;

    sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ara[i]);
        sum += ara[i];
        if (ara[i] % 2)
            chk = true;
    }

    if (chk || sum % 2)
        cout << "First";
    else
        cout << "Second";
    return 0;
}
