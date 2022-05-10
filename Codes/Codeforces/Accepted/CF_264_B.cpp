/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 100005;
vector<int> next_idx[mx];
int n, ara[mx];
bool flag[mx], chk[mx];

void sieve()
{
    int i, j, last = -1;

    for (i = 2; i < mx; i += 2)
        if (chk[i])
        {
            if (last != -1)
                next_idx[last].push_back(ara[i]);
            last = ara[i];
        }
    for (i = 3; i < mx; i += 2)
        if (!flag[i])
        {
            last = -1;
            for (j = i; j < mx; j += i)
            {
                flag[j] = true;
                if (chk[j])
                {
                    if (last != -1)
                        next_idx[last].push_back(ara[j]);
                    last = ara[j];
                }
            }
        }
}

int DP[mx];
int solve(int pos)
{
    if (next_idx[pos].empty())
        return 1;
    if (DP[pos])
        return DP[pos];

    int i, m;
    m = next_idx[pos].size();
    for (i = 0; i < m; i++)
        DP[pos] = max(DP[pos], 1 + solve(next_idx[pos][i]));
    return DP[pos];
}

int main()
{
    int i, x, ans;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        ara[x] = i;
        chk[x] = true;
    }
    ans = -1;
    sieve();
    for (i = 0; i < n; i++)
        ans = max(ans, solve(i));
    printf("%d\n", ans);

    return 0;
}
