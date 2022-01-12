#include <iostream>
using namespace std;

int n;
int i, j;

struct Trash
{
    int x;
    int y;
};
Trash trash[1000];

// 检查(X, Y)处是否存在垃圾
bool CheckXY(int X, int Y) {
    for(j = 0; j < n; j++)
    {
        if (trash[j].x == X && trash[j].y == Y)
            return true;
    }
    return false;
}

// 判断给定位置是否放置垃圾回收站
bool IsPlace(Trash t) {
    if (CheckXY(t.x - 1, t.y) && CheckXY(t.x + 1, t.y) && CheckXY(t.x, t.y - 1) && CheckXY(t.x, t.y + 1))
        return true;
    return false;
}

int main() {
    int score[5] = { 0 };
    cin >> n;
    for(i = 0; i < n; ++i) 
    {
        cin >> trash[i].x >> trash[i].y;
    }
    int cnt;
    for(i = 0; i < n; i++)
    {
        cnt = 0;
        if (IsPlace(trash[i]))
        {
            if (CheckXY(trash[i].x - 1, trash[i].y - 1))
            {
                cnt++;
            }
            if (CheckXY(trash[i].x - 1, trash[i].y + 1))
            {
                cnt++;
            }
            if (CheckXY(trash[i].x + 1, trash[i].y - 1))
            {
                cnt++;
            }
            if (CheckXY(trash[i].x + 1, trash[i].y + 1))
            {
                cnt++;
            }
            score[cnt]++; 
        }    
    }
    for (i = 0; i < 5; i++)
    {
        cout << score[i] << endl;
    }
    return 0;
}

/*
 *注意，这里变量 i 设置的是全局变量，如果所有函数的循环都使用变量 i
 *那么在函数调用过程中，i 的值将受所有函数的影响
 *所以主函数和其他函数的循环应该使用不同的递归变量
 */