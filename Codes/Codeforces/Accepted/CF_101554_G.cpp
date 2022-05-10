#include <bits/stdc++.h>
#define ll long long int
using namespace std;

char s[2][1005];

int main()
{
    int n, i;
    scanf("%d", &n);
    scanf("%s %s", s[0], s[1]);
    ///printf("%s\n%s\n",s[0],s[1]);
    if (n & 1)
    {
        for (i = 0; s[0][i] != '\0'; i++)
        {
            s[0][i] = ((!(s[0][i] - '0')) + '0');
        }
    }
    for (i = 0; s[0][i] != '\0'; i++)
    {
        if (s[0][i] != s[1][i])
        {
            printf("Deletion failed\n");
            return 0;
        }
    }
    printf("Deletion succeeded\n");
    return 0;
}
