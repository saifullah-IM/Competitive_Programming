#include <bits/stdc++.h>
using namespace std;

char s1[100005], s2[100005];

int main()
{
    int n, m, l, r, i, j, keep;
    scanf("%s %s", &s1, &s2);
    n = strlen(s1);
    m = strlen(s2);
    for (i = 0, j = 0; j < m && i < n; j++, i++)
    {
        if (s1[i] != s2[j])
            break;
    }
    l = j;
    keep = i;
    for (j = m - 1, i = n - 1; j >= l && i >= keep; i--, j--)
    {
        if (s1[i] != s2[j])
            break;
    }
    r = j;
    printf("%d\n", r - l + 1);
    return 0;
}
