#include <bits/stdc++.h>
using namespace std;

const int mx = 2e5 + 5;
int ara[mx];
bool ans[mx];
vector<int> inc, Dec;

inline bool checkInc(int x)
{
    if (inc.empty() || x > inc.back())
        return true;
    else
        return false;
}

inline bool checkDec(int x)
{
    if (Dec.empty() || x < Dec.back())
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> ara[i];
    for (int i = 0; i < n; i++)
    {
        int x = ara[i];
        bool in = checkInc(x);
        bool de = checkDec(x);
        if (!in && !de)
        { ///cout<<i<<endl; for (int v: inc) cout<<v<<endl; for (int v: Dec) cout<<v<<endl;
            cout << "NO" << endl;
            return 0;
        }
        else if (in && !de)
        {
            inc.push_back(x);
        }
        else if (!in && de)
        {
            Dec.push_back(x);
            ans[i] = true;
        }
        else
        {
            if (i + 1 == n)
                continue;
            else
            {
                if (x > ara[i + 1])
                {
                    Dec.push_back(x);
                    ans[i] = true;
                }
                else
                {
                    inc.push_back(x);
                }
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 0; i < n; i++)
        cout << (int)ans[i] << " ";

    return 0;
}
