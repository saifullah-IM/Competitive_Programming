/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int mx = 1e5 + 5;
int cnt[mx];
int main()
{
    int i, n, x, num = 0, maxi = 0, mini = mx;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        maxi = max(maxi, x);
        mini = min(mini, x);
        cnt[x]++;
    }
    for (i = maxi; i >= mini; i--)
        if (cnt[i] % 2 == 1)
        {
            cout << "Conan" << endl;
            return 0;
        }
    cout << "Agasa" << endl;

    return 0;
}
