#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

deque<PII> ans1;
vector<PII> ans2;

int main()
{
    int i, n, k, x, y, a, b, ans, t;
    PII A;

    scanf("%d %d", &n, &k);
    for (i = 1; i <= k; i++)
        ans1.push_back(make_pair(k + 1, i));
    for (i = k + 2; i <= n; i++)
    {
        A = ans1.back();
        ans1.pop_back();
        ans1.push_front(make_pair(i, A.second));
        ans2.push_back(make_pair(A.first, i));
    }

    ans = ((n - 1) / k) * 2;
    if ((n - 1) % k != 0)
    {
        t = (n - 1) % k;
        if (t == 1)
            ans += 1;
        else
            ans += 2;
    }
    x = ans1.size();
    y = ans2.size();

    printf("%d\n", ans);
    for (i = 0; i < x; i++)
    {
        A = ans1[i];
        a = A.first;
        b = A.second;
        printf("%d %d\n", a, b);
    }
    for (i = 0; i < y; i++)
    {
        A = ans2[i];
        a = A.first;
        b = A.second;
        printf("%d %d\n", a, b);
    }

    return 0;
}
