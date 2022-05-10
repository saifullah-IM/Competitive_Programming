/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int mx = 1000006;
char str[mx], ptr[mx];
int parent[mx];

int Find(int n)
{
    if (parent[n] == 0 || parent[n] == n)
        return parent[n] = n;
    else
        return parent[n] = Find(parent[n]);
}

void Union(int u, int v)
{
    parent[u] = parent[v] = max(Find(u), Find(v));
}

const int MOD1 = 1000000007;
const int MOD2 = 1111211111;
const int P1 = 31;
const int P2 = 37;

ll bigmod(ll a, ll b, ll c)
{
    ll res = 1;
    while (b > 0)
    {
        if (b % 2 == 1)
            res = (res * a) % c;
        a = (a * a) % c;
        b /= 2;
    }
    return res;
}

int ara[mx];
ll hash1[mx], hash2[mx], H1, H2;
ll POW1[mx], POW2[mx], inv1[mx], inv2[mx];

void prep()
{
    POW1[0] = POW2[0] = inv1[0] = inv2[0] = 1;
    for (int i = 1; i < mx; i++)
    {
        POW1[i] = (POW1[i - 1] * P1) % MOD1;
        POW2[i] = (POW2[i - 1] * P2) % MOD2;
        inv1[i] = bigmod(POW1[i], MOD1 - 2, MOD1);
        inv2[i] = bigmod(POW2[i], MOD2 - 2, MOD2);
    }
}

int main()
{
    int i, j, k, n, m, len;
    ll x, y, z, ans;

    prep();
    scanf("%d %d", &n, &m);
    scanf("%s", str);
    len = strlen(str);
    for (i = 0; i < n; i++)
        ptr[i] = '*';
    ptr[i] = '\0';

    for (i = 0; i < m; i++)
    {
        scanf("%d", &ara[i]);
        x = ara[i];
        k = Find(x);
        j = k - x;
        while (j < len)
        {
            ptr[x + j - 1] = str[j];
            Union(x + j, x + j + 1);
            k = Find(x + j);
            j = k - x;
        }
    }

    ans = 1;
    for (i = 0; i < n; i++)
    {
        if (ptr[i] == '*')
        {
            ans = (ans * 26) % MOD1;
            x = POW1[i + 1] * 27;
            hash1[i + 1] = (hash1[i] + x) % MOD1;
            x = POW2[i + 1] * 27;
            hash2[i + 1] = (hash2[i] + x) % MOD2;
            continue;
        }
        x = POW1[i + 1] * (ptr[i] - 'a' + 1);
        hash1[i + 1] = (hash1[i] + x) % MOD1;
        x = POW2[i + 1] * (ptr[i] - 'a' + 1);
        hash2[i + 1] = (hash2[i] + x) % MOD2;
    }

    H1 = H2 = 0;
    for (i = 0; i < len; i++)
    {
        x = POW1[i + 1] * (str[i] - 'a' + 1);
        H1 = (H1 + x) % MOD1;
        x = POW2[i + 1] * (str[i] - 'a' + 1);
        H2 = (H2 + x) % MOD2;
    }

    bool chk = false;
    for (i = 0; i < m; i++)
    {
        x = ara[i];
        y = (hash1[x + len - 1] - hash1[x - 1]) * inv1[x - 1];
        z = (hash2[x + len - 1] - hash2[x - 1]) * inv2[x - 1];
        y = (y % MOD1 + MOD1) % MOD1;
        z = (z % MOD2 + MOD2) % MOD2;
        if (y != H1 || z != H2)
        {
            chk = true;
            break;
        }
    }

    if (chk)
        cout << 0;
    else
        cout << ans << endl;

    return 0;
}
