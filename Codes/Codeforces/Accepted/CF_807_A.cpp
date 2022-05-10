#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, ara1[1005], ara2[1005], n, ck, temp;
    ck = 0;
    temp = 5000;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &ara1[i], &ara2[i]);
        if (ara1[i] != ara2[i])
            ck = 1;
        if (ck == 0 && temp < ara1[i])
            ck = 2;
        temp = ara1[i];
    }

    if (ck == 2)
        printf("unrated");
    else if (ck == 1)
        printf("rated");
    else
        printf("maybe");

    return 0;
}
