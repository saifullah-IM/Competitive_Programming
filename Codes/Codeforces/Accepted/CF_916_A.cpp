/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
bool check(int n)
{
    bool ret = false;
    while (n > 0)
    {
        if (n % 10 == 7)
            ret = true;
        n /= 10;
    }
    return ret;
}
int main()
{
    int i, x, hh, mm, ans = 0;

    cin >> x >> hh >> mm;
    while (1)
    {
        if (check(hh) || check(mm))
            break;
        ans++;
        mm -= x;
        if (mm < 0)
        {
            mm += 60;
            hh--;
            if (hh < 0)
                hh += 24;
        }
    }
    cout << ans << endl;

    return 0;
}
