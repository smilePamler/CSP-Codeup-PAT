/* 前缀计算 */
#include <iostream>

using namespace std;

int m[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int prefix[13];

int main()
{
    int y, d;
    cin >> y >> d;
    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) m[2] = 29;
    for (int i = 1; i <= 12; i++) {
        prefix[i] = prefix[i-1] + m[i];
        if (d > prefix[i]) continue;
        else {
            d = d - prefix[i-1];
            cout << i << endl;
            cout << d << endl;
            break;
        }
    }
    return 0;
}
