/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

map<int, int> mymap;
map<int, int>::iterator it;

struct compare
{
    bool operator()(int a, int b)
    {
        return mymap[a] < mymap[b];
    }
};
priority_queue<int, vector<int>, compare> myPQ;

struct triplet
{
    int ara[3];
};
vector<triplet> output;

int main()
{
    int i, n, x, y, z, ans;
    triplet A;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (mymap.find(x) == mymap.end())
            mymap[x] = 1;
        else
            mymap[x]++;
    }
    for (it = mymap.begin(); it != mymap.end(); it++)
        myPQ.push(it->first);
    ans = 0;
    while (myPQ.size() >= 3)
    {
        x = myPQ.top();
        myPQ.pop();
        y = myPQ.top();
        myPQ.pop();
        z = myPQ.top();
        myPQ.pop();
        ans++;
        A.ara[0] = x, A.ara[1] = y, A.ara[2] = z;
        sort(A.ara, A.ara + 3);
        output.push_back(A);

        mymap[x]--;
        mymap[y]--;
        mymap[z]--;
        if (mymap[x] > 0)
            myPQ.push(x);
        if (mymap[y] > 0)
            myPQ.push(y);
        if (mymap[z] > 0)
            myPQ.push(z);
    }
    printf("%d\n", ans);
    if (ans)
        for (i = 0; i < ans; i++)
            printf("%d %d %d\n", output[i].ara[2], output[i].ara[1], output[i].ara[0]);

    return 0;
}
