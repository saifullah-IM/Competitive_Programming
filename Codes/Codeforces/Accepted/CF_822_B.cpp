#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, n, m, ans, temp;
    char str1[1005], str2[1005];
    vector<int> vec1, vec2;

    scanf("%d %d", &n, &m);
    scanf(" %[^\n]", str1);
    scanf(" %[^\n]", str2);

    ans = n;
    for (i = 1; i <= n; i++)
        vec1.push_back(i);

    for (i = 0; i < m; i++)
    {
        temp = 0;
        vec2.clear();
        for (j = 0; j < n; j++)
        {
            if (i + j >= m)
            {
                temp = 10000;
                break;
            }
            if (str2[i + j] != str1[j])
            {
                temp++;
                vec2.push_back(j + 1);
            }
        }
        if (ans > temp)
        {
            ans = temp;
            vec1 = vec2;
        }
    }

    printf("%d\n", ans);
    n = vec1.size();
    for (i = 0; i < n; i++)
    {
        m = vec1[i];
        printf("%d ", m);
    }

    return 0;
}
