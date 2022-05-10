#include <bits/stdc++.h>
using namespace std;

int main()
{

    string a, b;
    cin >> a >> b;

    if (b.size() > a.size())
    {
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        cout << a;
        return 0;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 1; i++)
    {
        for (int j = i; j < a.size(); j++)
        {
            if (a[i] < a[j])
            {
                swap(a[i], a[j]);
                if (b.compare(a) < 0)
                    swap(a[j], a[i]);
            }
        }
    }
    cout << a;

    return 0;
}
