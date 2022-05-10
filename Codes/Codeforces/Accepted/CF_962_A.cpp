#include <iostream>
using namespace std;
int main()
{
    long long n, sum = 0;
    long long sumhalf;
    cin >> n;
    int arr[200005];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum = sum + arr[i];
    }
    sumhalf = (sum + 1) / 2;

    sum = 0;
    for (int i = 0; i < n; i++)
    {

        sum = sum + arr[i];
        if (sum >= sumhalf)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
}