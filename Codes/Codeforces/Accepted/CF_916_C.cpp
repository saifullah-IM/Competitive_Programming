/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
typedef pair<PII, int> edge;
const int hi = 3e5;
bool flag[hi];
vector<int> primes;
void sieve()
{
    primes.push_back(2);
    for (ll i = 3; i < hi; i += 2)
        if (!flag[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j < hi; j += i)
                flag[j] = true;
        }
}
vector<edge> ans;
int main()
{
    sieve();
    int i, n, m, sp, mst;
    cin >> n >> m;
    sp = 2;
    mst = 0;
    for (i = n; i > 2; i--)
    {
        ans.push_back(edge(PII(1, i), 2));
        mst += 2;
    }
    auto it = upper_bound(primes.begin(), primes.end(), mst);
    ans.push_back(edge(PII(1, 2), *it - mst));
    mst = *it;
    m -= n - 1;
    for (i = 2; i < n && m > 0; i++)
    {
        for (int j = i + 1; j <= n && m > 0; j++)
        {
            ans.push_back(edge(PII(i, j), mst));
            m--;
        }
    }
    printf("%d %d\n", sp, mst);
    for (auto it : ans)
    {
        int u = it.first.first;
        int v = it.first.second;
        int w = it.second;
        printf("%d %d %d\n", u, v, w);
    }

    return 0;
}
