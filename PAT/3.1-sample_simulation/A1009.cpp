#include <bits/stdc++.h>

const int M = 2001; // 幂的范围是[0, 1000]，乘积最大可为2000次方
struct Ploy
{
    int exp;
    double coef;
} Ploy[1001];

int main() {
    int i, j, n, m;
    double coe[M] = { 0.0 };
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d%lf", &Ploy[i].exp, &Ploy[i].coef);
    }
    scanf("%d", &m);
    for (i = 0; i < m; i++)
    {
        int x;
        double y;
        scanf("%d%lf", &x, &y);
        for (j = 0; j < n; j++)
        {// 每输入一个幂次和系数就和前一个多项式的每一项相乘
            coe[Ploy[j].exp+x] += (y*Ploy[j].coef);    
        }
    }
    int cnt = 0;
    for (i = 0; i < M; i++)
    {
        if (coe[i] != 0.0) cnt++;        
    }
    printf("%d", cnt);
    for (i = M-1; i >= 0; i--)
    {
        if (coe[i] != 0) printf(" %d %.1f", i, coe[i]);
    }
    return 0;
}