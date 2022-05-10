#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;
set<int> graph[mx];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].insert(v);
        graph[v].insert(u);
    } ///cout<<"in"<<n<<m<<endl;
    for (int i = 1; i <= n; i++)
    { ///cout<<"------"<<i<<endl;
        if (graph[i].size() != 2)
            continue;
        queue<int> myQ;
        myQ.push(i);
        while (!myQ.empty())
        {
            int u = myQ.front();
            myQ.pop();
            if (graph[u].size() != 2)
                continue;
            set<int>::iterator it = graph[u].begin();
            int x = *it;
            it++;
            int y = *it;
            graph[x].erase(u);
            graph[y].erase(u);
            graph[x].insert(y);
            graph[y].insert(x);
            graph[u].clear();
            if (graph[x].size() == 2)
                myQ.push(x);
            if (graph[y].size() == 2)
                myQ.push(y);
            ///cout<<"***"<<i<<' '<<u<<' '<<x<<' '<<y<<endl;
        }
    }
    bool ans = true;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (graph[i].size() > 1)
            ans = false;
        if (!graph[i].empty())
            cnt++;
    }
    if (ans && cnt == 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
