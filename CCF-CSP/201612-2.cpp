#include <iostream>
#include <climits>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); // 关闭与C兼容开关
    cin.tie(0); // 解除cin 和 cout绑定
    double T, res;
    cin >> T;
    array<double, 9> s{0, 3500, 5000, 8000, 12500, 38500, 58500, 83500, INT_MAX}, // 税前各节点工资
                rate{0.0, 0.0, 0.03, 0.1, 0.2, 0.25, 0.3, 0.35, 0.45}, // 税率
                t{}; // 各节点工资的税后
    for (int i = 1; i < 9; i++) {
        t[i] = t[i-1] + (s[i] - s[i-1]) * (1 - rate[i]);
    }
    for (int i = 1; i < 9; i++) {
        if (t[i] > T) {
            res = (T - t[i-1]) / (1 - rate[i]) + s[i-1];
            break;
        }
    }
    cout << res << endl;
    
    return 0;
}
