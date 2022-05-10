/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define PBI pair<bool, int>
using namespace std;

const int mx = 5005;
bool isPalindrome[mx][mx];
int DP[mx][mx];
char str[mx];

inline PBI solve(int i, int j)
{
    if (DP[i][j] != 0)
        return make_pair(isPalindrome[i][j], DP[i][j]);
    if (i == j)
    {
        DP[i][j] = isPalindrome[i][j] = 1;
        return make_pair(1, 1);
    }
    if (i == j - 1)
    {
        if (str[i] == str[j])
        {
            isPalindrome[i][j] = 1;
            DP[i][j] = 3;
            return make_pair(1, 3);
        }
        else
        {
            isPalindrome[i][j] = 0;
            DP[i][j] = 2;
            return make_pair(0, 2);
        }
    }

    PBI A, B, C;
    A = solve(i + 1, j - 1);
    B = solve(i + 1, j);
    C = solve(i, j - 1);

    if (str[i] == str[j])
        isPalindrome[i][j] = A.first;
    else
        isPalindrome[i][j] = false;
    DP[i][j] = B.second + C.second - A.second + isPalindrome[i][j];
    return make_pair(isPalindrome[i][j], DP[i][j]);
}
int main()
{
    int i, q, l, r, ans;

    scanf("%s", str);
    solve(0, strlen(str) - 1);
    scanf("%d", &q);
    for (i = 0; i < q; i++)
    {
        scanf("%d %d", &l, &r);
        if (DP[l - 1][r - 1])
            printf("%d\n", DP[l - 1][r - 1]);
        else
            printf("%d\n", solve(l - 1, r - 1).second);
    }

    return 0;
}
