#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if (n % 2)
        printf("0");
    else
    {
        n = (n - 2) / 4;
        printf("%d", n);
    }
    return 0;
}
