#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 5;
const int inf = 1e9 + 7;

int ara1[mx], ara2[mx];

int main()
{
    ios_base::sync_with_stdio(false);

    int tests;
    cin >> tests;
    while (tests--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> ara1[i];
            ara2[n - 1 - i] = ara1[i];
        }
        for (int i = 0; i < n; i++)
        {
            ara1[i] -= i;
            ara2[i] -= i;
        }

        int mini = ara1[0];
        int l = 0;
        for (int i = 1; i < n; i++)
        {
            if (ara1[i] > mini)
            {
                cout << "YES" << '\n';
                cout << l + 1 << ' ' << i + 1 << '\n';
                goto done;
            }
            if (ara1[i] < mini)
            {
                l = i;
                mini = ara1[i];
            }
        }

        mini = ara2[0];
        l = 0;
        for (int i = 1; i < n; i++)
        {
            if (ara2[i] > mini)
            {
                cout << "YES" << '\n';
                cout << n - i << ' ' << n - l << '\n';
                goto done;
            }
            if (ara2[i] < mini)
            {
                l = i;
                mini = ara2[i];
            }
        }

        cout << "NO" << endl;

    done:
        n = 0;
    }

    return 0;
}
