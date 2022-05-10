/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;
const int mx = 1e5 + 5;
const int block = 320;
int ara[mx];
PII dest[mx];
bool done[mx];
int main()
{
    int i, n, q;
    scanf("%d %d", &n, &q);
    for (i = 0; i < n; i++)
        scanf("%d", &ara[i]);
    for (i = n - 1; i >= 0; i--)
    {
        int pos = i / block;
        int idx = i;
        int jump = 0;
        while (true)
        {
            if (idx / block > pos || idx >= n)
            {
                dest[i] = PII(idx, jump);
                done[i] = true;
                break;
            }
            if (done[idx])
            {
                dest[i] = PII(dest[idx].first, jump + dest[idx].second);
                done[i] = true;
                break;
            }
            idx += ara[idx];
            jump++;
        }
    }
    while (q--)
    {
        int k, a, b;
        scanf("%d", &k);
        if (k == 0)
        {
            scanf("%d %d", &a, &b);
            a--;
            ara[a] = b;
            int start = (a / block) * block;
            int out = min(start + block, n);
            for (int j = a; j >= start; j--)
                done[j] = false;
            for (int j = a; j >= start; j--)
            {
                int idx = j;
                int jump = 0;
                while (true)
                {
                    if (idx >= out)
                    {
                        dest[j] = PII(idx, jump);
                        done[j] = true;
                        break;
                    }
                    if (done[idx])
                    {
                        dest[j] = PII(dest[idx].first, jump + dest[idx].second);
                        done[j] = true;
                        break;
                    }
                    idx += ara[idx];
                    jump++;
                }
            }
        }
        else
        {
            scanf("%d", &a);
            a--;
            int jump = 0, idx = a, last;
            while (idx < n)
            {
                jump += dest[idx].second;
                last = idx;
                idx = dest[idx].first;
            }
            while (true)
            {
                if (last + ara[last] >= n)
                    break;
                last += ara[last];
            }
            printf("%d %d\n", last + 1, jump);
        }
    }

    return 0;
}
