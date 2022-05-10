/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int maxn = 7e6;
const int mx = 3e5 + 5;
struct trie
{
    int node[maxn][2];
    bool iscomplete[maxn];
    int nnode;

    void initialize()
    {
        nnode = 0;
        node[0][0] = node[0][1] = -1;
        iscomplete[0] = false;
    }
    bool insert(char *str, int pos)
    { ///cout<<pos<<"      "<<str<<endl;
        if (*str == '\0')
            return iscomplete[pos] = true;
        int k = (*str) - '0', next;
        if (node[pos][k] != -1)
            next = node[pos][k];
        else
        {
            next = node[pos][k] = ++nnode;
            node[nnode][0] = node[nnode][1] = -1;
            iscomplete[nnode] = false;
        }
        insert(str + 1, next);
        return iscomplete[pos] = (iscomplete[node[pos][0]] & iscomplete[node[pos][1]]);
    }
    string mex(int pos, char *str)
    { ///if (pos==17) cout<<str<<' '<<node[pos][0]<<' '<<node[pos][1]<<' '<<iscomplete[node[pos][0]]<<' '<<iscomplete[node[pos][1]]<<endl;
        if (pos == -1)
            return "";
        ///if (node[pos][0]!=-1 && iscomplete[node[pos][0]] && node[pos][1]==-1) {cout<<pos<<'0'<<endl;return "1";}
        ///if (node[pos][1]!=-1 && iscomplete[node[pos][1]] && node[pos][0]==-1) {cout<<pos<<'1'<<endl;return "0";}
        int k = (*str) - '0';
        if (!iscomplete[node[pos][k]])
            return '0' + mex(node[pos][k], str + 1);
        else
            return '1' + mex(node[pos][k ^ 1], str + 1);
    }
} T;
int main()
{
    int i, n, q, xr = 0;
    char str[23];
    scanf("%d %d", &n, &q);
    T.initialize();
    for (i = 0; i < 19; i++)
        str[i] = '0';
    str[19] = '\0';
    ///T.insert(str,0);
    for (i = 0; i < n; i++)
    {
        int x, j = 0;
        scanf("%d", &x);
        while (j < 19)
        {
            str[j++] = '0' + (x % 2);
            x /= 2;
        }
        for (int k = 0; k < 9; k++)
            swap(str[k], str[18 - k]);
        str[19] = '\0';
        T.insert(str, 0);
    } ///cout<<T.nnode<<endl;
    while (q--)
    {
        int x, j = 0;
        scanf("%d", &x);
        xr ^= x;
        int t = xr;
        while (j < 19)
        {
            str[j++] = '0' + (t % 2);
            t /= 2;
        }
        for (int k = 0; k < 9; k++)
            swap(str[k], str[18 - k]);
        str[19] = '\0';
        string temp = T.mex(0, str);
        for (i = temp.size(); i < 19; i++)
            temp += '0';
        int ans = 0;
        for (i = 0; i < 19; i++)
            ans = ((ans << 1) | (temp[i] - '0'));
        printf("%d\n", ans);
    }

    return 0;
}
