/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define mp make_pair
#define PI (acos(-1.0))
#define inf INT_MAX / 2
#define abs(X) ((X) > 0 ? (X) : (-(X)))
using namespace std;

///cout << fixed << setprecision(12) << p << endl;

typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VP;

const int mx = 2e5 + 5;
const int MOD = 1e9 + 7;
int ara[mx];
int n, maxi[mx], mini[mx];
string str;
int toRight(int pos)
{
    if (pos == n - 1)
        return n - 1;
    if (str[pos] == '0')
        return pos;
    if (maxi[pos] != -1)
        return maxi[pos];
    return maxi[pos] = toRight(pos + 1);
}
int toLeft(int pos)
{
    if (pos == 0)
        return 0;
    if (str[pos - 1] == '0')
        return pos;
    if (mini[pos] != -1)
        return mini[pos];
    return mini[pos] = toLeft(pos - 1);
}
PII temp[mx];
bool cmp(PII A, PII B)
{
    if (A.first == B.first)
        return A.second < B.second;
    return A.first < B.first;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ara[i];
        temp[i].first = ara[i];
        temp[i].second = i;
    }
    sort(temp, temp + n, cmp);
    cin >> str;
    int cnt = 0;
    memset(maxi, -1, sizeof(maxi));
    memset(mini, -1, sizeof(mini));
    for (int i = 0; i < n; i++)
    {
        int j = temp[i].second;
        int l = toLeft(j);
        int r = toRight(j); ///cout<<l<<' '<<r<<' '<<temp[i].first<<endl;
        if (l <= i && r >= i)
            cnt++;
    }
    if (cnt == n)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
