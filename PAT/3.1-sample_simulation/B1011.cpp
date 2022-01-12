#include <bits/stdc++.h>
typedef long long LL;

int main() {
    LL a, b, c;
    int T, i;
    scanf("%d", &T);
    int flag[T] = { 0 };
    for (i = 0; i < T; i++)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        flag[i] = (a+b) > c ? 1 : 0;
    }
    for (i = 0; i < T; i++)
    {
        if (flag[i] == 1) printf("Case #%d: true\n", i+1);
        else printf("Case #%d: false\n", i+1);
    }
    return 0;
}