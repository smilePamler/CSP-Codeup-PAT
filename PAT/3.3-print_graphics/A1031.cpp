// 解题重点：分析出n1、n2、n3的计算公式
#include <bits/stdc++.h>

int main() {
    int n, i, j;
    char str[100], fig[40][40];
    gets(str);
    n = strlen(str);
    int n1 = (n+2)/3, n3 = n1, n2 = n+2-n1-n3;
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
            fig[i][j] = ' ';    // 数组全部初始化为空格‘ ’    
    }
    int pos = 0;
    for (i = 0; i < n1; i++)
    {
        fig[i][0] = str[pos++];
    }
    for (i = 1; i < n2; i++)
    {
        fig[n1-1][i] = str[pos++];
    }
    for (i = n3-2; i >= 0; i--)
    {
        fig[i][n2-1] = str[pos++];
    }
    for (i = 0; i < n1; i++)
    {
        for (j = 0; j < n2; j++)
            printf("%c", fig[i][j]);
        printf("\n");        
    }
    return 0;
}