#include <iostream>
using namespace std;
// 顺序：红-绿-黄
int main() {
    int r, y, g, n, k, t, i, extra;
    long long totalTime = 0; // 注意 int 只有60分
    cin >> r >> y >> g;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> k >> t;
        if (k == 0) totalTime += t;
        else if (k == 1) { // 红灯
            if (t >= totalTime) totalTime += (t - totalTime);
            else {
                extra = (totalTime - t)%(r + y + g);
                if ( extra < g) continue;
                else totalTime += (g + y + r - extra);
            }
        }
        else if (k == 2) { // 黄灯
            if (t >= totalTime) totalTime += (t - totalTime + r);
            else {
                extra = (totalTime - t)%(r + y + g);
                if (extra < r) totalTime += (r - extra);
                else if (extra < (r + g)) continue;
                else totalTime += (2*r + y + g - extra);
            }
        }
        else { // 绿灯
            if (t >= totalTime) continue;
            else {
                extra = (totalTime - t)%(r + y + g);
                if (extra < (y + r)) totalTime += (y + r - extra);
                else continue;
            }
        }
    }
    cout << totalTime << endl;
    return 0;
}