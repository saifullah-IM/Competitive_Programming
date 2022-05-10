#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, i, ans = 0;
    long long sum = 0;

    cin >> n;
    int ara[n];
    for (i = 0; i < n; i++)
        cin >> ara[i];

    sort(ara, ara + n);
    for (i = 0; i < n; i++)
    {
        if (sum <= ara[i])
        {
            ans++;
            sum += ara[i];
        }
    }
    cout << ans;

    return 0;
}
