#include <bits/stdc++.h>
using namespace std;

const int mx = 1e5 + 5;
typedef pair<int, int> PII;
PII ara[mx];

vector<int> ice;
int main()
{
    freopen("icecream.in", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> ara[i].first;
        for (int i = 0; i < n; i++)
            cin >> ara[i].second;

        sort(ara, ara + n);
        int calory = ara[k - 1].first;
        for (int i = 0; i < n; i++)
        {
            if (ara[i].first <= calory)
                ice.push_back(ara[i].second);
            else
                break;
        }
        sort(ice.begin(), ice.end());
        long long happy = 0;
        while (k--)
        {
            happy += ice.back();
            ice.pop_back();
        }
        cout << calory << ' ' << happy << endl;
        ice.clear();
    }

    return 0;
}