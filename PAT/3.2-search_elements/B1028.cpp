// 注意：若所有人的日期都不合理，则输出0
// 注意：每次根据比较结果，需要分别更新最大（小）的年份、月份和天数，不能只更新其中一个
#include <bits/stdc++.h>

struct People
{
    char name[6];
    char birthday[11];
};
const int year = 2014;
const int mon = 9;
const int day = 6;

int main() {
    int n, i, cnt = 0;
    scanf("%d", &n);
    People p[n];
    int sub_max = 0, max_y = 2014, max_m = 12, max_d = 31;
    int sub_min = 0, min_y = 1814, min_m = 1, min_d = 1;
    for (i = 0; i < n; i++)
    {
        bool flag = false;
        scanf("%s%s", &p[i].name, &p[i].birthday);
        int y = (p[i].birthday[0]-'0')*1000 + (p[i].birthday[1]-'0')*100
         + (p[i].birthday[2]-'0')*10 + (p[i].birthday[3]-'0');
        int m = (p[i].birthday[5]-'0')*10 + (p[i].birthday[6]-'0');
        int d = (p[i].birthday[8]-'0')*10 + (p[i].birthday[9]-'0');
        // 求有效身份个数
        if ((year-y)==200)
        {
            if (m>mon)
            {
                cnt++;
                flag = true;
            }
            else if (m==mon && d>=day)
            {
                cnt++;
                flag = true;
            }
        }
        else if ((year-y)<200 && (year-y)>0)
        {
            cnt++;
            flag = true;
        }
        else if ((year-y)==0)
        {
            if (m<mon)
            {
                cnt++;
                flag = true;
            }
            else if (m==mon && d<=day)
            {
                cnt++;
                flag = true;
            } 
        }
        if (flag)
        {
            // 求最年长
            if (y<max_y)
            {
                max_y = y;
                max_m = m;
                max_d = d;
                sub_max = i;
            }
            else if (y==max_y)
            {
                if (m<max_m)
                {
                    max_m = m;
                    max_d = d;
                    sub_max = i;
                }
                else if (m==max_m && d<max_d)
                {
                    max_d = d;
                    sub_max = i;
                }    
            }
            // 求最年轻
            if (y>min_y)
            {
                min_y = y;
                min_m = m;
                min_d = d;
                sub_min = i;
            }
            else if (y==min_y)
            {
                if (m>min_m)
                {
                    min_m = m;
                    min_d = d;
                    sub_min = i;
                }
                else if (m==min_m && d>min_d)
                {
                    min_d = d;
                    sub_min = i;
                }    
            }
        }    
    }
    if (cnt > 0) printf("%d %s %s\n", cnt, p[sub_max].name, p[sub_min].name);
    if (cnt == 0) printf("%d\n", cnt);
    return 0;
}