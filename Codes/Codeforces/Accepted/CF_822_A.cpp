#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, A, B;
    long long fact[13];

    fact[0] = 1;
    for (i = 1; i <= 12; i++)
        fact[i] = i * fact[i - 1];

    scanf("%d %d", &A, &B);
    A = min(A, B);
    cout << fact[A];

    return 0;
}
