#include <iostream>
#include <cmath>
using namespace std;

int is_composite[50000];
int primes[5200];
int sieve(int n)
{
    int i, j, k = 1;
    primes[0] = 2;
    for (i = 3; i <= n; i += 2)
    {
        if (is_composite[i] == 0)
        {
            primes[k] = i;
            k++;
            for (j = i * i; j <= n; j += i)
                is_composite[j] = 1;
        }
    }
    return k;
}

int main()
{
    int i = 3, j, k, root, n, ans = 1;
    cin >> n;

    if (n == 2 || n == 3)
        cout << 1;
    else if (n % 2 == 0)
        cout << 2;
    else
    {
        root = sqrt(n);
        k = sieve(root + 1);
        while (--i)
        {
            for (j = 0; j < k; j++)
            {
                if (n % primes[j] == 0)
                    break;
            }
            if (j == k)
            {
                cout << ans;
                break;
            }
            else
            {
                n -= 2;
                ans++;
            }
        }
        if (i == 0)
            cout << ans;
    }

    return 0;
}
