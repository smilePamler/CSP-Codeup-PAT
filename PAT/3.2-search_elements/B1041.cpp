#include <bits/stdc++.h>

struct Info
{
    // char id[16]; // 开字符数组时大小必须比实际存储字符串长度至少大1
    char id[17]; // 因为必须在字符串末尾加'\0'以表示字符串的结尾
    // scanf()和gets()是自动加'\0'，getchar()必须人为添加
    int try_num, test_num;
} Info[1000];

int main() {
    int n, m, i, j;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%s%d%d", &Info[i].id, &Info[i].try_num, &Info[i].test_num);
    }
    scanf("%d", &m);
    int check_num[m];
    for (i = 0; i < m; i++)
    {
        scanf("%d", &check_num[i]);
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (check_num[i]==Info[j].try_num)
            {
                printf("%s %d\n", Info[j].id, Info[j].test_num);
                break;
            }           
        }
    }
    return 0;
}