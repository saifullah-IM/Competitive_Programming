/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main()
{
    ll n, k;
    cin >> n >> k;
    priority_queue<int> myPQ, auxPQ;
    int i = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
        {
            myPQ.push(i);
            auxPQ.push(i);
        }
        i++;
        n /= 2;
    }
    if (myPQ.size() > k)
    {
        cout << "No" << endl;
        return 0;
    }
    else
        cout << "Yes" << endl;
    while (myPQ.size() < k)
    {
        int t = myPQ.top();
        myPQ.pop();
        myPQ.push(t - 1);
        myPQ.push(t - 1);
    }
    int x = myPQ.top();
    while (auxPQ.top() != x)
    {
        int t = auxPQ.top();
        auxPQ.pop();
        auxPQ.push(t - 1);
        auxPQ.push(t - 1);
    }
    vector<int> ans;
    while (!auxPQ.empty())
    {
        ans.push_back(auxPQ.top());
        auxPQ.pop();
    }
    while (ans.size() < k)
    {
        int t = ans.back();
        ans.pop_back();
        ans.push_back(t - 1);
        ans.push_back(t - 1);
    }
    for (i = 0; i < k; i++)
        printf("%d ", ans[i]);

    return 0;
}
