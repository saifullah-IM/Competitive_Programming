#include <stdio.h>
#include <string.h>
#define MAX(a, b) (a > b ? a : b)

int main()
{
    int i, ln1, ln2, x, z;
    char str1[100001], str2[100001];
    scanf("%s", str1);
    scanf("%s", str2);

    ln1 = strlen(str1);
    ln2 = strlen(str2);
    x = MAX(ln1, ln2);

    if (ln1 != ln2)
        printf("%d", x);
    else
    {
        z = strcmp(str1, str2);
        if (z == 0)
            printf("-1");
        else
        {
            printf("%d", ln1);
        }
    }

    return 0;
}
