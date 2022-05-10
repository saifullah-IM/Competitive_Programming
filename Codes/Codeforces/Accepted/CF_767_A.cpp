#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n, snack[100000];
    bool check[100000];
    memset(check, 0, sizeof(check));

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &snack[i]);
    for (i = 0, j = n; i < n; i++)
    {
        check[snack[i] - 1] = true;
        while (check[j - 1])
        {
            printf("%d ", j);
            j--;
            if (j == 0)
                break;
        }
        printf("\n");
    }

    return 0;
}
