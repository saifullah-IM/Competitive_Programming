/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define PII pair<int, long long>
using namespace std;

const int mx = 300005;
vector<int> synonym[mx], stk;
int ara[mx], start[mx], low[mx], Tm;
bool vis[mx], done[mx];
PII DP[mx], words[mx];
map<string, int> mymap;

PII solve(int w)
{
    if (synonym[w].empty())
        return words[w];
    if (done[w])
        return DP[w];
    vis[w] = true;
    start[w] = low[w] = ++Tm;
    stk.push_back(w);
    int i, m, v;
    PII A, ans;

    ans.first = words[w].first;
    ans.second = words[w].second;
    m = synonym[w].size();
    for (i = 0; i < m; i++)
    {
        v = synonym[w][i];
        if (!low[v])
        {
            A = solve(v);
            if (A.first < ans.first)
                ans = A;
            else if (A.first == ans.first && A.second < ans.second)
                ans = A;
        }
        else if (done[v])
        {
            A = DP[v];
            if (A.first < ans.first)
                ans = A;
            else if (A.first == ans.first && A.second < ans.second)
                ans = A;
        }
        if (vis[v])
            low[w] = min(low[w], low[v]);
    }

    if (low[w] == start[w])
        while (1)
        {
            v = stk.back();
            stk.pop_back();
            DP[v] = ans;
            vis[v] = false;
            if (w == v)
                break;
        }

    done[w] = true;
    return DP[w] = ans;
}

int main()
{
    int i, j, k, n, m, w;
    string a, b;

    w = 0;
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        cin >> a;
        for (j = k = 0; j < a.size(); j++)
        {
            if (a[j] >= 'a')
                a[j] = a[j] - 'a' + 'A';
            if (a[j] == 'R')
                k++;
        }
        if (mymap.find(a) == mymap.end())
        {
            mymap[a] = w;
            words[w] = make_pair(k, a.size());
            w++;
        }
        ara[i] = mymap[a];
    }
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        cin >> a >> b;
        for (j = k = 0; j < a.size(); j++)
        {
            if (a[j] >= 'a')
                a[j] = a[j] - 'a' + 'A';
            if (a[j] == 'R')
                k++;
        }
        if (mymap.find(a) == mymap.end())
        {
            mymap[a] = w;
            words[w] = make_pair(k, a.size());
            w++;
        }
        for (j = k = 0; j < b.size(); j++)
        {
            if (b[j] >= 'a')
                b[j] = b[j] - 'a' + 'A';
            if (b[j] == 'R')
                k++;
        }
        if (mymap.find(b) == mymap.end())
        {
            mymap[b] = w;
            words[w] = make_pair(k, b.size());
            w++;
        }
        if (mymap[a] != mymap[b])
            synonym[mymap[a]].push_back(mymap[b]);
    }

    PII ans, A;
    ans.first = ans.second = 0;
    for (i = 0; i < m; i++)
    {
        A = solve(ara[i]);
        ans.first += A.first;
        ans.second += A.second;
    }
    cout << ans.first << ' ' << ans.second << endl;

    return 0;
}
