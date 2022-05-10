/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int mx = 1e5 + 5;
int n, m, r, k, cnt;
ll res;
int fx[] = {0, 1, 0, -1};
int fy[] = {1, 0, -1, 0};
ll chk(PII A)
{
    ll a = min(n + 1, A.first + r) - max(A.first, r);
    ll b = min(m + 1, A.second + r) - max(A.second, r);
    return a * b;
}
struct compare
{
    bool operator()(PII A, PII B)
    {
        return chk(A) < chk(B);
    }
};
priority_queue<PII, vector<PII>, compare> myQ;
set<int> used[mx];
void bfs()
{
    while (++cnt <= k)
    {
        auto it = myQ.top();
        myQ.pop(); ///cout<<it.first<<' '<<it.second<<' '<<chk(it)<<endl;
        res += chk(it);
        for (int i = 0; i < 4; i++)
        {
            int u = it.first + fx[i];
            int v = it.second + fy[i];
            if (u > 0 && u <= n && v > 0 && v <= m && used[u].count(v) == 0)
            { ///cout<<' '<<u<<' '<<v<<' '<<chk(PII(u,v))<<endl;
                myQ.push(PII(u, v));
                used[u].insert(v);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> r >> k;
    if (n == 1 && m == 1)
        printf("%0.12lf\n", 1.0);
    else
    {
        ll x = n - r + 1;
        ll y = m - r + 1;
        int p = (n + 1) / 2;
        int q = (m + 1) / 2;
        myQ.push(PII(p, q));
        used[p].insert(q);
        bfs();
        double ans = (double)res / (x * y);
        printf("%0.12lf\n", ans);
    }

    return 0;
}
