#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if (a == b && a != 0)
        printf("YES");
    else if (a + 1 == b || b + 1 == a)
        printf("YES");
    else
        printf("NO");

    return 0;
}
