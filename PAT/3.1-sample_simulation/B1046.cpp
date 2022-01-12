#include <bits/stdc++.h>

int main() {
    int N, cnt1 = 0, cnt2 = 0;
    int a, b, x, y;
    scanf("%d", &N);
    while (N--)
    {
        scanf("%d%d%d%d", &a, &b, &x, &y);
        if (b==(a+x)&&y!=(a+x)) cnt2++; // 甲胜
        if (y==(a+x)&&b!=(a+x)) cnt1++; // 乙胜
    }
    printf("%d %d\n", cnt1, cnt2);
    return 0;
}