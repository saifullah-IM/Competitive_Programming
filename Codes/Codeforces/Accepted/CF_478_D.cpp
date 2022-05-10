/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم*/

#include <bits/stdc++.h>
#define PII pair<int,int>
#define MOD 1000000007
using namespace std;

const int mx=200005;
PII DP[2][mx];

int main ()
{
    int h,r,g,R,G,H,k;
    PII A,B,ans;

    scanf ("%d %d",&R,&G);
    H=(sqrt(1+8*(R+G))-1)/2;

    A.first=H, A.second=1;
    r=(H*(H+1))/2-G;
    k=(H+1)%2;
    while (r<=R && r>=0) {
        DP[k][r]=A;
        r++;
    }

    for (h=H;h>0;h--) {
        k=(h+1)%2;
        for (r=R;r>=0;r--) {
            g=(h*(h+1))/2-r;
            if (g<=G) A=DP[k][r];
            else A.first=A.second=0;
            if (r+h<=R) B=DP[k][r+h];
            else B.first=B.second=0;

            if (A.first==0 && B.first==0) ans.first=h-1,ans.second=1;
            else if (A.first>B.first) ans=A;
            else if (A.first<B.first) ans=B;
            else {
                ans.first=A.first;
                ans.second=(A.second+B.second)%MOD;
            }///cout<<h<<' '<<r<<' '<<ans.first<<' '<<ans.second<<endl;
            DP[h%2][r]=ans;
        }
    }
    cout<<DP[1][0].second<<endl;

    return 0;
}
