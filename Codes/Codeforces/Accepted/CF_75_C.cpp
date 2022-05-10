/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, a, b, l, h, root, m;
    vector<int> divs1, divs2, cmndivs;
    vector<int>::iterator it;

    scanf("%d %d", &a, &b);
    root = round(sqrt(a * 1.0));
    for (i = 1; i <= root; i++)
        if (a % i == 0)
        {
            divs1.push_back(i);
            divs1.push_back(a / i);
        }
    if (root * root == a)
        divs1.pop_back();
    root = round(sqrt(b * 1.0));
    for (i = 1; i <= root; i++)
        if (b % i == 0)
        {
            divs2.push_back(i);
            divs2.push_back(b / i);
        }
    if (root * root == b)
        divs2.pop_back();
    sort(divs1.begin(), divs1.end());
    m = divs2.size();
    for (i = 0; i < m; i++)
        if (binary_search(divs1.begin(), divs1.end(), divs2[i]))
            cmndivs.push_back(divs2[i]);
    sort(cmndivs.begin(), cmndivs.end());

    scanf("%d", &n);
    while (n--)
    {
        scanf("%d %d", &l, &h);
        it = upper_bound(cmndivs.begin(), cmndivs.end(), h);
        it--;
        if (*it >= l)
            printf("%d\n", *it);
        else
            printf("-1\n");
    }

    return 0;
}
