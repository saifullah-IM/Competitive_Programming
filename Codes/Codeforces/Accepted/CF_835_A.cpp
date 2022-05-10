/*  Bismillahir Rahmanir Rahim  */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int i, n, s, v1, v2, t1, t2, a1, a2;

    scanf("%d %d %d %d %d", &s, &v1, &v2, &t1, &t2);
    a1 = s * v1 + 2 * t1;
    a2 = s * v2 + 2 * t2;
    if (a1 == a2)
        cout << "Friendship";
    else if (a1 < a2)
        cout << "First";
    else
        cout << "Second";

    return 0;
}
