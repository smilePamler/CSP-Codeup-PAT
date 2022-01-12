#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int i, n, max, min;
    double mid;
    cin >> n;
    int array[n];
    for (i = 0; i < n; i++)
    {
        cin >> array[i];
    }
    max = array[0] >= array[n-1] ? array[0] : array[n-1];
    min = array[0] < array[n-1] ? array[0] : array[n-1];
    if(n % 2) {
        // mid = array[n/2];
        cout << max << " " << array[n/2] << " " << min;
    }
    else if((array[n/2-1] + array[n/2]) % 2) {
        mid = (array[n/2-1] + array[n/2]) / 2.0;
        printf("%d %.1f %d", max, mid, min); // 此时要用printf格式化输出(避免当数据过大时系统采用科学计数法)
    }
    else {
        // mid = (array[n/2-1] + array[n/2]) / 2;
        cout << max << " " << (array[n/2-1] + array[n/2]) / 2 << " " << min;
    }
    return 0;
}