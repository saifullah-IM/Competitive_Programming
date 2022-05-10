#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int win[105];
int lose[105];

int main()
{
    int test;
    cin >> test;
    while(test--) {
        int n;
        cin >> n;
        int half = (n - 1) / 2;

        memset(win, 0, sizeof(win));
        memset(lose, 0, sizeof(lose));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((n % 2 == 0 && i % 2 == 0) && j == i + 1) printf("0 ");
                else if (win[i] < half && lose[j] < half) {
                    printf("1 ");
                    win[i] += 1;
                    lose[j] += 1;
                }
                else if (lose[i] < half && win[j] < half) {
                    printf("-1 ");
                    lose[i] += 1;
                    win[j] += 1;
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}