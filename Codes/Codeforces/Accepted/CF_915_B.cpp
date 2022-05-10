/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
int main()
{
    int i, n, pos, l, r;

    cin >> n >> pos >> l >> r;
    int k = r - l + 1;
    if (k == n)
    {
        cout << 0 << endl;
        return 0;
    }

    int ans1 = INT_MAX, ans2 = INT_MAX;
    if (l > 1)
    {
        ans1 = fabs(pos - l) + 1;
        if (r < n)
            ans1 += fabs(r - l) + 1;
    }
    if (r < n)
    {
        ans2 = fabs(pos - r) + 1;
        if (l > 1)
            ans2 += fabs(r - l) + 1;
    }
    cout << min(ans1, ans2) << endl;
    return 0;
}