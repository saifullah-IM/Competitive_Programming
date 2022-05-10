#include <bits/stdc++.h>
#define PSS pair<string, string>
using namespace std;

int n, q;
set<string> ans;
PSS ops[40];

void dfs(string S)
{
    int m;
    m = S.size();
    if (m == n)
    {
        ans.insert(S);
        return;
    }

    int i;
    string U, V;

    for (i = 0; i < q; i++)
    {
        V = ops[i].first;
        if (S[0] == V[0])
        {
            U.clear();
            U += ops[i].second;
            if (m != 1)
                U.append(S.begin() + 1, S.end());
            dfs(U);
        }
    }
}

int main()
{
    int i, m;
    string S1, S2;

    scanf("%d %d", &n, &q);
    for (i = 0; i < q; i++)
    {
        cin >> S1 >> S2;
        ops[i] = make_pair(S2, S1);
    }

    dfs("a");
    m = ans.size();
    printf("%d", m);

    return 0;
}
