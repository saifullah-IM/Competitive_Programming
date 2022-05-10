/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define PII pair<int, int>
using namespace std;

struct edge
{
    int u, v, w;
};
bool sortFunction(edge A, edge B)
{
    if (A.w == B.w)
        return A.v > B.v;
    return A.w < B.w;
}
const int mx = 100005;
edge input[mx], output[mx];
vector<PII> temp;

int main()
{
    int i, n, m, u, v, w;
    bool chk = true;
    PII A;

    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &input[i].w, &input[i].v);
        input[i].u = i;
    }
    sort(input, input + m, sortFunction);
    v = 2;
    for (i = 0; i < m; i++)
    {
        if (input[i].v)
        {
            output[i].u = 1;
            output[i].v = v;
            output[i].w = input[i].u;
            for (u = 2; u < v && temp.size() < m; u++)
                temp.push_back(make_pair(u, v));
            v++;
        }
        else if (temp.empty())
        {
            chk = false;
            break;
        }
        else
        {
            A = temp.back();
            output[i].u = A.first;
            output[i].v = A.second;
            output[i].w = input[i].u;
            temp.pop_back();
        }
    }

    if (!chk)
        printf("-1\n");
    else
    {
        sort(output, output + m, sortFunction);
        for (i = 0; i < m; i++)
            printf("%d %d\n", output[i].u, output[i].v);
    }

    return 0;
}
