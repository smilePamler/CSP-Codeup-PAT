#include <bits/stdc++.h>

int main() {
    int a, b, c;
    int x, y, z;
    int r1 = 0, r2 = 0, r3 = 0;
    scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &x, &y, &z);
    r3 = c + z;
    if (r3 >= 29)
    {
        r2 += r3 / 29;
        r3 %= 29;
    }
    r2 += (b + y);
    if (r2 >= 17)
    {
        r1 += r2 / 17;
        r2 %= 17;
    }
    r1 += (a + x);
    printf("%d.%d.%d", r1, r2, r3);
    return 0;
}