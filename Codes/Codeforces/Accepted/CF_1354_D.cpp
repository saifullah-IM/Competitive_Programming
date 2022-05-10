#include <bits/stdc++.h>
using namespace std;

const int mx = 1e6 + 6;
int fenwickTree[mx];
int N;
int LogN;

void update(int idx, int val)
{
    while (idx <= N)
    {
        fenwickTree[idx] += val;
        idx += (idx & -idx);
    }
}

int find_order_statistics(int val)
{
    int sum = 0, pos = 0;
    for (int i = LogN; i >= 0; i--)
    {
        int next_pos = pos + (1 << i);
        if (next_pos <= N && sum + fenwickTree[next_pos] < val)
        {
            sum += fenwickTree[next_pos];
            pos = next_pos;
        }
    }

    return pos + 1;
}

int main()
{
    int Q;
    scanf("%d %d", &N, &Q);

    while ((1 << LogN) < N)
        LogN++;

    for (int i = 0; i < N; i++)
    {
        int x;
        scanf("%d", &x);
        update(x, 1);
    }

    //for (int i=0;i<10;i++) cout<<i<<"--"<<fenwickTree[i]<<endl;

    for (int i = 0; i < Q; i++)
    {
        int k;
        scanf("%d", &k);
        if (k > 0)
            update(k, 1);
        else
        {
            k = abs(k);
            int pos = find_order_statistics(k);
            update(pos, -1);
            /*cout<<"position  "<<pos<<endl;
            cout<<endl;
            for (int i=0;i<10;i++) cout<<i<<"--"<<fenwickTree[i]<<endl;
            cout<<endl;*/
        }
    }

    //for (int i=0;i<10;i++) cout<<i<<"--"<<fenwickTree[i]<<endl;
    int ans = find_order_statistics(1);
    if (ans > N)
        printf("%d", 0);
    else
        printf("%d", ans);

    return 0;
}