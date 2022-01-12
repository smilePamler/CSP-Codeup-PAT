#include <iostream>
using namespace std;

int main() {
    int n, i, priceN;
    cin >> n;
    int price[n+1];
    for (i = 1; i <= n; i++)
    {
        cin >> price[i];
    }
    for (i = 1; i <= n; i++)
    {
        if (i == 1) priceN = (price[i] + price[i+1])/2;
        else if (i == n) priceN = (price[i] + price[i-1])/2;
        else priceN = (price[i-1] + price[i] + price[i+1])/3;
        cout << priceN << " ";
    }
    return 0;
}