// 注意：a, b, c的范围应该是[−2^63, 2^63-1]
// 而long long 的取值范围[−2^63, 2^63-1]
// unsigned long long, 范围为[0, 2^64-1]

#include <bits/stdc++.h>

int main() {
    long long a, b, c, sum;
    int t, i;
    scanf("%d", &t);
    bool flag;
    for (i = 0; i < t; i++)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        sum = a + b;
        if (a>0 && b>0 && sum<0) flag = true;
        else if(a<0 && b<0 && sum>=0) flag = false;
        else if(sum>c) flag = true;
        else flag = false;
        if (flag) printf("Case #%d: true\n", i+1);
        else printf("Case #%d: false\n", i+1);        
    }
    return 0;
}