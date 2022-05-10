/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
#define PII pair<ll, ll>
using namespace std;

const int mx = 250005;
int ara[mx], mat[52][5005], mxi[52];
PII maxsum[3][52];
bool flag[52];
int main()
{
    int i, j, n, m, mm;
    ll ans = 0, temp;
    bool chk;

    scanf("%d %d", &n, &m);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &mat[i][0]);
        temp = 0;
        mxi[i] = -mx;
        chk = false;
        maxsum[2][i].first = -mx;
        for (j = 1; j <= mat[i][0]; j++)
        {
            scanf("%d", &mat[i][j]);
            mxi[i] = max(mxi[i], mat[i][j]);
            if (mat[i][j] >= 0)
                chk = true;
            temp = max(temp + mat[i][j], (ll)0);
            maxsum[2][i].first = max(maxsum[2][i].first, temp);
        }
        flag[i] = chk;
    }
    chk = false;
    mm = -mx;
    for (i = 0; i < m; i++)
    {
        scanf("%d", &ara[i]);
        j = ara[i] - 1;
        ans = max(ans, maxsum[2][j].first);
        chk = chk | flag[j];
        mm = max(mm, mxi[j]);
    }

    if (!chk)
    {
        printf("%d\n", mm);
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        maxsum[0][i].first = maxsum[0][i].second = 0;
        for (j = 1; j <= mat[i][0]; j++)
        {
            maxsum[0][i].first += mat[i][j];
            maxsum[0][i].second = max(maxsum[0][i].second, maxsum[0][i].first);
        }
        maxsum[1][i].first = maxsum[1][i].second = 0;
        for (j = mat[i][0]; j > 0; j--)
        {
            maxsum[1][i].first += mat[i][j];
            maxsum[1][i].second = max(maxsum[1][i].second, maxsum[1][i].first);
        }
    }
    temp = 0;
    for (i = 0; i < m; i++)
    {
        j = ara[i] - 1;
        ans = max(ans, temp + maxsum[0][j].second);
        temp = max(maxsum[1][j].second, temp + maxsum[0][j].first);
    }
    printf("%lld\n", ans);

    return 0;
}
