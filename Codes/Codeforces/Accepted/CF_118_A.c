#include <stdio.h>
int main()
{
    int i, ln;
    char str[101];
    scanf("%s", str);
    for (ln = 0; str[ln] != '\0'; ln++)
        ;
    for (i = 0; i < ln; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y')
            continue;
        else
            printf(".%c", str[i]);
    }
}