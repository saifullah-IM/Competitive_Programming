/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

const int root = 0;
const int mx = 1e5 + 5;
struct trie
{
    int node[mx][27], nnode;
    bool isWord[mx];

    trie()
    {
        nnode = 0;
        for (int i = 0; i < 26; i++)
            node[root][i] = -1;
    }
    void insert(char *str)
    {
        int len, now, i, j;
        now = root;
        len = strlen(str);
        for (i = 0; i < len; i++)
        {
            if (node[now][str[i] - 'a'] == -1)
            {
                node[now][str[i] - 'a'] = ++nnode;
                for (j = 0; j < 26; j++)
                    node[nnode][j] = -1;
            }
            now = node[now][str[i] - 'a'];
        }
        isWord[now] = true;
    }
};
bool win[mx], lose[mx];
char str[mx];
trie T;
bool ifWin(int v)
{
    bool res = false;
    for (int i = 0; i < 26; i++)
        if (T.node[v][i] != -1)
        {
            int u = T.node[v][i];
            res = (res | !ifWin(u));
        }
    return res;
}
bool ifLose(int v)
{
    bool res = false, chk = true;
    for (int i = 0; i < 26; i++)
        if (T.node[v][i] != -1)
        {
            int u = T.node[v][i];
            res = (res | !ifLose(u));
            chk = false;
        }
    return (res | chk);
}
int main()
{
    int i, n, k;

    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++)
    {
        scanf("%s", str);
        T.insert(str);
    }
    bool chk1 = ifWin(0);
    bool chk2 = ifLose(0);
    if (!chk1)
        printf("Second\n");
    else if (chk2)
        printf("First\n");
    else if (k % 2)
        printf("First\n");
    else
        printf("Second\n");

    return 0;
}
