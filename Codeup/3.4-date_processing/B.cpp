// 注意：此题的基准时间必须为2018年1月6日
// 注意：此题的基准时间前和基准时间后的星期推测方法不一样
#include <bits/stdc++.h>
using namespace std;

int days[13][2] = { {0, 0}, {31, 31}, {28, 29}, {31, 31}, {30, 30}, {31, 31},
    {30, 30}, {31, 31}, {31, 31}, {30, 30}, {31, 31}, {30, 30}, {31, 31}
};
char mon[7][15] = { "Saturday","Sunday", "Monday",
    "Tuesday", "Wednesday", "Thursday", "Friday"
};

// 这一天为星期六
const int date1 = 20180106;

int whichMon(string s) {
    if (s == "January") return 1;
    if (s == "February") return 2;
    if (s == "March") return 3;
    if (s == "April") return 4;
    if (s == "May") return 5;
    if (s == "June") return 6;
    if (s == "July") return 7;
    if (s == "August") return 8;
    if (s == "September") return 9;
    if (s == "October") return 10;
    if (s == "November") return 11;
    if (s == "December") return 12;
    return 0;
}

int isLeap(int year) {
    if ((year%4 == 0 && year%100 != 0) || year%400 == 0) return 1;
    else return 0;
}

int main() {
    int d, y;
    char mth[15];
    while(~scanf("%d %s %d", &d, mth, &y)) {
        // 这个信息不能设为全局变量，因为可能会被改变，改变后对下一次输入会有影响
        int year = 2018, month = 1, day = 6;
        bool flag = true; // 若过输入日期在给定日期之前，则为true
        int m = whichMon(mth);
        int date2 = d + m*100 + y*10000; // date2是输入的日期
        if (date2 > date1)
        {
            int temp = y;
            y = year;
            year = temp;
            temp = m;
            m = month;
            month = temp;
            temp = d;
            d = day;
            day = temp;
            flag = false;
        }
        int ans = 0; // 天数差值初始化为0
        // 跳出循环条件为（y1==y2 && m1==m2 && d1==d2）
        while (y<year || m<month || d<day)
        {
            d++;
            if (d>days[m][isLeap(y)])
            {
                m++;
                d = 1;
            }
            if (m>12)
            {
                y++;
                m = 1;
            }
            ans++;
        }
        int res = ans % 7;
        if (flag) printf("%s\n", mon[(7-res)%7]);
        else printf("%s\n", mon[res]);   
    }
    return 0;    
}