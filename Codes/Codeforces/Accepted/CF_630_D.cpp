#include <iostream>
using namespace std;

int main()
{
    int n;
    long long ans;

    cin >> n;
    ans = n;
    ans = 1 + 3 * ans * (ans + 1);
    cout << ans;

    return 0;
}
