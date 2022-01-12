/* ①scanf的%c是可以读入换行和空格的 */
/* ②getchar可以识别换行符和空格 */
#include <bits/stdc++.h>

int main() {
    //1-甲，2-乙
    //cnt数组记录胜利、平局、失败局数
    int N, i, cnt1[3] = { 0 }, cnt2[3] = { 0 };
    //winnum数组记录每种类型获胜次数，0：B，1：C，2：J
    int winnum1[3] = { 0 }, winnum2[3] = { 0 };
    char x, y;
    scanf("%d", &N);
    getchar(); // 读入输入N后的换行符
    for (i = 0; i < N; i++)
    {
        // scanf("%c %c", &x, &y); // 这种方法会读入空格和换行符
        scanf("%c", &x);
        getchar(); // 读入键盘空格
        scanf("%c", &y);
        getchar(); // 读入键盘换行
        if ((x=='C'&&y=='J')||(x=='B'&&y=='C')||(x=='J'&&y=='B'))
        {//甲胜
            cnt1[0] += 1;
            cnt2[2] += 1;
            switch (x)
            {
            case 'B':
                winnum1[0] += 1;
                break;
            case 'C':
                winnum1[1] += 1;
                break;
            case 'J':
                winnum1[2] += 1;
                break;
            }   
        }
        if (x==y)
        {//平局
            cnt1[1] += 1;
            cnt2[1] += 1;
        }
        if ((x=='J'&&y=='C')||(x=='C'&&y=='B')||(x=='B'&&y=='J'))
        {//乙胜
            cnt1[2] += 1;
            cnt2[0] += 1;
            switch (y)
            {
            case 'B':
                winnum2[0] += 1;
                break;
            case 'C':
                winnum2[1] += 1;
                break;
            case 'J':
                winnum2[2] += 1;
                break;
            } 
        }
    }
    printf("%d %d %d\n", cnt1[0], cnt1[1], cnt1[2]);
    printf("%d %d %d\n", cnt2[0], cnt2[1], cnt2[2]);
    int max1 = winnum1[0], sub1 = 0, max2 = winnum2[0], sub2 = 0;
    for (i = 1; i < 3; i++)
    {
        if (winnum1[i]>max1)
        {
            max1 = winnum1[i];
            sub1 = i;
        }
        if (winnum2[i]>max2)
        {
            max2 = winnum2[i];
            sub2 = i;
        }
    }
    switch (sub1)
    {
    case 0:
        x = 'B';
        break;
    case 1:
        x = 'C';
        break;
    case 2:
        x = 'J';
        break;
    }
    switch (sub2)
    {
    case 0:
        y = 'B';
        break;
    case 1:
        y = 'C';
        break;
    case 2:
        y = 'J';
        break;
    }
    printf("%c %c\n", x, y);
    return 0;
}