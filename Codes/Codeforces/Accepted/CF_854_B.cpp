/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, a, b, k, x;

    scanf("%d %d", &n, &k);

    if (n == k || k == 0)
        a = 0;
    else
        a = 1;
    b = min(k * 2, n - k);
    cout << a << ' ' << b << endl;

    return 0;
}
