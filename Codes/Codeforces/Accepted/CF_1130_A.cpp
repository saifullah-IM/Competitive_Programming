#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x > 0)
            pos++;
        else if (x < 0)
            neg++;
    }
    int mid = (n + 1) / 2;
    if (pos >= mid)
        cout << 1 << endl;
    else if (neg >= mid)
        cout << -1 << endl;
    else
        cout << 0 << endl;

    return 0;
}
