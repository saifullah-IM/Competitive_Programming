#include <stdio.h>
#include <math.h>

int main()
{
    int i, n, k;
    long long int x;
    double root;

    scanf("%d %d", &n, &k);
    int ID[n];
    for (i = 0; i < n; i++)
        scanf("%d", &ID[i]);

    x = k;
    x = (x * 8) + 1;
    root = (sqrt(x) - 1.0) / 2.0;
    x = floor(root);
    k = k - ((x * (x + 1)) / 2);

    if (k)
        printf("%d", ID[k - 1]);
    else
        printf("%d", ID[x - 1]);

    return 0;
}
