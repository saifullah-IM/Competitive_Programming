#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n == 2 || n == 1)
        cout << -1;
    else
    {
        long long m, k, x;
        if (n % 2 == 0)
        {
            x = n / 2;
            x *= x;
            m = x - 1;
            k = x + 1;
        }
        else
        {
            x = (n + 1) / 2;
            m = 2 * x * (x - 1);
            k = m + 1;
        }

        cout << m << ' ' << k;
    }

    return 0;
}
