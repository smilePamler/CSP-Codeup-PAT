#include <bits/stdc++.h>
typedef long long LL;

int main() {
    int T, i = 0;
    scanf("%d", &T);
    int flag[T] = { 0 };
    // 下面循环如果用 while(T--) 会导致T最终变为0，第二个for循环则会出问题
    for (i = 0; i < T; i++)
    {
        LL a = 0, b = 0, c = 0, sum = 0;
        scanf("%lld%lld%lld", &a, &b, &c);
        sum = a + b;
        flag[i] = (sum > c) ? 1 : 0;
    }
    for (i = 0; i < T; i++)
    {
        if (flag[i] == 1) printf("Case #%d: true\n", i+1);
        else printf("Case #%d: false\n", i+1);
    }
    return 0;
}