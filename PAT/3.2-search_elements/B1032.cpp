// 注意：最多n个学校，0位置不存分数，故数组最大开n+1
#include <bits/stdc++.h>

int main() {
    int n, i, x, y;
    scanf("%d", &n);
    int score[n+1] = { 0 };
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        score[x] += y;
    }
    int sub = 0, max = score[0];
    for (i = 1; i <= n; i++)
    {
        if (score[i] > max)
        {
            max = score[i];
            sub = i;
        }    
    }
    printf("%d %d\n", sub, max);
    return 0;
}