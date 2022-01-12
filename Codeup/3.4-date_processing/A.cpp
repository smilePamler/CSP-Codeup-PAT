#include <bits/stdc++.h>

int days[13][2] = { {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31},
    {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}
};

int isLeap(int year) {
    if ((year%4 == 0 && year%100 != 0) || year%400 == 0) return 1;
    else return 0;
}

int main() {
    int date1, y1, m1, d1;
    int date2, y2, m2, d2;
    while(~scanf("%d %d", &date1, &date2)) {
        if (date1 > date2) // 将早的日期放前面
        {
            int temp = date1;
            date1 = date2;
            date2 = temp;
        }
        y1 = date1/10000, m1 = date1/100%100, d1 = date1%100;
        y2 = date2/10000, m2 = date2/100%100, d2 = date2%100;
        int ans = 1; // 天数差值初始化为1（根据相邻日期差值为2）
        // 跳出循环条件为（y1==y2 && m1==m2 && d1==d2）
        while (y1<y2 || m1<m2 || d1<d2)
        {
            d1++;
            if (d1>days[m1][isLeap(y1)])
            {
                m1++;
                d1 = 1;
            }
            if (m1>12)
            {
                y1++;
                m1 = 1;
            }
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}