#include <iostream>
using namespace std;

int main() {
    int N, cnt1 = 0, cnt2 = 0, max;
    int num_3, num_5, num_re;
    cin >> N;
    N /= 10;
    num_3 = N / 3;
    num_re = N % 3;
    cnt1 = num_3 * 3 + num_3 + num_re;
    num_5 = N / 5;
    num_re = N % 5;
    if (num_re >= 3)
    {
        num_re = num_re % 3;
        cnt2 = num_5 * 5 + 2 * num_5 + 4 + num_re;
    }
    else cnt2 = num_5 * 5 + 2 * num_5 + num_re;
    max = cnt1 > cnt2 ? cnt1 : cnt2;
    cout << max << endl;
    return 0;
}