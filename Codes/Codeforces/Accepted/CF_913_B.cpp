/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 1005;
vector<int> edges[mx];

int main()
{
    int i, x, n;

    scanf("%d", &n);
    for (i = 2; i <= n; i++)
    {
        scanf("%d", &x);
        edges[x].push_back(i);
    }
    bool ans = true;
    for (i = 1; i <= n; i++)
        if (!edges[i].empty())
        {
            int cnt = 0;
            for (int v : edges[i])
            {
                if (edges[v].empty())
                    cnt++;
            }
            if (cnt < 3)
            {
                ans = false;
                break;
            }
        }
    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
