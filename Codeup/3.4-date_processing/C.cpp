// 注意：1 <= y <= 3000, 即 y 可能不满4位
#include <bits/stdc++.h>

int days[13][2] = { {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31},
    {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}
};

int isLeap(int year) {
    if ((year%4 == 0 && year%100 != 0) || year%400 == 0) return 1;
    else return 0;
}

int main() {
    int y, n;
    while (~scanf("%d %d", &y, &n))
    {
        int i, j;
        int sum = 0, k = isLeap(y);
        bool flag = false;
        for (i = 1; i <= 12; i++)
        {
            for (j = 1; j <= days[i][k]; j++)
            {
                sum++;
                if (sum == n) {
                    printf("%04d-%02d-%02d\n", y, i, j);
                    flag = true;
                    break;
                }
            }
            if(flag == true) break;
        }
    }
    return 0;
}