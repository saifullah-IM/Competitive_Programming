#include <iostream>
#define PRM 1000000007
using namespace std;

int main()
{
    int n;

    cin >> n;

    if (n == 1)
        cout << 0;
    else if (n == 2)
        cout << 3;
    else
    {
        int i = 2;
        long long ara[3];
        ara[0] = 0;
        ara[1] = 3;

        while (i < n)
        {
            ara[2] = (2 * ara[1] + 3 * ara[0]) % PRM;
            ara[0] = ara[1];
            ara[1] = ara[2];
            i++;
        }

        cout << ara[2];
    }

    return 0;
}
