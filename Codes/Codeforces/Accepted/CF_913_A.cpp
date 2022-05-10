/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int i, n, m;

    cin >> n >> m;

    int cnt = 0;
    int k = m;
    int ara[35];
    while (k > 0)
    {
        ara[cnt] = k % 2;
        cnt++;
        k /= 2;
    }
    if (cnt < n)
    {
        cout << m << endl;
        return 0;
    }
    int x = -1;
    x = (x << n);
    x = (~x);
    cout << (x & m) << endl;

    return 0;
}
