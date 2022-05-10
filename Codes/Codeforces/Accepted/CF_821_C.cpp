#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, m, ans = 0, x, y, z, k, cnt;
    string S;
    bool mode = false;
    stack<int> mystk;

    scanf("%d", &n);
    m = 2 * n;
    ans = 0;
    cnt = k = 0;
    for (i = 0; i < m; i++)
    {
        cin >> S;
        if (S == "add")
        {
            mode = false;
            scanf("%d", &x);
            mystk.push(x);
            cnt++;
        }
        else
        {
            k++;
            if (!mode)
            {
                x = mystk.top();
                if (x == k)
                {
                    mystk.pop();
                    cnt--;
                }
                else if (cnt > 0)
                {
                    ans++;
                    mode = true;
                    cnt = 0;
                }
            }
        }
    }
    cout << ans;

    return 0;
}
