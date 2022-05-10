/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
#define PII pair<ll, ll>
using namespace std;

const int mx = 100005;
char str[mx];
int main()
{
    int i, n, k;
    char ch;
    bool chk;
    vector<int> v1, v2;

    scanf("%s", str);
    ch = str[0];
    n = strlen(str);
    chk = k = 1;
    for (i = 1; i <= n; i++)
    {
        if (ch != str[i])
        {
            ch = str[i];
            if (chk)
                v1.push_back(k);
            else
                v2.push_back(k);
            k = 1;
            chk ^= 1;
        }
        else
            k++;
    }

    ll ans1, ans2, t1, t2, p, q, r;
    PII A, B;
    A.first = A.second = B.first = B.second = ans1 = ans2 = 0;

    n = max(v1.size(), v2.size());
    for (i = 0; i < n; i++)
    {
        p = (v1[i] + 1) / 2;
        q = v1[i] / 2;
        ans1 += A.first * p + A.second * q;
        ans2 += A.first * q + A.second * p;
        if (v1[i] % 2 == 1)
        {
            swap(A.first, A.second);
            swap(B.first, B.second);
        }
        A.first += p;
        A.second += q;
        p = (p * (p + 1)) / 2;
        q = (q * (q + 1)) / 2;
        r = (v1[i] - 1) / 2;
        r = (r * (r + 1)) / 2;
        ans1 += q + r;
        ans2 += p + q;

        if (i < v2.size())
        {
            p = (v2[i] + 1) / 2;
            q = v2[i] / 2;
            ans1 += B.first * p + B.second * q;
            ans2 += B.first * q + B.second * p;
            if (v2[i] % 2 == 1)
            {
                swap(A.first, A.second);
                swap(B.first, B.second);
            }
            B.first += p;
            B.second += q;
            p = (p * (p + 1)) / 2;
            q = (q * (q + 1)) / 2;
            r = (v2[i] - 1) / 2;
            r = (r * (r + 1)) / 2;
            ans1 += q + r;
            ans2 += p + q;
        }
    }

    printf("%lld %lld", ans1, ans2);

    return 0;
}
