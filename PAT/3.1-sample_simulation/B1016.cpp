#include <bits/stdc++.h>

int main() {
    long long a, b, pa = 0, pb = 0;
    int da, db;
    scanf("%lld%d%lld%d", &a, &da, &b, &db);
    while (a > 0)
    {
        if (a%10 == da) pa = pa*10 + da;
        a = a/10;
    }
    while (b > 0)
    {
        if (b%10 == db) pb = pb*10 + db;
        b = b/10;
    }
    printf("%lld\n", pa + pb);
    return 0;
}