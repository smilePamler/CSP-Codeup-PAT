#include <bits/stdc++.h>

// int main() {
//     char sen[90];
//     gets(sen); // OJ系统会编译错误
//     int i, j, k, len;
//     len = strlen(sen);
//     k = len - 1;
//     for (i = len-1; i >= 0; i--)
//     {
//         if (sen[i] == ' ')
//         {
//             for (j = i+1; j <= k; j++)
//             {
//                 printf("%c", sen[j]);
//             }
//             k = i - 1;
//             printf(" ");
//         }
//         if (i == 0)
//         {
//             for (j = i; j <= k; j++)
//             {
//                 printf("%c", sen[j]);
//             }
//         }
//     }
//     return 0;
// }

int main() {
    char sen[90][90];
    int num = 0, i;
    while (~scanf("%s", sen[num])) // Ctrl+Z+Enter 结束输入
    {
        num++;
    }
    for (i = num-1; i >= 0; i--)
    {
        printf("%s", sen[i]);
        if (i > 0) printf(" ");
    }
    return 0;
}