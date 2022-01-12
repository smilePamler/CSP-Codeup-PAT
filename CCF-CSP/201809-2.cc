/*寻找两个数组的重复数据长度，用标记数组*/
#include <iostream>
using namespace std;

struct Time
{
    int t1;
    int t2;
};
Time H[2000];
Time W[2000];


int main() {
    int n, i, j, max, talk = 0;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> H[i].t1 >> H[i].t2;
    for (i = 0; i < n; i++)
        cin >> W[i].t1 >> W[i].t2;
    max = H[n-1].t2 > W[n-1].t2 ? H[n-1].t2 : W[n-1].t2; // 求出最大的时刻
    int Flag[max] = { 0 }; // 设置长度为最大时刻的数组
    for (i = 0; i < n; i++)
    {
        for (j = H[i].t1; j < H[i].t2; j++) Flag[j]++; // 注意内层循环的 j 不能等于 t2 值，因为 t1、t2 代表的是时刻
        for (j = W[i].t1; j < W[i].t2; j++) Flag[j]++; // 所以[t1, t2]时间段实际上的时间只有 (t2 - t1)个单位 
    }
    for (i = 0; i < max; i++)
    {
        if (Flag[i] == 2) talk++;        
    }
    cout << talk << endl;
    return 0;
}