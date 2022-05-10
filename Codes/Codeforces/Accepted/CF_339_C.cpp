#include <bits/stdc++.h>
using namespace std;

int m;
char str[12];
vector<int> ans;

bool xenia_weights(int i, int j, int w1, int w2)
{
    if (i == m)
        return true;
    bool chk = false;

    for (int k = 0; k < 10; k++)
        if (j != k && str[k] == '1')
        {
            if (i % 2 == 0 && w1 + k + 1 > w2)
            {
                ans.push_back(k + 1);
                chk = xenia_weights(i + 1, k, w1 + k + 1, w2);
                if (chk)
                    break;
                else
                    ans.pop_back();
            }
            else if (i % 2 == 1 && w2 + k + 1 > w1)
            {
                ans.push_back(k + 1);
                chk = xenia_weights(i + 1, k, w1, w2 + k + 1);
                if (chk)
                    break;
                else
                    ans.pop_back();
            }
        }

    return chk;
}

int main()
{
    int i, n;
    bool chk;

    scanf("%s", str);
    scanf("%d", &m);
    chk = xenia_weights(0, -1, 0, 0);
    if (!chk)
        printf("NO");
    else
    {
        printf("YES\n");
        for (i = 0; i < m; i++)
        {
            n = ans[i];
            printf("%d ", n);
        }
    }

    return 0;
}
