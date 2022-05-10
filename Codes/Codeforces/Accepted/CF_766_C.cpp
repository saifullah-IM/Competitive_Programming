#include <bits/stdc++.h>
#define MOD 1000000007
#define PII pair<int, int>
using namespace std;

int n, ans2, ara[27];
PII DP[1005];
char str[1005];

PII split_message(int i)
{
    if (i == n)
        return make_pair(1, 0);
    if (i == n - 1)
        return make_pair(1, 1);
    if (DP[i].first != -1)
        return DP[i];

    char ch;
    int j, u, v, ans;
    ans = 0;
    u = v = MOD;
    ch = str[i];
    for (j = i; j < n; j++)
    {
        u = min(u, ara[str[j] - 'a']);
        if (u >= j - i + 1)
        {
            ans = (ans + split_message(j + 1).first) % MOD;
            v = min(v, split_message(j + 1).second);
            ans2 = max(ans2, j - i + 1);
        }
        else
            break;
    }

    return DP[i] = make_pair(ans, v + 1);
}

int main()
{
    int i, u, ans1, ans3;
    char ch;
    PII A;

    scanf("%d", &n);
    scanf("%s", str);
    for (i = 0; i < 26; i++)
        scanf("%d", &ara[i]);

    memset(DP, -1, sizeof(DP));
    ans2 = 1;
    A = split_message(0);
    ans1 = A.first;
    ans3 = A.second;

    printf("%d\n%d\n%d", ans1, ans2, ans3);

    return 0;
}
