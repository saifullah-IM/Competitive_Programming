/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 6;
int ara[mx];
bool flag[mx];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ara[i];
    int last = n;
    for (int i = n - 1; i > 0; i--)
    {
        if (ara[i] == 0)
            continue;
        int k = min(last, i - 1);
        last = min(last, i - ara[i]);
        last = max(last, 0);
        for (int j = k; j >= last; j--)
            flag[j] = true;
        if (last == 0)
            break;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (!flag[i])
            ans++;
    cout << ans << endl;

    return 0;
}
