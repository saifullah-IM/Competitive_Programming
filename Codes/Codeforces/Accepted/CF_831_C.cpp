/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, l, n, k, m, ara1[2005], ara2[2005], ara3[2005], sum, x, crnt, prev;
    set<int> myset;

    sum = 0;
    scanf("%d %d", &k, &n);
    for (i = 0; i < k; i++)
    {
        scanf("%d", &x);
        sum += x;
        ara1[i] = sum;
    }

    for (i = 0; i < n; i++)
        scanf("%d", &ara2[i]);
    sort(ara1, ara1 + k);
    sort(ara2, ara2 + n);
    myset.clear();
    m = k - n + 1;

    for (i = 0; i < m; i++)
    {
        x = ara1[i] - ara2[0];
        l = 0;
        bool chk = false;
        for (j = 0; j < k && l < n; j++)
        {
            if (x + ara2[l] == ara1[j])
            {
                l++;
                continue;
            }
            else
            {
                chk = true;
                while (++j < k)
                {
                    if (x + ara2[l] == ara1[j])
                    {
                        l++;
                        chk = false;
                        break;
                    }
                    else if (x + ara2[l] < ara1[j])
                        break;
                }
            }

            if (chk)
                break;
        }

        if (!chk)
            myset.insert(x);
    }

    cout << myset.size();

    return 0;
}
