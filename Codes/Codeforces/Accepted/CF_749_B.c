#include <stdio.h>
int main()
{
    int X[4], Y[4], i;
    scanf("%d %d", &X[0], &Y[0]);
    scanf("%d %d", &X[1], &Y[1]);
    scanf("%d %d", &X[2], &Y[2]);
    printf("3\n");

    X[3] = X[0] + X[1] - X[2];
    Y[3] = Y[0] + Y[1] - Y[2];
    printf("%d %d\n", X[3], Y[3]);

    X[3] = X[2] + X[1] - X[0];
    Y[3] = Y[2] + Y[1] - Y[0];
    printf("%d %d\n", X[3], Y[3]);

    X[3] = X[0] + X[2] - X[1];
    Y[3] = Y[0] + Y[2] - Y[1];
    printf("%d %d\n", X[3], Y[3]);

    return 0;
}
