/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define PII pair<int, int>
#define ll long long
using namespace std;

const int mx = 1e5 + 5;
int n;
PII ar1[mx], ar2[mx], temp[mx];
ll cnt, sum, SS;

void inversion_count(PII ara[], int lo, int hi)
{
    if (lo == hi)
        return;
    int mid = (lo + hi) / 2;
    inversion_count(ara, lo, mid);
    inversion_count(ara, mid + 1, hi);

    int i, j, k, m, t = 0;
    ll SI = 0;
    m = mid - lo + 1;
    for (i = lo; i <= mid; i++)
        SI += ara[i].second;
    for (i = lo, j = mid + 1, k = lo; k <= hi; k++)
    {
        if (i == mid + 1)
            temp[k] = ara[j++];
        else if (j == hi + 1 || ara[i].first <= ara[j].first)
        {
            t++;
            SI -= ara[i].second;
            temp[k] = ara[i++];
        }
        else
        {
            cnt += mid - i + 1;
            sum += (ll)(n - ara[j].second) * (SI + m - t);
            SS += (ll)(ara[j].second + 1) * ((ll)(m - t) * n - SI); //cout<<SS<<' '<<t<<endl;
            temp[k] = ara[j++];
        }
    }
    for (i = lo; i <= hi; i++)
        ara[i] = temp[i];
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar1[i].first);
        ar1[i].second = i;
        ar2[n - 1 - i] = ar1[i];
    }
    double ans;
    inversion_count(ar1, 0, n - 1);
    ans = cnt - (double)sum / n / (n + 1); //cout<<sum<<endl;
    SS = 0;
    inversion_count(ar2, 0, n - 1);
    ans += (double)SS / n / (n + 1); //cout<<SS<<endl;
    printf("%0.12lf\n", ans);

    return 0;
}
