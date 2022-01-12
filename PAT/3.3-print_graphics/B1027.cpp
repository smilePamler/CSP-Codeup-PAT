// ①等差数列求和：Sn = n(a1+an)/2
// ②必须求出三角形底边字符个数
// ③每行只需要打印完非空字符即可换行
// ④上下三角形分开打印
#include <bits/stdc++.h>

int main() {
    int n, i, j, m = 0, p = 0; // m存三角形包含的符号数，p存行数
    char c;
    scanf("%d %c", &n, &c);
    while ((2*m-1) <= n)
    {
        p++;
        m += (2*p - 1);
    }
    int bottom = 2*(p-1)-1; // 底边符号数
    int used = (bottom+1)*(bottom+1)/2 - 1;
    for (i = bottom; i >= 1; i -= 2)
    {// 打印倒三角
        for (j = 0; j < (bottom-i)/2; j++)
            printf(" ");
        for (j = 0; j < i; j++)
            printf("%c", c);
        printf("\n");
    }
    for (i = 3; i <= bottom; i += 2)
    {// 打印正三角
        for (j = 0; j < (bottom-i)/2; j++)
            printf(" ");
        for (j = 0; j < i; j++)
            printf("%c", c);
        printf("\n");
    }
    // printf("%d %d %d %d\n", p, m, bottom, used);
    printf("%d\n", n-used);
    return 0;
}