/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

struct info
{
    int first, second, id;
};
struct compare
{
    bool operator()(info A, info B)
    {
        if (A.second == B.second)
            return A.first > B.first;
        else
            return A.second > B.second;
    }
};
bool sortFunction(info A, info B)
{
    if (A.first == B.first)
        return A.second < B.second;
    else
        return A.first < B.first;
}
const int mx = 100005;
info ara[mx];
vector<int> res;
priority_queue<info, vector<info>, compare> myPQ;

int main()
{
    int i, n, m, u, v, k = 1, ans = 0;
    info A;

    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        v = n - v + 1;
        if (u > v)
            swap(u, v);
        ara[i].first = u;
        ara[i].second = v;
        ara[i].id = i + 1;
    }
    ara[m].first = ara[m].second = n + 1, ara[m].id = m + 1;
    sort(ara, ara + m + 1, sortFunction);
    for (i = 0; i <= m; i++)
    {
        if (k == ara[i].first)
        {
            myPQ.push(ara[i]);
            continue;
        }
        else if (myPQ.empty())
        {
            k = ara[i].first;
            i--;
            continue;
        }
        else
        {
            A = myPQ.top();
            myPQ.pop();
            if (k <= A.second)
            {
                ans++;
                k++;
                res.push_back(A.id);
            }
            i--;
        }
    }
    printf("%d\n", ans);
    for (i = 0; i < res.size(); i++)
        printf("%d ", res[i]);

    return 0;
}
