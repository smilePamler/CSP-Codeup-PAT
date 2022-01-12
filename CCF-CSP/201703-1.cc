#include <iostream>
using namespace std;

int main() {
    int n, k, i, sum = 0, cnt = 0;
    cin >> n >> k;
    int weight[n+1] = { 0 };
    for (i = 1; i < n+1; i++)
    {
        cin >> weight[i];
    }
    for (i = 1; i < n+1; i++)
    {
        sum += weight[i];
        if (sum >= k)
        {
            cnt++;
            sum = 0;
        }
        else if (i == n)
        {
            cnt++;
        }
        else continue;
    }
    cout << cnt;
    return 0;
}