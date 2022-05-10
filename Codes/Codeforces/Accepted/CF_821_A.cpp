#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k, l, n, ara[55][55], x, y, z;
    bool temp;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &ara[i][j]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (ara[i][j] != 1)
            {
                x = ara[i][j];
                temp = false;
                for (k = 0; k < n; k++)
                    for (l = 0; l < n; l++)
                    {
                        if (ara[k][j] + ara[i][l] == x)
                        {
                            temp = true;
                            break;
                        }
                    }
                if (!temp)
                {
                    cout << "No";
                    return 0;
                }
            }
    cout << "Yes";

    return 0;
}
