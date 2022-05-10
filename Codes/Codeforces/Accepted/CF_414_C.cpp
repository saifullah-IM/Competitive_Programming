/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = (1 << 20) + 5;
int ara[mx], rev[mx], temp[mx];
ll ans[22], res[22];
map<int, int> mymap;

void prep()
{
    mymap[1] = 0;
    int x = 1;
    for (int i = 1; i <= 20; i++)
    {
        x *= 2;
        mymap[x] = i;
    }
}

void inversion_count(int arr[], ll a[], int lo, int hi)
{
    if (lo == hi)
        return;
    int mid = (lo + hi) / 2;
    inversion_count(arr, a, lo, mid);
    inversion_count(arr, a, mid + 1, hi);

    int i, j, k, x;
    x = mymap[hi - lo + 1];
    for (i = k = lo, j = mid + 1; k <= hi; k++)
    {
        if (i == mid + 1)
            temp[k] = arr[j++];
        else if (j == hi + 1 || arr[i] <= arr[j])
            temp[k] = arr[i++];
        else
        {
            a[x] += mid - i + 1;
            temp[k] = arr[j++];
        }
    }
    for (i = lo; i <= hi; i++)
        arr[i] = temp[i];
}

int main()
{
    int i, n, m;

    scanf("%d", &n);
    m = 1 << n;
    for (i = 0; i < m; i++)
    {
        scanf("%d", &ara[i]);
        rev[m - i - 1] = ara[i];
    }
    prep();
    inversion_count(ara, ans, 0, m - 1);
    inversion_count(rev, res, 0, m - 1);

    int p, q;
    ll ret;
    scanf("%d", &q);
    for (int j = 0; j < q; j++)
    {
        scanf("%d", &p);
        ret = 0;
        for (i = 1; i <= p; i++)
            ret += res[i];
        for (i = p + 1; i <= n; i++)
            ret += ans[i];
        printf("%lld\n", ret);
        for (i = 1; i <= p; i++)
            swap(res[i], ans[i]);
    }

    return 0;
}
