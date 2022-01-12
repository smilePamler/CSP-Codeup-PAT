#include <bits/stdc++.h>

int main() {
    char a[11], b[11];
    int da, db;
    while (~scanf("%s%d%s%d", &a, &da, &b, &db))
    {
        int i, cnt1 = 0, cnt2 = 0;
        double Pa = 0, Pb = 0; // 由于pow()函数结果强转为int型会有精度损失，所以定义为double类型
        int len1 = strlen(a);
        int len2 = strlen(b);
        for (i = 0; i < len1; i++)
        {
            if (a[i]-'0' == da) cnt1++;  
        }
        for (i = 0; i < len2; i++)
        {
            if (b[i]-'0' == db) cnt2++;
        }
        while (cnt1 > 0)
        {
            Pa += da*pow(10.0, (cnt1-1)/1.0);
            cnt1--;
        }
        while (cnt2 > 0)
        {
            Pb += db*pow(10.0, (cnt2-1)/1.0);
            cnt2--;
        }
        printf("%.0f\n", Pa+Pb);
    }
    return 0;
}