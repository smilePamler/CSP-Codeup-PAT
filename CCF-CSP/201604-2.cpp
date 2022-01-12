#include <iostream>

using namespace std;

int mat[15][10], res[15][10];
int block[4][4];
int start;
int u = 10, d = -1;
bool bypass = true;

int main()
{
    for (int i = 0; i < 15; i++) {// 输入初始方格图
        for (int j = 0; j < 10; j++) {
            cin >> mat[i][j];
            res[i][j] = mat[i][j];
        }
    }
    for (int i = 0; i < 4; i++) { // 输入方块
        for (int j = 0; j < 4; j++) {
            cin >> block[i][j];
            if (block[i][j] != 0) bypass = false; // 全0行，跳过
        }
        if (!bypass) { // 记录块的上下边界
            if (u > i) u = i;
            if (d < i) d = i;
            bypass = true;
        }
    }

    cin >> start;
    int up = 0;
    bool flag = true; // 是否可以相加的标志
    while (flag && up <= (14 - (d - u))) { // 功能：找方块到达的最终行位置
        for (int i = up, k1 = u; i <= up+d-u && k1 <= d; i++, k1++) {
            for (int j = 0, k2 = 0; k2 < 4; j++, k2++) {
                if (mat[i][start+j-1] + block[k1][k2] == 2) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) up++;
        else break;
    }
    for (int i = up-1, k1 = u; i <= up+d-u-1 && k1 <= d; i++, k1++) { // 最终位置为 up-1
        for (int j = 0, k2 = 0; k2 < 4; j++, k2++)
            res[i][start+j-1] += block[k1][k2];
    }

    for (int i = 0; i < 15; i++) {
        for (int j = 0; j < 10; j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
