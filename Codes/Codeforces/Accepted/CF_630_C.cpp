#include <iostream>
using namespace std;

int main()
{
    long long ans = 1;
    int i = 0, n;

    cin >> n;
    while (i <= n)
    {
        ans *= 2;
        i++;
    }
    ans -= 2;

    cout << ans;

    return 0;
}
