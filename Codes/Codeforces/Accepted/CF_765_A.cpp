#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n;
    string s;
    cin >> n;
    cin >> s;
    for (i = 0; i < n; i++)
        cin >> s;
    if (n % 2 == 0)
        cout << "home";
    else
        cout << "contest";

    return 0;
}
