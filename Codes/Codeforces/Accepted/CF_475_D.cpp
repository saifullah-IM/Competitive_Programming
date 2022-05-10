/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int GCD(int a, int b)
{
    while (b > 0)
    {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

const int mx = 1e5 + 5;
int ara[mx];
int main()
{
    int i, n, q;
    map<int, ll> ans;
    map<int, ll> divs, nextdivs;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &ara[i]);
    for (i = 0; i < n; i++)
    {
        nextdivs.clear();
        for (auto &p : divs)
        {
            nextdivs[GCD(p.first, ara[i])] += p.second;
        }
        nextdivs[ara[i]]++;
        swap(divs, nextdivs);
        for (auto &p : divs)
        {
            ans[p.first] += p.second;
        }
    }
    scanf("%d", &q);
    for (i = 0; i < q; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%lld\n", ans[x]);
    }

    return 0;
}
