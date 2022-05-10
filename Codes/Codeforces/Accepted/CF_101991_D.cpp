#include <bits/stdc++.h>
using namespace std;

const int mx = 1005;
bool ara[mx][mx];
vector<int> xvec, yvec;
map<int, int> xmap, ymap;
long long xrev[mx], yrev[mx];
typedef pair<int, int> PII;
PII white[mx];

int main()
{
    freopen("dull.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        int k;
        cin >> n >> m >> k;
        if (k == 0)
        {
            cout << 0 << ' ' << n * m << endl;
            continue;
        }

        for (int i = 0; i < k; i++)
        {
            cin >> white[i].first >> white[i].second;
            xvec.push_back(white[i].first);
            yvec.push_back(white[i].second);
        }
        sort(xvec.begin(), xvec.end());
        sort(yvec.begin(), yvec.end());

        int n1, m1, cnt = 1, num = xvec[0];
        for (int v : xvec)
        {
            if (num != v)
            {
                num = v;
                cnt++;
            }
            xrev[cnt] = v;
            xmap[v] = cnt;
        }
        n1 = cnt;
        xrev[n1 + 1] = n + 1;

        cnt = 1, num = yvec[0];
        for (int v : yvec)
        {
            if (num != v)
            {
                num = v;
                cnt++;
            }
            yrev[cnt] = v;
            ymap[v] = cnt;
        }
        m1 = cnt;
        yrev[m1 + 1] = m + 1;

        for (int i = 0; i < k; i++)
        {
            int u = white[i].first;
            int v = white[i].second;
            u = xmap[u];
            v = ymap[v];
            ara[u][v] = 1;
        }
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 2; j <= m1; j++)
            {
                ara[i][j] ^= ara[i][j - 1];
            }
        }
        for (int j = 1; j <= m1; j++)
        {
            for (int i = 2; i <= n1; i++)
            {
                ara[i][j] ^= ara[i - 1][j];
            }
        }

        long long odd = 0, even = 0;
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= m1; j++)
            {
                if (ara[i][j])
                {
                    int p, q;
                    p = i + 1;
                    q = j + 1;
                    long long xtra = (xrev[p] - xrev[i]) * (yrev[q] - yrev[j]);
                    odd += xtra;

                    ///cout<<i<<' '<<j<<' '<<xrev[i]<<' '<<yrev[j]<<' '<<odd<<endl;
                }
            }
        }

        long long total = n * m;
        even = total - odd;
        cout << odd << ' ' << even << endl;

        xvec.clear();
        xmap.clear();
        yvec.clear();
        ymap.clear();
        memset(ara, 0, sizeof(ara));
    }

    return 0;
}
