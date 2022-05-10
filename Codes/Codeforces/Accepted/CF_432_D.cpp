/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;
char str[mx];
int len, Z[mx], cnt[mx];
vector<int> ans;

void ZFunction()
{
    int i, l, r;
    len = strlen(str);
    l = r = Z[0] = 0;

    for (i = 1; i < len; i++)
    {
        if (i <= r)
            Z[i] = min(Z[i - l], r - i + 1);
        while (i + Z[i] < len && str[i + Z[i]] == str[Z[i]])
            Z[i]++;
        if (i + Z[i] - 1 > r)
            l = i, r = i + Z[i] - 1;
        if (i + Z[i] == len)
            ans.push_back(i);
        cnt[Z[i]]++;
    }
}

bool compare(int i, int j)
{
    return Z[i] < Z[j];
}

int main()
{
    scanf("%s", str);
    ZFunction();
    sort(ans.begin(), ans.end(), compare);
    cnt[len] = 1;
    Z[0] = len; ///cout<<1;
    ans.push_back(0);
    int n = ans.size();
    for (int i = len - 1; i >= 0; i--)
        cnt[i] += cnt[i + 1];

    printf("%d\n", n);
    for (int i = 0; i < n; i++)
        printf("%d %d\n", Z[ans[i]], cnt[Z[ans[i]]]);

    return 0;
}
